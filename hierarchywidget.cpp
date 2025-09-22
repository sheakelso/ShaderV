#include "hierarchywidget.h"

HierarchyWidget::HierarchyWidget(QWidget *parent)
    : QDockWidget(parent)
{
    setWindowTitle("Hierarchy");
    m_tree = new QTreeWidget(this);
    setWidget(m_tree);
    m_tree->setColumnCount(1);
    QTreeWidgetItem *item = new QTreeWidgetItem(QTreeWidgetItem::Type);
    m_tree->addTopLevelItem(item);
    item->addChild(new QTreeWidgetItem(item));
    m_tree->addTopLevelItem(new QTreeWidgetItem(QTreeWidgetItem::Type));
}

HierarchyWidget::~HierarchyWidget()
{

}

void HierarchyWidget::set_scene(Scene* scene)
{
    m_scene = scene;
    m_tree->clear();

    m_tree->addTopLevelItem(scene->get_root()->to_tree_item());
}
