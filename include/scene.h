#ifndef SCENE_H
#define SCENE_H

#include "scene_manager.h"

class SCENE_MANAGER; // forward declaration

class SCENE
{
protected:
    SCENE_MANAGER *manager;
public:
    SCENE(SCENE_MANAGER *m) : manager(m){}
    virtual void draw() = 0;
    virtual void update() = 0;
};

#endif