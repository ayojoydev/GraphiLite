#pragma once

#include "GLFWWindow.h"
#include "VulkanRenderer.h"
#include "ImGuiLayer.h"

namespace GraphiLite {

class GraphiLiteApp {
public:
    GraphiLiteApp();
    ~GraphiLiteApp();

    void Run();

private:
    void Init();
    void Shutdown();

    GLFWWindow* window = nullptr;
    VulkanRenderer* renderer = nullptr;
    ImGuiLayer* imguiLayer = nullptr;

    bool isRunning = true;
};

} // namespace GraphiLite
