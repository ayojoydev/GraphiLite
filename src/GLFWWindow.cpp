#include "GLFWWindow.h"
#include <stdexcept>
#include <iostream>

namespace GraphiLite {

GLFWWindow::GLFWWindow(int width, int height, const std::string& title) {
    Init(width, height, title);
}

GLFWWindow::~GLFWWindow() {
    Shutdown();
}

void GLFWWindow::Init(int width, int height, const std::string& title) {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Без OpenGL контекста
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create GLFW window!");
}

void GLFWWindow::Shutdown() {
    if (window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

void GLFWWindow::PollEvents() {
    glfwPollEvents();
}

bool GLFWWindow::ShouldClose() const {
    return glfwWindowShouldClose(window);
}

GLFWwindow* GLFWWindow::GetNativeWindow() const {
    return window;
}

} // namespace GraphiLite
