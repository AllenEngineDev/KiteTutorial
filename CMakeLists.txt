set(ENGINE_SOURCE_DIR "Engine/src")
set(ENGINE_OUTPUT_LIB_DIR "${CMAKE_BINARY_DIR}/Kite/lib")
set(ENGINE_OUTPUT_DLL_DIR "${CMAKE_BINARY_DIR}/Kite/bin")

cmake_minimum_required(VERSION 3.10)

project(KiteEngine)

# Building the Kite Engine DLL
add_library(Kite SHARED "${ENGINE_SOURCE_DIR}/main.cpp")
# Setting where the Kite Engine DLL should be built.
set_target_properties(Kite
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_LIB_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_LIB_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_DLL_DIR}"
)

# Add a custom target to copy the DLL after the executable is built
# The DEPENDS commands mean that it will only be built after the Sandbox executable is built.
add_custom_target(CopyKiteDLL ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    "${ENGINE_OUTPUT_DLL_DIR}/libKite.dll"
    $<TARGET_FILE_DIR:Sandbox>
    DEPENDS Sandbox
)


# Check CMakeLists.txt of this to learn more. Building this in build/bin/
add_subdirectory("Sandbox" "Sandbox/bin")
