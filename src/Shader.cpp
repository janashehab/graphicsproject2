#include "Shader.h"
#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
//c++(cpu) bystakhdem shader.use() w shader.setFloat("brightness",0.8f)
//hatb3at el value as uniform variable
//GLSL(gpu) bystakhdem 0.8 to calc lightening
//vertex shader:vertecies pos
//fragmant shader: color of each pixel
//shader program: combines vertex and fragment shader
Shader::Shader(const char* vertexCode, const char* fragmentCode) {
    // hatgebly el shader id
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, nullptr);

    // compile vertex shader code
    // the code may contain mistake, opengl msh hay3raf ycompile
    glCompileShader(vertex);
    // msh bt print errors auto fa use check compile errors
    checkCompileErrors(vertex, "VERTEX");
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    //create program
    //msh automatically activated->mehtageen glUseProgram
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);

    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    // awel mal shaders t link lelprogram, seperate objects msh mehtagahom
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

//elhelper
void Shader::checkCompileErrors(unsigned int shader, std::string type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        //hashoof law el shader compiled
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR::shader_comp_error:" << infoLog << "\n" << type << std::endl;}}
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR::program_link_error:" << infoLog << "\n" << type << std::endl;}}}
void Shader::use() const {
    //activate linked program
    glUseProgram(ID);}

void Shader::setBool(const std::string& name, bool value) const {
    //name of uniform variable
    //value-true or false
    //loc-find variable insie program
    //send value to processor as 0 or 1
    glUniform1i(glGetUniformLocation(ID, name.c_str()),(int)value);}

void Shader::setInt(const std::string& name, int value) const {
    //no conversion needed aashan value aslun int
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);}
//send 3 nums together lel shader
void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
    //1=>sending one vector
    //&value[0]->pointer to first component
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);}
//send 3 seperate floats
void Shader::setVec3(const std::string& name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);}
//sed trans matrix lel shader
//control where object appear,dierction,size
void Shader::setMat4(const std::string& name, const glm::mat4& value) const {
    //1=sending one 4x4 matrix
    //false=dont transpose
    //pointer to matrix data
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));}
