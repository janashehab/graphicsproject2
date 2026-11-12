#include "Shader.h"

// TODO (Member B): compile and link vertexCode and fragmentCode, then implement the setters.
// Both pointers are GLSL source strings supplied by the caller, as in Lab 5 shader.h.
// This file does not read shader files.

Shader::Shader(const char*, const char*) {
}

void Shader::use() const {
}

void Shader::setBool(const std::string&, bool) const {
}

void Shader::setInt(const std::string&, int) const {
}

void Shader::setFloat(const std::string&, float) const {
}

void Shader::setVec3(const std::string&, const glm::vec3&) const {
}

void Shader::setVec3(const std::string&, float, float, float) const {
}

void Shader::setMat4(const std::string&, const glm::mat4&) const {
}
