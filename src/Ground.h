#pragma once

#include "Model.h"

// Ground is a project-specific wrapper around the original lab-based Model
// implementation (model-loading lab, Template/model.h and Template/main.cpp).
// It privately owns one Model. Loading, textures, and buffers stay inside Model.
//
// Ground does not store a transformation, dimensions, height, texture IDs,
// or scene boundaries. The caller supplies the model matrix when drawing.
//
// Construct Ground only after an OpenGL context exists and GLAD has been
// initialized. Model's constructor creates mesh buffers and textures.

class Ground {
public:
    explicit Ground(const std::string& path);
    void draw(Shader& shader, const glm::mat4& model);

private:
    Model floorModel;
};
