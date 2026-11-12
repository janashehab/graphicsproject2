# graphicsp2

Shared skeleton for DMET 502 Project 2 (3D world navigation). The CMake target is `Project2`. This tree is structural scaffolding: empty declarations, stub definitions, and build configuration. Graphics features are left for the assigned team members.

## Build

The first configure downloads GLM 1.0.1. Git and network access are required for that download. Later configures reuse the copy CMake stored under `build/`.

```bash
cmake -S . -B build
cmake --build build
./build/Project2
```

The executable starts and exits immediately. A multi-config generator places the binary under `build/Debug/` or `build/Release/` instead of `build/Project2`.

`build/` is gitignored. Do not commit it.

## GLM

GLM 1.0.1 is obtained with CMake FetchContent from <https://github.com/g-truc/glm.git> at tag `1.0.1`.

**EXTERNAL — NOT VERIFIED IN LABS.** FetchContent is an external build-configuration technique. It is not university lab material, and it is not a graphics implementation. The shared headers include `<glm/glm.hpp>` for `glm::vec3` and `glm::mat4`.

GLFW, GLAD, Assimp, stb_image, and audio libraries are not configured.

## Ownership

| Member | Files |
| --- | --- |
| A — core, player, camera | `src/main.cpp`, `Camera`, `Player`, `Input`, `HUD`, `assets/player/` |
| B — rendering and lighting | `Shader`, `Model`, `Texture`, `Lights`, `Ground` |
| C — scene 1 | `Scene1`, `scene1/`, `assets/scene1/` |
| D — scene 2 and audio | `Scene2`, `Audio`, `scene2/`, `assets/scene2/`, `assets/sounds/` |

`Interactable.h` and `Scene.h` are shared contracts. Signatures are recorded in `docs/team-interfaces.md`.

## Current behavior

`main` returns 0. Class methods are empty stubs.

`Shader` takes two embedded GLSL source strings, matching Lab 5. The project target is OpenGL 3.3 core and `#version 330 core`. The lab files request 4.3 and `#version 430 core`. The inspected lighting and model shaders need no GLSL feature past 330 besides that version line. E is reserved for interaction, not vertical camera movement.
