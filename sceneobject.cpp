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
