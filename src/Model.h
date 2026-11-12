#pragma once

#include "Shader.h"

#include <string>

// TODO (Member B): load a model from disk and draw it.
// Consult the supplied DMET 502 materials on model loading.

class Model {
public:
    explicit Model(const std::string& path);
    void draw(Shader& shader);
};
