#pragma once

#ifdef KT_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
    printf("[KITE]: ENTRY POINT REACHED\n");

    Kite::Log::Init();
    KT_WARN("Client Logger warning. Test variable set to {0}!", 5);
    KT_CORE_ERROR("Core Logger error!");

    auto app = Kite::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif  