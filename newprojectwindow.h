#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class NewProjectWindow;
}

class NewProjectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewProjectWindow(QWidget *parent = nullptr);
    ~NewProjectWindow();

private slots:

    void on_buttonBox_rejected();

    void on_pushButton_released();

    void on_directoryField_textChanged(const QString &arg1);

    void on_nameField_textChanged(const QString &arg1);

    void check_name();

    void update_name_indicator();

    void update_directory_indicator();


private:
    Ui::NewProjectWindow *ui;
    QLineEdit *directory_field;
    QLineEdit *name_field;
    QLabel *directory_indicator;
    QLabel *name_indicator;
    QPixmap check_pixmap;
    QPixmap close_pixmap;
    bool name_valid;
    bool directory_valid;
};

#endif // NEWPROJECTWINDOW_H
