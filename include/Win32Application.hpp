#ifndef LUNA_WIN32_APPLICATION_HPP
#define LUNA_WIN32_APPLICATION_HPP
#include "Application.hpp"
#include <Windows.h>

namespace luna
{
  class Win32Application
  {
  public:
    static int Run(Application &, const HINSTANCE, const int);
    static HWND GetHwnd();

  protected:
    static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

  private:
    static void ErrorExit();
    static HWND m_hwnd;
  };
} // namespace luna
#endif // LUNA_WIN32_APPLICATION_HPP