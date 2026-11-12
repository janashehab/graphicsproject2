#include "Camera.h"

// TODO (Member A): Lab 5 computes Front, Right, and Up in updateCameraVectors.
// Those three vectors are not initialized here, so they are not usable for movement yet.

Camera::Camera(glm::vec3 position, float yaw, float pitch)
    : Position(position), WorldUp(0.0f, 1.0f, 0.0f), Yaw(yaw), Pitch(pitch) {
}

glm::mat4 Camera::GetViewMatrix() const {
    return {};
}

void Camera::ProcessKeyboard(Camera_Movement, float) {
}

void Camera::ProcessMouseMovement(float, float) {
}

void Camera::ProcessMouseScroll(float) {
}
