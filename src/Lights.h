#pragma once

#include "Shader.h"

#include <glm/glm.hpp>

extern const char* lightingVS;
extern const char* lightingFS;

// TODO (Member B): horror lighting is still pending.
// Consult Lab 5.
//
// Lab 5 uniform names, from 6_multiple_lights.cpp and 5_3_light_casters_spot.cpp:
//   dirDir    -> dirLight.direction
//   pointPos  -> pointLights[0].position
//   spotPos   -> spotLight.position
//   spotDir   -> spotLight.direction
// spotCutoff and spotOuter are degrees. The lab shader stores cosines.
// applyLights uploads cos(radians(degrees)) to spotLight.cutOff and
// spotLight.outerCutOff. 5_3_light_casters_spot.cpp converts 12.5 and 17.5
// degrees that way.
//
// dirColor, pointColor, and spotColor are each one vec3.
// Lab 5 stores ambient, diffuse, and specular separately for every light.
// applyLights scales each base color by the original 6_multiple_lights.cpp
// coefficient vectors:
//   directional: ambient 0.05, diffuse 0.4, specular 0.5
//   point:       ambient 0.05, diffuse 0.8, specular 1.0
//   spot:        ambient 0.0,  diffuse 1.0, specular 1.0
// Attenuation remains the lab constants 1.0, 0.09, and 0.032.

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
