#include "Application.hpp"
#include "VulkanRenderer.hpp"

namespace luna
{
    void Application::Run(std::stop_token st)
    {
        if (!m_renderer)
            return;

        m_renderer->run();

        while (!st.stop_requested())
        {
            m_renderer->mainLoop();
        }

        m_renderer->cleanup();
    }
    void Application::OnWindowCreated(HINSTANCE hInstance, HWND hwnd, LONG width, LONG height)
    {
        // VulkanRendererのインスタンスを作成
        // WindowData構造体を使用して、ウィンドウデータを渡す
        m_renderer = std::make_unique<VulkanRenderer>(VulkanRenderer::WindowData{hInstance, hwnd, width, height});
    }
}