#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>

EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    m_scene = new Scene;

    hierarchy = new HierarchyWidget(this);
    hierarchy->setDockLocation(Qt::LeftDockWidgetArea);
    hierarchy->set_scene(m_scene);

    viewport = new ViewportWidget(this);
    setCentralWidget(viewport);
    viewport->set_scene(m_scene);

    this->showMaximized();
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::on_actionAddObject_triggered()
{
    m_scene->get_root()->add_child(new SceneObject("New Object"));
}

