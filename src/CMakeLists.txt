add_executable(vkHelloTriangle
  HelloTriangle.cpp)

target_link_libraries(vkHelloTriangle PRIVATE glfw Vulkan::Vulkan)