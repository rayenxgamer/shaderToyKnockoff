#include <common/shader.h>
#include <cstdlib>

Shader::Shader(const char* vsPath, const char* fsPath)
: m_vsPath(vsPath), m_fsPath(fsPath) {

  std::ifstream vertexFile, fragmentFile;

  vertexFile.open(vsPath);
  fragmentFile.open(fsPath);

  if (vertexFile.fail()) {
    std::cout << "{CRITICAL} FAILED TO OPEN VERTEX FILE AT : " << vsPath << std::endl;
  }
  if (fragmentFile.fail()) {
    std::cout << "{CRITICAL} FAILED TO OPEN FRAGMENT FILE AT: " << fsPath << std::endl;
  }

  std::stringstream vShaderStream, fShaderStream;

  vShaderStream << vertexFile.rdbuf();
  fShaderStream << fragmentFile.rdbuf();

  vertexFile.close();
  fragmentFile.close();

  std::string vertexChar = vShaderStream.str();
  std::string fragmentChar = fShaderStream.str();

  compileShaders(vertexChar, fragmentChar);
};

void Shader::Bind() {
  glUseProgram(ID);
}

void Shader::compileShaders(std::string vertexChar, std::string fragmentChar){
  unsigned int v,fs;

  vertex = vertexChar.c_str();
  fragment = fragmentChar.c_str();

  v = glCreateShader(GL_VERTEX_SHADER);
  fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(v, 1, &vertex, nullptr);
  glShaderSource(fs, 1, &fragment, nullptr);

  int success;
  char infolog[512];

  glCompileShader(v);
  glCompileShader(fs);

  glGetShaderiv(v,GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(v, 512, nullptr, infolog);
    std::cout << "{CRITICAL} FAILED TO COMPILE VERTEX SHADER AT  "
      << m_vsPath << std::endl;
  }
  glGetShaderiv(fs,GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(fs, 512, nullptr, infolog);
    std::cout << "{CRITICAL} FAILED TO COMPILE FRAGMENT SHADER AT  "
      << m_fsPath << std::endl;
  }

  ID = glCreateProgram();
  glAttachShader(ID, v);
  glAttachShader(ID, fs);

  glLinkProgram(ID);

  glGetProgramiv(ID, GL_LINK_STATUS, &success);

  if (!success) {
    glGetProgramInfoLog(ID, 512 , nullptr, infolog);
    std::cout << "{CRITICAL} FAILED TO LINK PROGRAM FOR " <<
      m_vsPath << " and " << m_fsPath << std::endl;
    exit(EXIT_FAILURE);
  }

  glUseProgram(ID);
  std::cout << "using program\n";
}

void Shader::setBool (std::string& name, bool value){
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat (std::string& name, float value){
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setInt (const std::string& name, int value){
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setMat4 (const std::string& name, mat4 value){
  glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()),1 ,GL_FALSE, &value[0][0]);
}
void Shader::setVec2 (std::string& name, vec2 value){
  glUniform2fv(glGetUniformLocation(ID, name.c_str()),1 , &value[0]);
}
void Shader::setVec3 (std::string& name, vec3 value){
  glUniform3fv(glGetUniformLocation(ID, name.c_str()),1 , &value[0]);
}
void Shader::setVec4 (std::string& name, vec4 value){
  glUniform4fv(glGetUniformLocation(ID, name.c_str()),1 , &value[0]);
}
