#pragma once
#include "ktpch.h"
#include "Core.h"

// Log class
namespace Kite {
    class KITE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core logging macros
#define KT_CORE_ERROR(...)      Kite::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KT_CORE_WARN(...)       Kite::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KT_CORE_INFO(...)       Kite::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KT_CORE_TRACE(...)      Kite::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logging macros
#define KT_ERROR(...)           Kite::Log::GetClientLogger()->error(__VA_ARGS__)
#define KT_WARN(...)            Kite::Log::GetClientLogger()->error(__VA_ARGS__)
#define KT_INFO(...)            Kite::Log::GetClientLogger()->error(__VA_ARGS__)
#define KT_TRACE(...)           Kite::Log::GetClientLogger()->error(__VA_ARGS__)

