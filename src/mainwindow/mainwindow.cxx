#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    framelessPatcher->patch(this);

    auto * centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background: #FFF; margin: 16px");

    auto * mainLayout = new QHBoxLayout(centralWidget);
    centralWidget->setLayout(mainLayout);

    titleBar->setParent(centralWidget);
    titleBar->setStyleSheet("background: #CCC");
    mainLayout->addWidget(titleBar);
}

MainWindow::~MainWindow() {
    delete framelessPatcher;
}
