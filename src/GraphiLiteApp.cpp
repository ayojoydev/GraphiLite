#include "GraphiLiteApp.h"
#include <iostream>

namespace GraphiLite {

GraphiLiteApp::GraphiLiteApp() {
    Init();
}

GraphiLiteApp::~GraphiLiteApp() {
    Shutdown();
}

void GraphiLiteApp::Init() {
    window = new GLFWWindow(1280, 720, "GraphiLite Window");
    renderer = new VulkanRenderer(window->GetNativeWindow());
    imguiLayer = new ImGuiLayer(window->GetNativeWindow(), renderer->GetVulkanInstance());
}

void GraphiLiteApp::Shutdown() {
    delete imguiLayer;
    delete renderer;
    delete window;
}

void GraphiLiteApp::Run() {
    while (!window->ShouldClose()) {
        window->PollEvents();

        imguiLayer->Begin();
        {
            ImGui::ShowDemoWindow(); // Показать тестовое окно ImGui
        }
        imguiLayer->End();
    }
}

} // namespace GraphiLite
