#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QString>
#include <QVector>
#include <QTreeWidgetItem>

#include "event.h"

class SceneObject
{
public:
    SceneObject(QString name);
    QTreeWidgetItem *to_tree_item();
    void add_child(SceneObject *child);
    SceneObject *get_parent();
    QVector<SceneObject *> *get_children();
    Event<SceneObject *> on_child_added;

private:
    QString m_name = "Object";
    SceneObject *m_parent = nullptr;
    QVector<SceneObject *> m_children;
};

#endif // SCENEOBJECT_H
