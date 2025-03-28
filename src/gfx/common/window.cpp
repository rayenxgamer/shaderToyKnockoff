#include <common/window.h>

using namespace std;

Window::Window(int width, int height, const char* title){

  if(!glfwInit()){
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  window = glfwCreateWindow(width, height, title, nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
    cout << "failed to create GLFW window!\n";
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "failed to load GLAD!\n";
    exit(EXIT_FAILURE);
  }

  cout << "OpenGl GLSL version :" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  /*  some fuckery to center the */
  /*  screen (will be changed at some point */
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwSetWindowPos(window, mode->height/2, mode->width/7);

  Window::running = true;
}

float Window::GetDeltaTime(){
  float currentTime = glfwGetTime();
  Window::deltaTime = currentTime - timeSincelastFrame;
  timeSincelastFrame = currentTime;
  return deltaTime;
}

bool Window::ShouldClose(){
  return glfwWindowShouldClose(window);
}

GLFWkeyfun Window::SetKeyCallback(GLFWkeyfun key_callback){
  return glfwSetKeyCallback(window, key_callback);
}

void Window::Update(){
  glfwSwapBuffers(window);
  glfwPollEvents();
  if (Window::ShouldClose())
    running = false;
}

void Window::ClearColor(float r, float g, float b, float a){
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Window::~Window(){
  glfwDestroyWindow(window);
  glfwTerminate();
}
