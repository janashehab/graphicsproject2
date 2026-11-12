#pragma once

#include "Interactable.h"
#include "Lights.h"

#include <glm/glm.hpp>

#include <vector>

// Shared scene contract.
// Member C implements Scene1. Member D implements Scene2.
// The scene that inserts an Interactable* owns that object and deletes it in
// its own destructor. ~Scene() does not delete interactables. Nothing in this
// skeleton allocates or deletes them.

struct Bounds {
    float minX;
    float maxX;
    float minZ;
    float maxZ;
};

class Scene {
public:
    std::vector<Interactable*> interactables;

    virtual ~Scene() = default;

    virtual void load() = 0;
    virtual void update(float dt, float time, bool horror) = 0;
    virtual void draw(Shader& shader) = 0;
    virtual Bounds bounds() = 0;
    virtual LightSetup lights() = 0;
    virtual glm::vec3 spawnPoint() = 0;
    virtual glm::vec3 sceneCenter() = 0;
    virtual float sceneSize() = 0;
};
