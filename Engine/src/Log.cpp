#include "Log.h"

namespace Kite {    

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    // Initializes the Core and Client loggers. Must be called before any logging functions are
    void Log::Init()
    {
        s_CoreLogger = spdlog::stdout_color_mt("Core Logger");
        s_ClientLogger = spdlog::stdout_color_mt("Client Logger");

        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}