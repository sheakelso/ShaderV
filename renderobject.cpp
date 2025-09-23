#include "renderobject.h"
#include "scene.h"

RenderObject::RenderObject(QString name) : SceneObject(name)
{

}

RenderObject::RenderObject(Scene *scene, QString name) : SceneObject(scene, name)
{

}
