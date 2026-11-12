#pragma once

#include <string>

// Texture record from the model-loading lab, Template/mesh.h.
// TextureFromFile loads an image file from disk into an OpenGL texture.

struct Texture {
    unsigned int id;
    std::string type; // "texture_diffuse" or "texture_specular"
    std::string path;
};

unsigned int TextureFromFile(const char* path, const std::string& directory);
