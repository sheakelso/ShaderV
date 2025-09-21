#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <stdio.h>
#include <fstream>
#include <sstream>

#include <QWidget>
#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

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
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLShaderProgram m_program;

protected:
    void initializeGL() override
    {
        initializeOpenGLFunctions();

        m_vao.create();
        m_vao.bind();

        static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        };

        m_vbo.create();
        m_vbo.bind();
        m_vbo.allocate(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

        m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, "://res/shader/shader.vsh");
        m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, "://res/shader/shader.frag");
        m_program.link();
    }

    void resizeGL(int w, int h) override
    {
        m_projection.setToIdentity();
        m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
    }

    void paintGL() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        m_vbo.bind();
        m_program.bind();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }
};

#endif // VIEWPORTWIDGET_H
