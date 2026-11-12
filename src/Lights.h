#pragma once

#include "Shader.h"

#include <glm/glm.hpp>

// TODO (Member B): directional, point, and spot lights, plus horror lighting.
// Consult the supplied DMET 502 materials on lighting.

struct LightSetup {
    glm::vec3 dirDir;
    glm::vec3 dirColor;
    glm::vec3 pointPos;
    glm::vec3 pointColor;
    glm::vec3 spotPos;
    glm::vec3 spotDir;
    glm::vec3 spotColor;
    float spotCutoff;
    float spotOuter;
};

void applyLights(Shader& shader, const LightSetup& lights, float time, bool horror);
