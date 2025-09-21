#include "newprojectwindow.h"
#include "ui_newprojectwindow.h"
#include <QFileDialog>
#include <filesystem>

NewProjectWindow::NewProjectWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewProjectWindow)
{
    ui->setupUi(this);

    directory_field = findChild<QLineEdit*>("directoryField");
    directory_indicator = findChild<QLabel*>("directoryIndicator");

    name_field = findChild<QLineEdit*>("nameField");
    name_indicator = findChild<QLabel*>("nameIndicator");

    check_pixmap = QPixmap("://res/img/check.png");
    close_pixmap = QPixmap("://res/img/close.png");
}

NewProjectWindow::~NewProjectWindow()
{
    delete ui;
}


void NewProjectWindow::on_buttonBox_rejected()
{
    close();
}


void NewProjectWindow::on_pushButton_released()
{
    QString directory = QFileDialog::getExistingDirectory();
    directory_field->setText(directory);
}


void NewProjectWindow::on_directoryField_textChanged(const QString &arg1)
{
    std::filesystem::path path{arg1.toStdString()};
    if(std::filesystem::exists(path))
    {
        directory_valid = true;
        update_directory_indicator();
        return;
    }
    else
    {
        directory_valid = false;
        update_directory_indicator();
        return;
    }
    check_name();
}

void NewProjectWindow::check_name()
{
    if(name_field->text().contains("/"))
    {
        name_valid = false;
        update_name_indicator();
        return;
    }

    QString project_directory = directory_field->text() + "/" + name_field->text();
    std::filesystem::path path{project_directory.toStdString()};
    if(std::filesystem::exists(path))
    {
        name_valid = false;
        update_name_indicator();
        return;
    }
    else
    {
        name_valid = true;
        update_name_indicator();
        return;
    }
}

void NewProjectWindow::on_nameField_textChanged(const QString &arg1)
{
    check_name();
}

void NewProjectWindow::update_name_indicator()
{
    if(name_valid) name_indicator->setPixmap(check_pixmap);
    else name_indicator->setPixmap(close_pixmap);
}

void NewProjectWindow::update_directory_indicator()
{
    if(directory_valid) directory_indicator->setPixmap(check_pixmap);
    else directory_indicator->setPixmap(close_pixmap);
}

