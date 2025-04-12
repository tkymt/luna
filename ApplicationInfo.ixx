module;
#include <string>

export module ApplicationInfo;

namespace luna
{
	export class ApplicationInfo
	{
	public:
		ApplicationInfo()
		{
			_applicationInfo = this;
		};
		~ApplicationInfo()
		{
			_applicationInfo = nullptr;
		};
		ApplicationInfo *GetInstance()
		{
			return _applicationInfo;
		};

	protected:
		unsigned int screenWidth = 0;
		unsigned int screenHeight = 0;
		std::string applicationName = "";

	private:
		static ApplicationInfo *_applicationInfo;
	};

	ApplicationInfo *ApplicationInfo::_applicationInfo{};
}