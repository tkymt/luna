#include "VulkanRenderer.hpp"

namespace luna
{

  VulkanRenderer::VulkanRenderer(WindowData WindowData)
      : m_windowData{WindowData}
  {
  }

  void VulkanRenderer::run()
  {
    initVulkan();
    mainLoop();
    cleanup();
  }

  void VulkanRenderer::initVulkan()
  {
    createInstance();
  }

  void VulkanRenderer::mainLoop() {}

  void VulkanRenderer::cleanup()
  {
    m_instance.destroy();
  }

  void VulkanRenderer::createInstance()
  {
    vk::ApplicationInfo applicationInfo{
        "Luna",
        vk::makeApiVersion(0, 1, 0, 0),
        "No Engine",
        vk::makeApiVersion(0, 1, 0, 0),
        vk::ApiVersion10};
    vk::InstanceCreateInfo instanceCreateInfo{

    };
  }

} // namespace luna
