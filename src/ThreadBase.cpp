#include "ThreadBase.hpp"
namespace luna
{
    ThreadBase::~ThreadBase() { Terminate(); }

    void ThreadBase::Start()
    {
        if (_jthread.joinable())
        {
            return;
        }
        _jthread = std::jthread(
            [this](std::stop_token st)
            {
                this->Run(st);
            });
    }

    void ThreadBase::Terminate()
    {
        if (_jthread.joinable())
        {
            _jthread.request_stop();
            _jthread.join();
        }
    }

    bool ThreadBase::IsRunning() const
    {
        return _jthread.joinable();
    }

    void ThreadBase::Sleep(std::chrono::nanoseconds duration) const
    {
        std::this_thread::sleep_for(duration);
    }
}