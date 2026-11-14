#include "Ground.h"

// Model-loading lab, Template/main.cpp lines 116–123:
//   glm::mat4 model = glm::mat4(1.0f);
//   model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//   model = glm::scale(model, glm::vec3(1.0f));
//   ourShader.setMat4("model", model);
//   ourModel.Draw(ourShader);
//
// Ground does not reconstruct that matrix. The caller supplies it.
// The caller must activate the shader before drawing. Ground does not
// call Shader::use or applyLights.

Ground::Ground(const std::string& path)
    : floorModel(path)
{
}

void Ground::draw(Shader& shader, const glm::mat4& model)
{
    // Upload, then draw. Same order as Template/main.cpp lines 120–123.
    shader.setMat4("model", model);
    floorModel.draw(shader);
}
