#include "viewportwidget.h"
#include "ui_viewportwidget.h"

ViewportWidget::ViewportWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::ViewportWidget)
{
    ui->setupUi(this);
}

ViewportWidget::~ViewportWidget()
{
    delete ui;
}

void ViewportWidget::set_scene(Scene *scene)
{
    m_scene = scene;
}
