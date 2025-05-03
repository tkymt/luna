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
      int width;
      int height;
    };

  public:
    VulkanRenderer(WindowData);
    void run();
    void mainLoop();
    void cleanup();

  private:
    void initVulkan();
    void createInstance();
    bool checkValidationLayerSupport();

  private:
    WindowData m_windowData;

    const std::vector<const char *> m_validationLayers{
        "VK_LAYER_KHRONOS_validation"};

#ifndef DEBUG
    const bool enableValidationLayers = true;
#else
    const bool enableValidationLayers = false;
#endif

    vk::Instance m_instance;
  };

} // namespace luna
#endif // LUNA_VULKAN_RENDERER_HPP