#include "ImGuiLayer.h"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_vulkan.h>

#include <stdexcept>

namespace GraphiLite {

ImGuiLayer::ImGuiLayer(GLFWwindow* window, VkInstance instance) {
    Init(window, instance);
}

ImGuiLayer::~ImGuiLayer() {
    Shutdown();
}

void ImGuiLayer::Init(GLFWwindow* window, VkInstance /*instance*/) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForVulkan(window, true);

    // Здесь должна быть полноценная настройка для Vulkan,
    // но для минимального примера опустим детали.
}

void ImGuiLayer::Shutdown() {
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::Begin() {
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::End() {
    ImGui::Render();
    // Обычно тут ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), commandBuffer);
    // Но пока Vulkan рендер-пайплайна нет — оставляем пустым.
}

} // namespace GraphiLite