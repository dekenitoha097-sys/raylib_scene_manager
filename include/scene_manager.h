#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <memory>

class SCENE; // forward declaration

class SCENE_MANAGER
{
private:
    std::unique_ptr<SCENE> current_scene;
public:
    ~SCENE_MANAGER() = default;
    void draw();
    void update();
    void set_scene(std::unique_ptr<SCENE> newScene);
};

#endif