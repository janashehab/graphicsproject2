#pragma once

#include <glm/glm.hpp>

#include <string>

// TODO (Member B): compile and link the two GLSL source strings, then upload uniforms.
// Labs 3, 4, and 5 pass embedded C++ strings. They do not read shader files.
// Lab 5 shader.h is the interface to follow.
// Write shaders as #version 330 core. The lab files say 430. The inspected lighting
// and model shaders use no feature past GLSL 330 besides that version line.

class Shader {
public:
    unsigned int ID = 0;

    Shader(const char* vertexCode, const char* fragmentCode);
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec3(const std::string& name, float x, float y, float z) const;
    void setMat4(const std::string& name, const glm::mat4& value) const;
};
