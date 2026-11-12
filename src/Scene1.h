#pragma once

#include "Scene.h"

// TODO (Member C): first room, imported models, interactive objects, animations,
// scene bounds, and light positions.
// Consult the supplied DMET 502 materials on scene content and object animation.

class Scene1 : public Scene {
public:
    void load() override;
    void update(float dt, float time, bool horror) override;
    void draw(Shader& shader) override;
    Bounds bounds() override;
    LightSetup lights() override;
    glm::vec3 spawnPoint() override;
    glm::vec3 sceneCenter() override;
    float sceneSize() override;
};
