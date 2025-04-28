module;
#include <Windows.h>
#include <vulkan/vulkan.hpp>
#include <string>
#include <cstdint>

module Graphics;

namespace luna
{
  Graphics::Graphics(HINSTANCE hInstance,HWND hwnd,uint32_t width,uint32_t height)
  :m_hInstance{hInstance}
  ,m_hwnd{hwnd}
  ,m_width{width}
  ,m_height{height}
  {}

  void Graphics::run() {}
  void Graphics::initVulkan() {}
  void Graphics::mainLoop() {}
  void Graphics::cleanup()
  {
    m_instance.destroy();
  }
  void Graphics::createInstance()
  {
    std::string applicationName{"Luna Application"};
    std::string engineName{"Luna Engine"};
    vk::ApplicationInfo applicationInfo{
    applicationName.c_str(),
    0,
    engineName.c_str(),
    0,
    vk::ApiVersion10
  };
  vk::InstanceCreateInfo instanceCreateInfo{
    {},
    &applicationInfo
  };
  m_instance = vk::createInstance(instanceCreateInfo);

  }
}
