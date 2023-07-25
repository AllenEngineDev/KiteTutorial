add_executable(Sandbox "src/main.cpp")

# Linking our main Kite DLL
target_link_libraries(Sandbox PRIVATE Kite)
target_include_directories(Sandbox PRIVATE "../Engine/src")