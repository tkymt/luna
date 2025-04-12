module;
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Windowsヘッダーからあまり使用されないものを除外します。
#endif
#include <Windows.h>
#include <cstdlib>
#include <tchar.h>

module Win32Application;


namespace luna
{
	int Win32Application::Run(luna::Win32Application *application, HINSTANCE hInstance, int nCmdShow)
	{
		WNDCLASSEX windowClassEx{
			.cbSize{sizeof(WNDCLASSEX)},
			.style{CS_HREDRAW | CS_VREDRAW},
			.lpfnWndProc{WindowProcedure},
			.hInstance{hInstance},
			.hCursor{LoadCursor(NULL, IDC_ARROW)},
			.lpszClassName{_TEXT("Luna Window Class")}};

		if (RegisterClassEx(&windowClassEx) == 0)
		{
			// エラーハンドリング
			ErrorExit();
		}

		// ウィンドウのタイトルバーを除いた部分であるクライアント領域のサイズを指定
		RECT windowRect{
			.right{1280},
			.bottom{960}};
		if (AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE) == 0)
		{
			// エラーハンドリング
			ErrorExit();
		}

		if ((_hwnd = CreateWindow(
				 windowClassEx.lpszClassName,
				 _TEXT("Luna Application"),
				 WS_OVERLAPPEDWINDOW,
				 CW_USEDEFAULT,
				 CW_USEDEFAULT,
				 windowRect.right - windowRect.left,
				 windowRect.bottom - windowRect.top,
				 NULL,
				 NULL,
				 hInstance,
				 application)) == NULL)
		{
			MessageBox(NULL, _TEXT("ウインドウの作成に失敗しました。"), _TEXT("エラー"), MB_OK | MB_ICONERROR);
			return EXIT_FAILURE;
		}

		ShowWindow(_hwnd, nCmdShow);
		/*
			MSG msg{};
			while (msg.message != WM_QUIT)
			{
				if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					// luna->Update();
				}
			}
		*/

		MSG msg{};
		BOOL msgReturn{};
		while ((msgReturn = GetMessage(&msg, _hwnd, 0, 0)) != 0)
		{
			if (msgReturn == -1)
			{
				ErrorExit();
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		return static_cast<int>(msg.wParam);
	}

	HWND Win32Application::GetHwnd()
	{
		return _hwnd;
	}

	LRESULT CALLBACK Win32Application::WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		luna::Application* luna{ reinterpret_cast<luna::Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA)) };
		switch (msg)
		{
		case WM_CREATE:
		{
			CREATESTRUCT* createStruct{ reinterpret_cast<CREATESTRUCT*>(lParam) };
			luna = { reinterpret_cast<luna::Application*>(createStruct->lpCreateParams) };
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(luna));
			return 0;
		}
		case WM_DESTROY:
			PostQuitMessage(EXIT_SUCCESS);
			return 0;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
	}

	void Win32Application::ErrorExit()
	{
		// Retrieve the system error message for the last-error code

		LPVOID lpMsgBuf;
		DWORD dw = GetLastError();

		if (FormatMessage(
				FORMAT_MESSAGE_ALLOCATE_BUFFER |
					FORMAT_MESSAGE_FROM_SYSTEM |
					FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				dw,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR)&lpMsgBuf,
				0, NULL) == 0)
		{
			MessageBox(NULL, TEXT("FormatMessage failed"), TEXT("Error"), MB_OK);
			ExitProcess(dw);
		}

		MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK);

		LocalFree(lpMsgBuf);
		ExitProcess(dw);
	}

	/// @brief 値初期化によるゼロ初期化でnullptrを初期値にする
	HWND Win32Application::_hwnd{};
}
