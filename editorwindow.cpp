#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>

EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    Scene *scene = new Scene;

    hierarchy = new HierarchyWidget(this);
    hierarchy->setDockLocation(Qt::LeftDockWidgetArea);
    hierarchy->set_scene(scene);

    viewport = new ViewportWidget(this);
    setCentralWidget(viewport);
    viewport->set_scene(scene);

    this->showMaximized();
}

EditorWindow::~EditorWindow()
{
    delete ui;
}
