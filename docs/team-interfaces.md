# Shared interfaces

These are the approved contracts. Method signatures stay as written here.

`Scene` stores `std::vector<Interactable*>`. The scene that inserts a pointer owns that object and deletes it in its destructor. `~Scene()` does not delete them. This skeleton allocates and deletes none.

`Scene::~Scene` is virtual so a derived scene can be destroyed through a `Scene*`.

GLM types come from GLM 1.0.1. Fetching GLM with CMake FetchContent is **EXTERNAL — NOT VERIFIED IN LABS**. See `README.md`.

`Shader` follows Lab 5 `shader.h`. The constructor receives two GLSL source strings embedded in C++, matching Labs 3, 4, and 5. It does not read `.vert` or `.frag` files. The method bodies in this skeleton are empty.

The common target is OpenGL 3.3 core and `#version 330 core`. Labs 3, 4, and 5 request OpenGL 4.3 and `#version 430 core`. The inspected Lab 5 lighting shaders and the model-lab shaders use `layout(location)` on vertex inputs, structs, samplers, and `texture()`. Those are valid in GLSL 330. They do not use explicit uniform locations, storage blocks, or compute shaders. Only the version line has to change when those shaders are brought into this project.

`LightSetup` fields stay as written. `applyLights` is empty. The Lab 5 names are `dirLight.direction`, `pointLights[0].position`, `spotLight.position`, and `spotLight.direction`. `spotCutoff` and `spotOuter` are degrees. The lab shader stores cosines, and `5_3_light_casters_spot.cpp` converts degrees with `cos(radians(...))` before upload. How `dirColor`, `pointColor`, and `spotColor` split into the lab's separate ambient, diffuse, and specular colors is unresolved. Do not invent intensity multipliers or attenuation values for that split.

E is reserved for interaction. The Lab 5 camera has no vertical movement. Lab 4's use of E to move up is not part of this interface. `Camera::Front`, `Right`, and `Up` are not initialized for movement until `updateCameraVectors` is implemented.

```cpp
struct Bounds {
    float minX;
    float maxX;
    float minZ;
    float maxZ;
};

struct LightSetup {
    glm::vec3 dirDir;
    glm::vec3 dirColor;
    glm::vec3 pointPos;
    glm::vec3 pointColor;
    glm::vec3 spotPos;
    glm::vec3 spotDir;
    glm::vec3 spotColor;
    float spotCutoff;
    float spotOuter;
};

void applyLights(Shader& shader, const LightSetup& lights, float time, bool horror);

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

class Model {
public:
    explicit Model(const std::string& path);
    void draw(Shader& shader);
};

class Interactable {
public:
    glm::vec3 position;
    float range;
    float maxAngleDeg;
    glm::vec3 camPos;
    glm::vec3 camTarget;
    float duration;

    virtual void animate(float t) = 0;
    virtual void reset() = 0;
    virtual void horrorIdle(float time) {}
    virtual void draw(Shader& shader) = 0;
    virtual ~Interactable() = default;
};

class Scene {
public:
    std::vector<Interactable*> interactables;

    virtual ~Scene() = default;

    virtual void load() = 0;
    virtual void update(float dt, float time, bool horror) = 0;
    virtual void draw(Shader& shader) = 0;
    virtual Bounds bounds() = 0;
    virtual LightSetup lights() = 0;
    virtual glm::vec3 spawnPoint() = 0;
    virtual glm::vec3 sceneCenter() = 0;
    virtual float sceneSize() = 0;
};
```
