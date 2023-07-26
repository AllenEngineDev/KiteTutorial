#pragma once

// Defining the KITE_API macro -> this is to be used before class as class KITE_API ClassName
#ifdef KT_PLATFORM_WINDOWS // dllimport and dllexport is Windows-only
    #ifdef KT_BUILD_DLL
        #define KITE_API __declspec(dllexport)
    #else
        #define KITE_API __declspec(dllimport)
    #endif
#else
    #error "Kite only supports Windows! Define KT_PLATFORM_WINDOWS in preprocessor definitions and use Windows"
#endif

#define BIT(x) 1 << x