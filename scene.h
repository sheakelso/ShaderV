#ifndef SCENE_H
#define SCENE_H

#include "sceneobject.h"

class Scene
{
public:
    Scene();
    SceneObject* get_root();

private:
    SceneObject* m_root;
};

#endif // SCENE_H
