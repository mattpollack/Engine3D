#ifndef _SCENE_H
#define _SCENE_H

#include "SceneManager.h"

class Scene {
private:
public:
    virtual void enter() = 0;
    virtual void update() = 0;

    // TODO, pass renderer when implemented
    virtual void draw() = 0;
    virtual void exit() = 0;
};

#endif
