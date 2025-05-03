#ifndef LUNA_GAMEINFO_HPP
#define LUNA_GAMEINFO_HPP
#include <string>

namespace luna
{
  class GameInfo
  {
  public:
    GameInfo();
    ~GameInfo();
    GameInfo *GetInstance();

  protected:
    uint32_t m_ScreenWidth{1280};
    uint32_t m_ScreenHeight{960};
    std::string m_ApplicationName{};

  private:
    static GameInfo *s_GameInfo;
  };
} // namespace luna
#endif // LUNA_GAMEINFO_HPP