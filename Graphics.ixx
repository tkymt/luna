module;
#include <Windows.h>
#include <cstdint>
#include <vulkan/vulkan.hpp>
export module Graphics;

namespace luna
{
	export class Graphics {
	public:
		Graphics(HINSTANCE, HWND, uint32_t, uint32_t);
		void run();
	private:
		void initVulkan();
		void mainLoop();
		void cleanup();
		void createInstance();
	private:
		const uint32_t m_width;
		const uint32_t m_height;
		HINSTANCE m_hInstance;
		HWND m_hwnd;

		vk::Instance m_instance;
	};
}
