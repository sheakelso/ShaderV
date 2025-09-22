#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include "viewportwidget.h"
#include "hierarchywidget.h"

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = nullptr);
    ~EditorWindow();

private:
    Ui::EditorWindow *ui;
    ViewportWidget *viewport;
    HierarchyWidget *hierarchy;
};

#endif // EDITORWINDOW_H
