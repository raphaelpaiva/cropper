#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    setCentralWidget(scrollArea);
    setWindowTitle(tr("Cropper Result"));

    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(QImage image)
{
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->adjustSize();
}
