#pragma once

#include <string>

// Texture record from the model-loading lab, Template/mesh.h.
// TODO (Member B): fill id, type, and path when a texture is loaded.
// This skeleton does not load or bind images.

struct Texture {
    unsigned int id;
    std::string type; // "texture_diffuse" or "texture_specular"
    std::string path;
};
