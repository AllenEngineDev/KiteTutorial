#pragma once

#ifdef KT_PLATFORM_WINDOWS

// To be defined in CLIENT
Kite::Application* Kite::CreateApplication(); 

int main(int argc, char** argv)
{
    printf("[KITE]: ENTRY POINT REACHED\n");
    auto app = Kite::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#else
    #error "Kite only supports Windows!"
#endif  