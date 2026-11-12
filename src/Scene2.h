#pragma once

#include "Scene.h"

// TODO (Member D): second room, imported models, interactive objects, and animations.
// Consult the supplied DMET 502 materials on scene content and object animation.

class Scene2 : public Scene {
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
