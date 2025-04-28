module;
#include <thread>
#include <string>
export module Application;
import ThreadBase;

namespace luna
{
export class Application: ThreadBase
{
public:
	Application() = default;
	~Application() = default;

protected:
	void Run(std::stop_token) override;

private:
};
void Application::Run(std::stop_token st)
{
	// Main loop
	while(st.stop_requested())
	{
		// Update logic here
		std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Simulate work
	}
}
}
