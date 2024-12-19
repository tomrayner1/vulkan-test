cmake_minimum_required(VERSION 3.12)

PROJECT(vulkantest VERSION 1.0 LANGUAGES C CXX)

# Ensure we are using C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find local installation of Vulkan SDK
find_package(Vulkan REQUIRED)

if(Vulkan_FOUND)
  message(STATUS "Vulkan installed at ${Vulkan_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Vulkan SDK isn't installed correctly.")
endif()

include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)

FetchContent_MakeAvailable(glfw)

add_subdirectory(src)
