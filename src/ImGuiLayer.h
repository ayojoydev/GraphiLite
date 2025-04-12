#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace GraphiLite {

class ImGuiLayer {
public:
    ImGuiLayer(GLFWwindow* window, VkInstance instance);
    ~ImGuiLayer();

    void Begin();
    void End();

private:
    void Init(GLFWwindow* window, VkInstance instance);
    void Shutdown();
};

} // namespace GraphiLite
