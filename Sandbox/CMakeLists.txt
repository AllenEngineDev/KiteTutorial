file (GLOB SANDBOX_SOURCES CONFIGURE_DEPENDS
    "src/*.cpp")
add_executable(Sandbox ${SANDBOX_SOURCES})

# Preprocessor definitions
target_compile_definitions(Sandbox PRIVATE KT_PLATFORM_WINDOWS)

# Linking our main Kite DLL
target_link_libraries(Sandbox PRIVATE Kite)
# Including the Src from Engine directory -> this should be changed to a proper include directory
target_include_directories(Sandbox PRIVATE "../Engine/include")