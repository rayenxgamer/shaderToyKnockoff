#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

class Window{
  public:
    bool running;
    GLFWwindow* window;

    Window(int width, int height, const char* title);
    ~Window();
    void Update();
    void ClearColor(float r, float g, float b, float a);
    // * setting keycallback is temporary, will have
    // * a vector based input system anytime soon
    GLFWkeyfun SetKeyCallback(GLFWkeyfun key_callback);
    GLFWmousebuttonfun SetMouseCallback(GLFWmousebuttonfun mouse_callback){
    return glfwSetMouseButtonCallback(window, mouse_callback);
  }
    bool ShouldClose();
    float GetDeltaTime();
  private:
    float deltaTime;
    float timeSincelastFrame;
};




