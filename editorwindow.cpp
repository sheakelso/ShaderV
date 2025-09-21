#include "editorwindow.h"
#include "ui_editorwindow.h"
#include <QtOpenGLWidgets/QOpenGLWidget>

EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    viewport = new ViewportWidget(this);
    setCentralWidget(viewport);
}

EditorWindow::~EditorWindow()
{
    delete ui;
}
