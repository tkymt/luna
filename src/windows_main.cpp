#include <Windows.h>
#include <tchar.h>
#include "Application.hpp"
#include "Win32Application.hpp"

_Use_decl_annotations_ int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpCmdLine, int nCmdShow)
{
    return luna::Win32Application::Run(hInstance, nCmdShow);
}
