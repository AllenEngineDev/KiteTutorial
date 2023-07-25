#pragma once

#ifdef KT_BUILD_DLL
    #define KITE_API __declspec(dllexport)
#else
    #define KITE_API __declspec(dllimport)
#endif