#include "Application.hpp"
#include "VulkanRenderer.hpp"

namespace luna
{
    Application::Application(VulkanRenderer &renderer)
        : m_renderer{renderer}
    {
    }

    void Application::Run(std::stop_token st)
    {
        m_renderer.run();
        while (!st.stop_requested())
        {
            m_renderer.mainLoop();
        }
        m_renderer.cleanup();
    }
}