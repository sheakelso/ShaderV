#include "sceneobject.h"

SceneObject::SceneObject(QString name)
{
    m_name = name;
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
}

SceneObject *SceneObject::get_parent()
{
    return m_parent;
}

QVector<SceneObject *> *SceneObject::get_children()
{
    return &m_children;
}
