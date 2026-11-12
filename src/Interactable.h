#pragma once

#include "Shader.h"

#include <glm/glm.hpp>

// Shared interactable contract. Concrete objects are added by Members C and D.

class Interactable {
public:
    glm::vec3 position;
    float range;
    float maxAngleDeg;
    glm::vec3 camPos;
    glm::vec3 camTarget;
    float duration;

    virtual void animate(float t) = 0;
    virtual void reset() = 0;
    virtual void horrorIdle(float time) {}
    virtual void draw(Shader& shader) = 0;
    virtual ~Interactable() = default;
};
