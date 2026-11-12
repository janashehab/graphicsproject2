#pragma once

#include <glm/glm.hpp>

#include <string>

// TODO (Member B): shader program and uniform uploads.
// Consult the supplied DMET 502 materials on shader programs and uniforms.

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    void setMat4(const std::string& name, const glm::mat4& value);
    void setVec3(const std::string& name, const glm::vec3& value);
    void setFloat(const std::string& name, float value);
    void setInt(const std::string& name, int value);
};
