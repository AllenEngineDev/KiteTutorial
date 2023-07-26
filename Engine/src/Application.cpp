#include "Application.h"
#include "Events/WindowEvent.h"
#include "Log.h"

namespace Kite {
    Application::Application()
    {
    }

    Application::~Application()
    {

    }

    bool TestWindowResize(WindowResizeEvent& event)
    {
        KT_CORE_INFO("Window Resize Event Dispatched!");
        return false;
    }

    void Application::Run()
    {   
        // Testing events
        WindowResizeEvent wr(1280, 720);
        KT_CORE_INFO(wr.ToString());
        EventDispatcher<WindowResizeEvent> dispatcher(wr);
        dispatcher.Dispatch(TestWindowResize);

        while (true);
    }

    

}