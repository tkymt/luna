#ifndef LUNA_APPLICATION_HPP
#define LUNA_APPLICATION_HPP

#include "ThreadBase.hpp"
#include "VulkanRenderer.hpp"
#include <memory>

namespace luna
{
  class Application : public ThreadBase
  {
  public:
    Application() = default;
    void OnWindowCreated(HINSTANCE hInstance, HWND hwnd, LONG width, LONG height);

  private:
    void Run(std::stop_token) override final;

    std::unique_ptr<VulkanRenderer> m_renderer{nullptr};
  };

} // namespace luna

#endif // LUNA_APPLICATION_HPP