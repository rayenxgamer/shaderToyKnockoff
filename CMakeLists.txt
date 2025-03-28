cmake_minimum_required(VERSION 3.27)
project(ShaderToyKnockoff)

set(CMAKE_CXX_STANDARD)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ShaderToyKnockoff
  src/main.cpp
  src/gfx/common/window.cpp
  src/gfx/common/log.cpp
  src/gfx/common/shader.cpp
  src/gfx/common/camera.cpp
  lib/glad/glad.c
  lib/stb_image/stb_image.c
)

target_include_directories(ShaderToyKnockoff PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/lib
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx
)

target_link_directories(ShaderToyKnockoff PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/libglfw3.a
)

target_link_libraries(ShaderToyKnockoff PRIVATE
  glfw
  m
  dl
  pthread
)

# plz let me be goud at grapjix programin
