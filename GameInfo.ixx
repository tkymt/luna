module;
#include <string>

export module GameInfo;

namespace luna
{
export class GameInfo
{
public:
	GameInfo()
	{
		s_GameInfo = this;
	};
	~GameInfo()
	{
		s_GameInfo = nullptr;
	};
	GameInfo *GetInstance()
	{
		return s_GameInfo;
	};

protected:
	uint32_t m_ScreenWidth{1280};
	uint32_t m_ScreenHeight{960};
	std::string m_ApplicationName{};

private:
	static GameInfo *s_GameInfo;
};

GameInfo *GameInfo::s_GameInfo{};
}
