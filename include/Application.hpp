#ifndef LUNA_APPLICATION_HPP
#define LUNA_APPLICATION_HPP

#include "ThreadBase.hpp"
#include "VulkanRenderer.hpp"

namespace luna
{
  class Application : public ThreadBase
  {
  public:
    Application(VulkanRenderer &);

  private:
    void Run(std::stop_token) override final;
    VulkanRenderer &m_renderer;
  };

} // namespace luna

#endif // LUNA_APPLICATION_HPP