#include "Texture.h"
#include <glad/glad.h>
#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int TextureFromFile(const char* path, const std::string& directory) {
    std::string filename = directory + '/' + std::string(path);

    int width=0; int height=0;
    int nrComponents = 0;//num of color channelss
    //read image from disk
    unsigned char* data =stbi_load(filename.c_str(),&width,&height,&nrComponents,0);
    if (!data) {
        std::cout << "Texture failed to load at path: " << filename << std::endl;
        return 0;}

    unsigned int format = 0;
    if (nrComponents == 1) {
        format = GL_RED;} else if (nrComponents == 3) {
        format = GL_RGB;} else if (nrComponents == 4) {
        format = GL_RGBA;} else {
        std::cout << "Texture failed to load at path: " << filename
                  << " (unsupported channel count " << nrComponents << ")" << std::endl;
        stbi_image_free(data);
        return 0;
    }
    unsigned int textureID = 0;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    //upload image lel gpu
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    //create prog smaller versions of texture
    glGenerateMipmap(GL_TEXTURE_2D);
//repeat the image if its texture coordinates go beyond the normal range
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//free mem
    stbi_image_free(data);
    return textureID;
}
