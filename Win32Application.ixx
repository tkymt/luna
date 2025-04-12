module;
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Windowsヘッダーからあまり使用されないものを除外します。
#endif
#include <Windows.h>
#include <string>

export module Win32Application;
import Application;

namespace luna
{
	export class Win32Application
	{
	public:
		static int Run(luna::Win32Application *, HINSTANCE, int);
		static HWND GetHwnd();

	protected:
		static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

	private:
		static void ErrorExit();
		static HWND _hwnd;
	};
}
