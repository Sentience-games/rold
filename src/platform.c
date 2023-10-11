#define NOUNICODE
#define STRICT
#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX            1

#include <windows.h>
#include <timeapi.h>

#undef STRICT
#undef WIN32_LEAN_AND_MEAN
#undef NOMINMAX
#undef far
#undef near

#include "common.h"

#define ROLD_WINDOW_CLASS_NAME "ROLD_WINDOW_CLASS_NAME"

bool Running = false;
umm PageSize;

void
Arena_CommitMoreMemory(Arena__Internal* arena)
{
	umm amount_to_commit = PageSize*arena->commit_pace;
	ASSERT(arena->committed + amount_to_commit <= arena->reserved);

	void* commit_result = VirtualAlloc((u8*)(arena+1) + arena->committed, amount_to_commit, MEM_COMMIT, PAGE_READWRITE);
	ASSERT(commit_result != 0); // TODO
}

Arena*
Arena_Init(umm reserve_size, u8 commit_pace)
{
	ASSERT(PageSize*commit_pace <= reserve_size);

	umm amount_to_commit = PageSize*commit_pace;

	Arena__Internal* arena = VirtualAlloc(0, reserve_size, MEM_RESERVE, PAGE_READWRITE);
	ASSERT(arena != 0); // TODO

	void* commit_result = VirtualAlloc(arena, amount_to_commit, MEM_COMMIT, PAGE_READWRITE);
	ASSERT(commit_result != 0); // TODO

	*arena = (Arena__Internal){
		.commit_more_memory = Arena_CommitMoreMemory,
		.cursor             = 0,
		.committed          = amount_to_commit - sizeof(Arena__Internal),
		.reserved           = reserve_size - sizeof(Arena__Internal),
		.commit_pace        = commit_pace,
	};

	return (Arena*)arena;
}

typedef struct Game_Code
{
	HMODULE code;
	Tick_Func* tick_func;
} Game_Code;

bool
ReloadGameCodeIfNecessary(Game_Code* game_code)
{
	return true;
}

LRESULT
Wndproc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (msg == WM_CLOSE || msg == WM_QUIT || msg == WM_DESTROY)
	{
		Running = false;
		return 0;
	}
	return DefWindowProcA(window, msg, wparam, lparam);
}

int APIENTRY 
WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int show_cmd)
{
	Arena* platform_arena   = 0;
	Arena* persistent_arena = 0;
	Arena* frame_arena      = 0;
	{ /// Intialize Memory Arenas
		struct { Arena** arena_handle; umm reserve_size; u8 commit_pace; } arena_settings[] = {
			[0] = {
				.arena_handle = &platform_arena,
				.reserve_size = GB(4),
				.commit_pace  = 1,
			},
			[1] = {
				.arena_handle = &persistent_arena,
				.reserve_size = GB(4),
				.commit_pace  = 1,
			},
			[2] = {
				.arena_handle = &frame_arena,
				.reserve_size = GB(4),
				.commit_pace  = 1,
			},
		};

		for (uint i = 0; i < STATIC_ARRAY_SIZE(arena_settings); ++i)
		{
			*arena_settings[i].arena_handle = Arena_Init(arena_settings[i].reserve_size, arena_settings[i].commit_pace);
		}
	}

	{ /// Set Current Working Directory
		umm exe_path_capacity_cutoff = GB(1);
		umm exe_path_capacity        = PageSize;
		umm exe_path_size            = 0;
		LPSTR exe_path = Arena_Push(platform_arena, exe_path_capacity, ALIGNOF(u8));

		ASSERT(exe_path_capacity_cutoff < U32_MAX);
		while (exe_path_capacity < exe_path_capacity_cutoff)
		{
			exe_path_size = GetModuleFileNameA(0, exe_path, (DWORD)exe_path_capacity);
			if (exe_path_size == 0 || exe_path_size == exe_path_capacity)
			{
				// NOTE: poor growth behaviour, but this should never happen, so I guess its fine
				exe_path_capacity += PageSize;
				Arena_Push(platform_arena, PageSize, ALIGNOF(u8));
				continue;
			}
			else break;
		}

		if (exe_path_capacity >= exe_path_capacity_cutoff)
		{
			//// ERROR: Path too long
			NOT_IMPLEMENTED;
		}
		else
		{
			for (umm i = exe_path_size-1; i < exe_path_size; --i)
			{
				if (exe_path[i] == '/' || exe_path[i] == '\\')
				{
					exe_path[i+1] = 0;
					break;
				}
			}

			if (!SetCurrentDirectoryA(exe_path))
			{
				//// ERROR: Failed to set 
				NOT_IMPLEMENTED;
			}
		}
	}

	Platform_Link platform_link = (Platform_Link){
		.persistent_arena = persistent_arena,
		.frame_arena      = frame_arena,
	};

	Game_Code game_code = {0};
	if (!ReloadGameCodeIfNecessary(&game_code))
	{
		//// ERROR: failed to load game code
		NOT_IMPLEMENTED;
	}

	WNDCLASSA window_class = {
		.style         = CS_OWNDC, // TODO: This is probably needed for gdi blitting, but I don't know
		.lpfnWndProc   = Wndproc,
		.hInstance     = instance,
		.hbrBackground = CreateSolidBrush(0),
		.lpszClassName = ROLD_WINDOW_CLASS_NAME,
	};

	if (!RegisterClassA(&window_class))
	{
		//// ERROR
		NOT_IMPLEMENTED;
	}

	HWND window = CreateWindowA(ROLD_WINDOW_CLASS_NAME, "Rold",
															WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
															0, 0, 0, 0);

	if (window == 0)
	{
		//// ERROR
		NOT_IMPLEMENTED;
	}
	else
	{
		ShowWindow(window, SW_SHOW);

		Running = true;
		while (Running)
		{
			ReloadGameCodeIfNecessary(&game_code);

			for (MSG msg; PeekMessageA(&msg, window, 0, 0, PM_REMOVE);)
			{
				DispatchMessage(&msg);
			}

			game_code.tick_func(platform_link);
		}
	}

	return 0;
}
