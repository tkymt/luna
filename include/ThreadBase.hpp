#ifndef LUNA_THREAD_BASE_HPP
#define LUNA_THREAD_BASE_HPP
#include <thread>

namespace luna
{
  class ThreadBase
  {
  public:
    ~ThreadBase();
    void Start();
    void Terminate();
    inline bool IsRunning() const;

  protected:
    virtual void Run(std::stop_token) = 0;
    void Sleep(std::chrono::nanoseconds duration) const;

  private:
    std::jthread _jthread;
  };
} // namespace luna
#endif // LUNA_THREAD_BASE_HPP