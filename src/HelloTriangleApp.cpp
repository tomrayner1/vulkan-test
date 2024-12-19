#include "HelloTriangleApp.h"
#include "GLFW/glfw3.h"
#include <GLFW/glfw3.h>

void HelloTriangleApplication::Run() {
  InitWindow();
  InitVulkan();
  Loop();
  Cleanup();
}

void HelloTriangleApplication::InitWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  m_Window = glfwCreateWindow(m_Width, m_Height, "HelloTriangle", nullptr, nullptr);
}

void HelloTriangleApplication::InitVulkan() {
  createInstance();
}

void HelloTriangleApplication::Loop() {
  while (!glfwWindowShouldClose(m_Window)) {
    glfwPollEvents();
  }
}

void HelloTriangleApplication::Cleanup() {
  vkDestroyInstance(m_Instance, nullptr);

  glfwDestroyWindow(m_Window);
  glfwTerminate();
}

//------------------------------------------------------------------------------
// Vulkan methods
//------------------------------------------------------------------------------

void HelloTriangleApplication::createInstance() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;
  createInfo.enabledLayerCount = 0;

  vkCreateInstance(&createInfo, nullptr, &m_Instance);
}