#ifndef HIERARCHYWIDGET_H
#define HIERARCHYWIDGET_H

#include <QDockWidget>
#include <QTreeWidget>

#include "scene.h"

class HierarchyWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit HierarchyWidget(QWidget *parent = nullptr);
    ~HierarchyWidget();

    void set_scene(Scene* scene);

private:
    QTreeWidget *m_tree;
    Scene *m_scene;
};

#endif // HIERARCHYWIDGET_H
