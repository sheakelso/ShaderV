#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "newprojectwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    NewProjectWindow *new_project_window = new NewProjectWindow(this);
    new_project_window->show();
}

