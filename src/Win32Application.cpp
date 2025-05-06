#include "Win32Application.hpp"
#include "Application.hpp"
#include <Windows.h>
#include <tchar.h>

namespace luna
{
  int Win32Application::Run(HINSTANCE hInstance, int nCmdShow)
  {
    WNDCLASSEX windowClassEx{
        .cbSize = sizeof(WNDCLASSEX),
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = WindowProcedure,
        .hInstance = hInstance,
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .lpszClassName = _TEXT("Luna Window Class")};

    if (RegisterClassEx(&windowClassEx) == 0)
    {
      // エラーハンドリング
      ErrorExit();
    }

    // ウィンドウのタイトルバーを除いた部分であるクライアント領域のサイズを指定
    RECT windowRect{
        .right = 1280,
        .bottom = 960};

    if (AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE) == 0)
    {
      // エラーハンドリング
      ErrorExit();
    }

    Application application;
    m_hwnd = CreateWindow(windowClassEx.lpszClassName,
                          _TEXT("Luna Application"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          windowRect.right - windowRect.left,
                          windowRect.bottom - windowRect.top,
                          NULL,
                          NULL,
                          hInstance,
                          reinterpret_cast<LPVOID>(&application));

    if (m_hwnd == NULL)
    {
      MessageBox(NULL, _TEXT("ウインドウの作成に失敗しました。"), _TEXT("エラー"), MB_OK | MB_ICONERROR);
      return EXIT_FAILURE;
    }

    ShowWindow(m_hwnd, nCmdShow);
    application.Start();

    MSG msg{};
    while (true)
    {
      BOOL msgReturn{GetMessage(&msg, m_hwnd, 0, 0)};

      if (msgReturn == 0)
        break;
      if (msgReturn == -1)
        ErrorExit();

      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
  }

  HWND Win32Application::GetHwnd() { return m_hwnd; }

  LRESULT CALLBACK Win32Application::WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
  {
    if (msg == WM_CREATE)
    {
      CREATESTRUCT *createStruct{reinterpret_cast<CREATESTRUCT *>(lParam)};
      Application *application = reinterpret_cast<luna::Application *>(createStruct->lpCreateParams);
      SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(application));
      RECT clientRect;
      GetClientRect(hwnd, &clientRect);
      LONG width = clientRect.right - clientRect.left;
      LONG height = clientRect.bottom - clientRect.top;
      application->OnWindowCreated(createStruct->hInstance, hwnd, width, height);
      return 0;
    }
    else if (msg == WM_DESTROY)
    {
      Application *application = reinterpret_cast<Application *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
      application->Terminate();
      PostQuitMessage(EXIT_SUCCESS);
      return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
  }

  void Win32Application::ErrorExit()
  {
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    DWORD dw = GetLastError();

    if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                          FORMAT_MESSAGE_FROM_SYSTEM |
                          FORMAT_MESSAGE_IGNORE_INSERTS,
                      NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      (LPTSTR)&lpMsgBuf, 0, NULL) == 0)
    {
      MessageBox(NULL, TEXT("FormatMessage failed"), TEXT("Error"), MB_OK);
      ExitProcess(dw);
    }

    MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    ExitProcess(dw);
  }

  /// @brief 値初期化によるゼロ初期化でnullptrを初期値にする
  HWND Win32Application::m_hwnd{};
} // namespace luna
