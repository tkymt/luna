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
