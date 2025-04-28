module;
#include <Windows.h>

export module Win32Application;
import Application;

namespace luna
{
	export class Win32Application
	{
	public:
		static int Run(Application *, HINSTANCE, int);
		static HWND GetHwnd();

	protected:
		static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

	private:
		static void ErrorExit();
		static HWND _hwnd;
	};
}
