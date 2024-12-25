#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class HelloTriangleApplication {
public:
  explicit HelloTriangleApplication(unsigned int width, unsigned int height)
    : m_Width(width), m_Height(height) {}

  void Run();
private:
  void InitWindow();
  void InitVulkan();
  void Loop();
  void Cleanup();

  GLFWwindow* m_Window = nullptr;
  const unsigned int m_Width, m_Height;
private:
  void createInstance();
private:
  VkInstance m_Instance;
};