#include "scene.h"

Scene::Scene()
{
    m_root = new SceneObject("Root");
    SceneObject *obj = new SceneObject("object1");
    m_root->add_child(obj);
    m_root->add_child(new SceneObject("object2"));
    obj->add_child(new SceneObject("object3"));
}

SceneObject *Scene::get_root()
{
    return m_root;
}
