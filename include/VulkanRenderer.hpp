#ifndef LUNA_VULKAN_RENDERER_HPP
#define LUNA_VULKAN_RENDERER_HPP
#include <vector>
#include <cstdint>
#include <Windows.h>
#include <vulkan/vulkan_raii.hpp>

namespace luna
{
  class VulkanRenderer
  {
  public:
    struct WindowData
    {
      HINSTANCE hInstance;
      HWND hwnd;
      LONG width;
      LONG height;
    };

    VulkanRenderer(WindowData);
    void run();
    void mainLoop();
    void cleanup();

  private:
    WindowData m_windowData;
  };

} // namespace luna
#endif // LUNA_VULKAN_RENDERER_HPP