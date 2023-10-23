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
#define ROLD_DLL_PATH "rold.dll"
#define ROLD_DLL_LOADED_PATH "rold_loaded.dll"
#define ROLD_TICK_FUNC_NAME "Tick"

bool Running = false;

typedef struct Win32_Game_Code
{
	HMODULE dll;
	Game_Tick_Func* tick;
	FILETIME file_time;
} Win32_Game_Code;

bool
ReloadGameCodeIfNecessary(Win32_Game_Code* game_code)
{
	bool should_reload = true;
	if (game_code->dll != 0)
	{
		WIN32_FILE_ATTRIBUTE_DATA file_info;
		if (!GetFileAttributesExA(ROLD_DLL_PATH, GetFileExInfoStandard, &file_info)) should_reload = false;
		else
		{
			should_reload = (CompareFileTime(&game_code->file_time, &file_info.ftLastWriteTime) == -1);
		}
	}

	bool result = false;
	if (!should_reload) result = true;
	else
	{
		if (game_code->dll == 0 || FreeLibrary(game_code->dll))
		{
			// TODO: Eliminate this delay without tripping DEP
			Sleep(500);
			if (CopyFile(ROLD_DLL_PATH, ROLD_DLL_LOADED_PATH, FALSE))
			{
				game_code->dll = LoadLibraryA(ROLD_DLL_LOADED_PATH);
				if (game_code->dll != 0)
				{
					game_code->tick = (Game_Tick_Func*)GetProcAddress(game_code->dll, ROLD_TICK_FUNC_NAME);
					if (game_code->tick != 0)
					{
						// NOTE: filetime is not critical to success, so set to a safe value when query fails
						// TODO: ensure 0 is safe
						WIN32_FILE_ATTRIBUTE_DATA file_info;
						if (GetFileAttributesExA(ROLD_DLL_PATH, GetFileExInfoStandard, &file_info)) game_code->file_time = file_info.ftLastWriteTime;
						else                                                                        game_code->file_time = (FILETIME){0};

						OutputDebugStringA("Reloaded game code successfully\n");
						result = true;
					}
				}
			}
		}
	}

	return result;
}

void
Arena_CommitMoreMemory(Arena_Internal* arena)
{
	umm required_size = arena->cursor - arena->committed;
	umm extra_size    = KB(4);
	void* result = VirtualAlloc(arena->memory + arena->committed, required_size + extra_size, MEM_COMMIT, PAGE_READWRITE);
	if (result == 0)
	{
		//// ERROR: Failed to commit memory
	}
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
	Arena_Internal arena_bank[3];
	Arena* platform_arena    = (Arena*)&arena_bank[0];
	Arena* persistent_arena  = (Arena*)&arena_bank[1];
	Arena* frame_arena       = (Arena*)&arena_bank[2];
	{ /// Setup Memory Arenas ---------------------------------------------------------------------------------------------
		umm reserve_size = GB(32);
		for (umm i = 0; i < STATIC_ARRAY_SIZE(arena_bank); ++i)
		{
			void* memory = VirtualAlloc(0, reserve_size, MEM_RESERVE, PAGE_READWRITE);
			if (memory == 0)
			{
				//// ERROR: Failed to reserve memory
				NOT_IMPLEMENTED;
			}

			arena_bank[i] = (Arena_Internal){
				.commit_more_memory = Arena_CommitMoreMemory,
				.cursor             = 0,
				.committed          = 0,
				.reserved           = reserve_size,
				.memory             = memory,
			};
		}
	}

	{ /// Set Working Directory -------------------------------------------------------------------------------------------
		Arena_Marker* marker = Arena_GetMarker(platform_arena);

		DWORD working_dir_growth   = MAX_PATH;
		DWORD working_dir_cutoff   = 10*MAX_PATH; // TODO: idk man
		DWORD working_dir_capacity = MAX_PATH;
		DWORD working_dir_size     = 0;
		LPSTR working_dir          = Arena_Push(platform_arena, working_dir_capacity, ALIGNOF(u8));
		
		for (;;)
		{
			working_dir_size = GetModuleFileNameA(0, working_dir, working_dir_capacity);
			if (working_dir_size == 0 || working_dir_size == working_dir_capacity)
			{
				if (working_dir_capacity < working_dir_cutoff)
				{
					Arena_Push(platform_arena, working_dir_growth, ALIGNOF(u8));
					working_dir_capacity += working_dir_growth;
					continue;
				}
				else
				{
					//// ERROR: Failed to query directory of executable
					NOT_IMPLEMENTED;
					break;
				}
			}
			else break;
		}

		while (working_dir[working_dir_size-1] != '\\' && working_dir[working_dir_size-1] != '/') --working_dir_size;
		working_dir[working_dir_size] = 0;

		if (!SetCurrentDirectoryA(working_dir))
		{
			//// ERROR: Failed to set working directory
			NOT_IMPLEMENTED;
		}

		Arena_PopToMarker(platform_arena, marker);
	}

	Win32_Game_Code game_code   = {0};
	Platform_Link platform_link = {
		.persistent_arena = persistent_arena,
		.frame_arena      = frame_arena,
	};
	{ /// Load Game -------------------------------------------------------------------------------------------------------
		for (umm i = 0;; ++i)
		{
			if      (ReloadGameCodeIfNecessary(&game_code)) break;
			else if (i < 100)
			{
				Sleep(20);
				continue;
			}
			else
			{
				//// ERROR: Failed to load game code
				NOT_IMPLEMENTED;
			}
		}
	}

	HWND window = 0;
	{ /// Create Window ---------------------------------------------------------------------------------------------------
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

		window = CreateWindowA(ROLD_WINDOW_CLASS_NAME, "Rold",
													 WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
													 0, 0, 0, 0);

		if (window == 0)
		{
			//// ERROR
			NOT_IMPLEMENTED;
		}
	}

	ShowWindow(window, SW_SHOW);
	Running = true;
	while (Running)
	{
		ReloadGameCodeIfNecessary(&game_code);

		for (MSG msg; PeekMessageA(&msg, window, 0, 0, PM_REMOVE);)
		{
			DispatchMessage(&msg);
		}

		game_code.tick(platform_link);
	}

	return 0;
}
