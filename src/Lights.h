#pragma once

#include "Shader.h"

#include <glm/glm.hpp>

// TODO (Member B): directional, point, and spot lights, plus horror lighting.
// Consult Lab 5. applyLights is still empty.
//
// Lab 5 uniform names, from 6_multiple_lights.cpp and 5_3_light_casters_spot.cpp:
//   dirDir    -> dirLight.direction
//   pointPos  -> pointLights[0].position
//   spotPos   -> spotLight.position
//   spotDir   -> spotLight.direction
// spotCutoff and spotOuter are degrees. The lab shader stores cosines.
// applyLights must upload cos(radians(degrees)) to spotLight.cutOff and
// spotLight.outerCutOff. 5_3_light_casters_spot.cpp converts 12.5 and 17.5
// degrees that way.
//
// UNRESOLVED: dirColor, pointColor, and spotColor are each one vec3.
// Lab 5 stores ambient, diffuse, and specular separately for every light.
// Do not invent intensity multipliers or attenuation values for that split.

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
