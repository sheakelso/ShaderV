#include "scene.h"

Scene::Scene()
{
    m_root = new SceneObject("Root");
}

SceneObject *Scene::get_root()
{
    return m_root;
}
