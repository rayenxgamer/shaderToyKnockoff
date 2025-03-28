#pragma once

#include <glad/glad.h>

#include "glm/ext/quaternion_common.hpp"
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


enum class Camera_Movement
{
 FORWARD,
 BACKWARD,
 LEFT,
 RIGHT
};

// Default camera values
const float SPEED = 0.01f;
const float SENSITIVITY = 0.0001f;
const float ZOOM = 45.0f;

class chanCamera
{
public:
 glm::vec3 Position;
 glm::quat Orientation;
 float RightAngle;
 float UpAngle;

 // Camera options
 float MovementSpeed;
 float MouseSensitivity;
 float Zoom;

 chanCamera
 (
  glm::vec3 position = glm::vec3(0.f, 0.f, 0.f),
  glm::vec3 up = glm::vec3(0.f, 1.0f, 0.f)
 );
 chanCamera(float posX, float posY, float posZ);

 glm::mat4 GetViewMatrix();
 void ProcessKeyboard(Camera_Movement direction, float deltaTime);
 void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
 void ProcessMouseScroll(float yoffset);

private:
 void updateCameraVectors();
};
