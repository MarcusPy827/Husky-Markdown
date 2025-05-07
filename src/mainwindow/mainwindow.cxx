#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    framelessPatcher->patch(this);

    auto * centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background: #FFF; margin: 16px");

    auto * mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    centralWidget->setLayout(mainLayout);

    titleBar->setParent(centralWidget);
    titleBar->setStyleSheet("min-height: 32px; max-height: 32px; background: #CCC");
    mainLayout->addWidget(titleBar);

    auto * contentContainer = new QWidget(centralWidget);
    mainLayout->addWidget(contentContainer);
}

MainWindow::~MainWindow() {
    delete framelessPatcher;
}
