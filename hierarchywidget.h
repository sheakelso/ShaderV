#ifndef HIERARCHYWIDGET_H
#define HIERARCHYWIDGET_H

#include <QDockWidget>
#include <QTreeWidget>
#include <QMap>

#include "scene.h"

class HierarchyWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit HierarchyWidget(QWidget *parent = nullptr);
    ~HierarchyWidget();

    void set_scene(Scene *scene);

private:
    void add_object(SceneObject *object);
    void add_children(SceneObject *object);

    QTreeWidget *m_tree;
    Scene *m_scene;
    QMap<SceneObject *, QTreeWidgetItem *> m_object_map;
};

#endif // HIERARCHYWIDGET_H
