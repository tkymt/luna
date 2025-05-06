#include "VulkanRenderer.hpp"
#include <iostream>

namespace luna
{
  VulkanRenderer::VulkanRenderer(WindowData windowData)
      : m_windowData{windowData}
  {
  }

  void VulkanRenderer::run()
  {
    try
    {
      // コンテキストをインスタンス化
      vk::raii::Context context;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  void VulkanRenderer::mainLoop()
  {
    // メインループの処理をここに記述
  }
  void VulkanRenderer::cleanup()
  {
    // クリーンアップ処理をここに記述
  }
} // namespace luna