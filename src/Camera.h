#pragma once

#include <glm/glm.hpp>

// Lab 5 camera.h is the starting interface for Member A.
// TODO (Member A): implement updateCameraVectors before using the camera to move or look.
// Front, Right, and Up are not initialized for functional camera movement until that
// function exists. This skeleton does not compute them.
// E is reserved for interaction. It is not a camera key, and this camera has no
// vertical movement. Lab 4's use of E to move up is not part of this interface.

enum Camera_Movement { FORWARD, BACKWARD, LEFT, RIGHT };

class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    float Yaw;
    float Pitch;
    float MovementSpeed = 2.5f;
    float MouseSensitivity = 0.1f;
    float Zoom = 45.0f;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f), float yaw = -90.0f, float pitch = 0.0f);
    glm::mat4 GetViewMatrix() const;
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset);
    void ProcessMouseScroll(float yoffset);
};
