add_executable(vkHelloTriangle
  HelloTriangle.cpp
  HelloTriangleApp.cpp
)

target_link_libraries(vkHelloTriangle PRIVATE glfw Vulkan::Vulkan logging)
# target_include_directories(vkHelloTriangle PUBLIC ${VULKAN_INCLUDE_DIRS})