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
