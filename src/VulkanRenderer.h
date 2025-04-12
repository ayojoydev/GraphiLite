#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace GraphiLite {

class VulkanRenderer {
public:
    VulkanRenderer(GLFWwindow* window);
    ~VulkanRenderer();

    VkInstance GetVulkanInstance() const { return instance; }

private:
    void Init(GLFWwindow* window);
    void Shutdown();

    VkInstance instance = VK_NULL_HANDLE;
};

} // namespace GraphiLite
