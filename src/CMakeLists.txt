add_executable(vkHelloTriangle
  HelloTriangle.cpp)

target_link_libraries(vkHelloTriangle PRIVATE glfw Vulkan::Vulkan)
target_include_directories(vkHelloTriangle PUBLIC ${VULKAN_INCLUDE_DIRS})