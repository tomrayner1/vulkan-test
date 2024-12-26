cmake_minimum_required(VERSION 3.12)

PROJECT(vulkantest VERSION 1.0 LANGUAGES CXX)

# Ensure we are using C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find local installation of Vulkan SDK
find_package(Vulkan REQUIRED)

if(Vulkan_FOUND)
  message(STATUS "Found ${Vulkan_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Couldn't find Vulkan SDK.")
endif()

include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)

FetchContent_MakeAvailable(glfw)

add_subdirectory(logging)

add_subdirectory(hellotriangle)
