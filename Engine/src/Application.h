#pragma once
#include "Core.h"

// To be overriden by Sandbox
namespace Kite {
    class KITE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}