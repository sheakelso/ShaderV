
#include "hierarchywidget.h"
#include <QMenu>
#include <QContextMenuEvent>

HierarchyWidget::HierarchyWidget(QWidget *parent)
    : QDockWidget(parent)
{
    setWindowTitle("Hierarchy");
    m_tree = new QTreeWidget(this);
    setWidget(m_tree);
}

HierarchyWidget::~HierarchyWidget()
{

}

void HierarchyWidget::set_scene(Scene* scene)
{
    m_scene = scene;
    m_tree->clear();

    scene->on_object_added_event.bind([this](SceneObject *obj){this->add_object(obj);});
    add_object(scene->get_root());
}

void HierarchyWidget::add_object(SceneObject *object)
{
    qInfo() << "adding object";
    SceneObject *parent = object->get_parent();
    QTreeWidgetItem *item_parent = m_object_map[parent];
    QTreeWidgetItem *item = object->to_tree_item();

    if(object->get_parent() == nullptr)
    {
        m_object_map[object] = item;
        m_tree->addTopLevelItem(item);
    }
    else
    {
        if(item_parent != nullptr)
        {
            item_parent->addChild(item);
        }
        else
        {
            add_object(parent);
            return;
        }
    }

    add_children(object);
}

void HierarchyWidget::add_children(SceneObject *object)
{
    QTreeWidgetItem *item = m_object_map[object];
    QVector<SceneObject *> *children = object->get_children();
    for(int i = 0; i < children->count(); i++)
    {
        SceneObject *child = children->at(i);
        QTreeWidgetItem *child_item = child->to_tree_item();
        m_object_map[child] = child_item;
        item->addChild(child_item);
        add_children(child);
    }
}

void HierarchyWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    QAction *action = menu.addAction("Add Object");
    connect(action, &QAction::triggered, this, &HierarchyWidget::action_clicked);
    menu.exec(event->globalPos());
}

void HierarchyWidget::action_clicked()
{
    m_scene->get_root()->add_child(new SceneObject("Work please"));
}
