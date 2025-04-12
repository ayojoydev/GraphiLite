#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace GraphiLite {

class GLFWWindow {
public:
    GLFWWindow(int width, int height, const std::string& title);
    ~GLFWWindow();

    void PollEvents();
    bool ShouldClose() const;
    GLFWwindow* GetNativeWindow() const;

private:
    void Init(int width, int height, const std::string& title);
    void Shutdown();

    GLFWwindow* window = nullptr;
};

} // namespace GraphiLite
