#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

#include <assimp/scene.h>

#include <string>
#include <vector>

// Model: runs Assimp on a file (.obj, .fbx, .gltf, .dae, ...), walks the scene's node tree, and turns every piece of geometry it finds into a Mesh.
class Model {
public:
    explicit Model(const std::string& path);
    void draw(Shader& shader);

private:
    std::vector<Texture> textures_loaded; // cache: don't load the same file twice
    std::vector<Mesh>    meshes;
    std::string directory;

    void loadModel(const std::string& path);

    // Assimp stores geometry in a tree of nodes (for skeletal/hierarchical
    // transforms). We don't need the hierarchy for a static model, so this
    // just flattens it: collect every mesh from every node into one list.
    void processNode(aiNode* node, const aiScene* scene);

    // Converts one aiMesh (Assimp's format) into our own Vertex/index/Texture
    // vectors, which is what our Mesh class (and our VAO layout) expects.
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string& typeName);
};
