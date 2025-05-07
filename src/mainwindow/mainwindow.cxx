#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    FramelessPatcher::patch(this);
    auto * centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background: #FFF; margin: 16px");
}
