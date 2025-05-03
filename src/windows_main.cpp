#include <Windows.h>
#include <tchar.h>
#include "Application.hpp"
#include "Win32Application.hpp"

_Use_decl_annotations_ int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpCmdLine, int nCmdShow)
{
    luna::VulkanRenderer renderer{luna::VulkanRenderer::WindowData{hInstance, nullptr, 1280, 960}};
    luna::Application application{renderer};
    return luna::Win32Application::Run(application, hInstance, nCmdShow);
}
