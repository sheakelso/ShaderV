#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QWidget>
#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QMatrix4x4>

namespace Ui {
class ViewportWidget;
}

class ViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit ViewportWidget(QWidget *parent = nullptr);
    ~ViewportWidget();

private:
    Ui::ViewportWidget *ui;
    QMatrix4x4 m_projection;

protected:
    void initializeGL() override
    {
        initializeOpenGLFunctions();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }

    void resizeGL(int w, int h) override
    {
        m_projection.setToIdentity();
        m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
    }

    void paintGL() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

#endif // VIEWPORTWIDGET_H
