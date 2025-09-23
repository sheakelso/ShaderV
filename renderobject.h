#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "sceneobject.h"

class RenderObject : public SceneObject
{
public:
    RenderObject(QString name);
    RenderObject(Scene *scene, QString name);

private:

};

#endif // RENDEROBJECT_H
