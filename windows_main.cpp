#include <Windows.h>
#include <tchar.h>

import Application;
import Win32Application;

_Use_decl_annotations_ int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpCmdLine, int nCmdShow)
{
    luna::Application application{};
    return luna::Win32Application::Run(&application, hInstance, nCmdShow);
}
