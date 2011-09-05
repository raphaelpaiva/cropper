#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QScrollArea>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLabel *imageLabel;
    QScrollArea *scrollArea;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setImage(QImage image);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
