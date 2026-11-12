# Shared interfaces

These are the approved contracts. Method signatures stay as written here.

`Scene` stores `std::vector<Interactable*>`. This skeleton does not allocate or delete those objects. The team plan does not say who owns them.

`Scene::~Scene` is virtual so a derived scene can be destroyed through a `Scene*`.

GLM types come from GLM 1.0.1. Fetching GLM with CMake FetchContent is **EXTERNAL — NOT VERIFIED IN LABS**. See `README.md`.

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
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    void setMat4(const std::string& name, const glm::mat4& value);
    void setVec3(const std::string& name, const glm::vec3& value);
    void setFloat(const std::string& name, float value);
    void setInt(const std::string& name, int value);
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
