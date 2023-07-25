set(ENGINE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Engine")
set(ENGINE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Engine/src")
set(ENGINE_OUTPUT_LIB_DIR "${CMAKE_BINARY_DIR}/Kite/lib")
set(ENGINE_OUTPUT_DLL_DIR "${CMAKE_BINARY_DIR}/Kite/bin")

cmake_minimum_required(VERSION 3.10)

project(KiteEngine)

# Getting all the sources using GLOB
file(GLOB ENGINE_SOURCES CONFIGURE_DEPENDS
    "${ENGINE_SOURCE_DIR}/*.cpp")

# Building the Kite Engine DLL
add_library(Kite SHARED ${ENGINE_SOURCES})
# Setting where the Kite Engine DLL should be built.
set_target_properties(Kite
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_LIB_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_LIB_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_DLL_DIR}"
)

# Preprocessor definitions
target_compile_definitions(Kite PRIVATE KT_BUILD_DLL KT_PLATFORM_WINDOWS)

# Include directories for the Engine/include/Kite.h
target_include_directories(Kite PUBLIC ${ENGINE_SOURCE_DIR})

# Add a custom target to copy the DLL to the directory where the Sandbox target is built 
add_custom_target(CopyKiteDLL ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    "${ENGINE_OUTPUT_DLL_DIR}/libKite.dll"
    $<TARGET_FILE_DIR:Sandbox>
    DEPENDS Sandbox
)


# Check CMakeLists.txt of this to learn more. Building this in build/bin/
add_subdirectory("Sandbox" "Sandbox/bin")
