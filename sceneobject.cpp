#include "sceneobject.h"
#include "scene.h"

SceneObject::SceneObject(QString name)
{
    m_name = name;
}

SceneObject::SceneObject(Scene *_scene, QString name)
{
    m_name = name;
    scene = _scene;
}

QTreeWidgetItem *SceneObject::to_tree_item()
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, m_name);
    return item;
}

void SceneObject::add_child(SceneObject *child)
{
    m_children.append(child);
    child->m_parent = this;
    on_child_added.trigger(child);

    if(scene != nullptr)
    {
        child->scene = scene;
        scene->on_object_added_event.trigger(child);
    }
}

SceneObject *SceneObject::get_parent()
{
    return m_parent;
}

QVector<SceneObject *> *SceneObject::get_children()
{
    return &m_children;
}
