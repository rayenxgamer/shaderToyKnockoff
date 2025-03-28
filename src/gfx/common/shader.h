#pragma once

#include <glad/glad.h>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace glm;

class Shader {
  public:
  unsigned int ID;

  Shader(const char* vsPath, const char* fsPath);
  void Bind();

  void setBool (std::string& name, bool value);
  void setInt (const std::string& name, int value);
  void setFloat(std::string& name, float value);
  void setMat4 (const std::string& name, mat4 value);
  void setVec3 (std::string& name, vec3 value);
  void setVec2 (std::string& name, vec2 value);
  void setVec4 (std::string& name, vec4 value);
  private:
  const char* vertex;
  const char* fragment;
  const char* m_vsPath;
  const char* m_fsPath;

void compileShaders(std::string vertexChar, std::string fragmentChar);
};
