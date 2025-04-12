#ifdef __ANDROID__
#include <game-activity/native_app_glue/android_native_app_glue.h>

void handle_cmd(android_app *app, int32_t cmd);

void android_main(android_app *app)
{
  app->onAppCmd = handle_cmd;
  do
  {
    struct android_poll_source *source{nullptr};
    if (ALooper_pollOnce(0, nullptr, nullptr,
                         reinterpret_cast<void **>(&source)) >= 0)
    {
      if (source)
      {
        source->process(app, source);
      }
    }
  } while (!app->destroyRequested);
}

void handle_cmd(android_app *app, int32_t cmd)
{
  switch (cmd)
  {
  case APP_CMD_INIT_WINDOW:
    break;
  case APP_CMD_TERM_WINDOW:
    break;
  case APP_CMD_DESTROY:
    break;
  }
}

#endif __ANDROID__
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Windowsヘッダーからあまり使用されないものを除外します。
#endif
#include <Windows.h>
#include <tchar.h>
#include <string>
import Win32Application;

_Use_decl_annotations_ int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{    
    luna::Win32Application application{};
    return luna::Win32Application::Run(&application, hInstance, nCmdShow);
}
#endif
