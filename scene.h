#include "sceneobject.h"

#ifndef SCENE_H
#define SCENE_H
#include "event.h"

class Scene
{
public:
    Scene();
    SceneObject* get_root();
    Event<SceneObject *> on_object_added_event;

private:
    SceneObject* m_root;
};

#endif // SCENE_H
