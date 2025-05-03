#include "GameInfo.hpp"

namespace luna
{
  GameInfo::GameInfo()
  {
    s_GameInfo = this;
  }
  GameInfo::~GameInfo()
  {
    s_GameInfo = nullptr;
  }
  GameInfo *GameInfo::GetInstance()
  {
    return s_GameInfo;
  }
  GameInfo *GameInfo::s_GameInfo{};
} // namespace luna
