
#include "hierarchywidget.h"
#include <QMenu>
#include <QContextMenuEvent>

HierarchyWidget::HierarchyWidget(QWidget *parent)
    : QDockWidget(parent)
{
    setWindowTitle("Hierarchy");
    m_tree = new QTreeWidget(this);
    setWidget(m_tree);
    m_tree->setHeaderHidden(true);
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
    HierarchyTreeItem *item_parent = m_object_map[parent];
    HierarchyTreeItem *item = object->to_tree_item();

    if(object->get_parent() == nullptr)
    {
        m_object_map[object] = item;
        m_tree->addTopLevelItem(item);
    }
    else
    {
        if(item_parent != nullptr)
        {
            m_object_map[object] = item;
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
    HierarchyTreeItem *item = m_object_map[object];
    QVector<SceneObject *> *children = object->get_children();
    for(int i = 0; i < children->count(); i++)
    {
        SceneObject *child = children->at(i);
        HierarchyTreeItem *child_item = child->to_tree_item();
        m_object_map[child] = child_item;
        item->addChild(child_item);
        add_children(child);
    }
}

void HierarchyWidget::contextMenuEvent(QContextMenuEvent *event)
{
    m_clicked_item = dynamic_cast<HierarchyTreeItem *>(m_tree->itemAt(m_tree->mapFromGlobal(event->globalPos())));
    if(m_clicked_item == nullptr) return;
    qInfo() << m_clicked_item->text(0);

    QMenu menu;
    QAction *action = menu.addAction("Add Object");
    connect(action, &QAction::triggered, this, &HierarchyWidget::action_clicked);
    menu.exec(event->globalPos());
}

void HierarchyWidget::action_clicked()
{
    SceneObject *obj = m_object_map.key(m_clicked_item);
    if(obj == nullptr) return;
    obj->add_child(new SceneObject("HOORAYYY"));
}
