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

typedef struct Game_Code
{
	HMODULE code;
	Tick_Func* tick_func;
} Game_Code;

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
			for (MSG msg; PeekMessageA(&msg, window, 0, 0, PM_REMOVE);)
			{
				DispatchMessage(&msg);
			}
		}
	}

	return 0;
}
