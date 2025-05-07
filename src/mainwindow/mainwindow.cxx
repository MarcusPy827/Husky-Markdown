#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto * centralWidget = new QWidget(this);
    centralWidget->setObjectName("central_widget");
    this->setCentralWidget(centralWidget);

    auto * mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(16, 16, 16, 16);
    mainLayout->setSpacing(0);
    centralWidget->setLayout(mainLayout);

    titleBar->setObjectName("title_bar");
    mainLayout->addWidget(titleBar);

    auto * titleBarLayout = new QHBoxLayout;
    titleBarLayout->setContentsMargins(8, 8, 8, 8);
    titleBarLayout->setSpacing(8);
    titleBar->setLayout(titleBarLayout);

    auto * titleBarSpacer = new QSpacerItem(32, 32, QSizePolicy::Expanding, QSizePolicy::Expanding);
    titleBarLayout->addSpacerItem(titleBarSpacer);

    minimizeBtn->setObjectName("minimize_btn");
    titleBarLayout->addWidget(minimizeBtn);

    maximizeBtn->setObjectName("maximize_btn");
    titleBarLayout->addWidget(maximizeBtn);

    closeBtn->setObjectName("close_btn");
    titleBarLayout->addWidget(closeBtn);

    auto * contentContainer = new QWidget(centralWidget);
    mainLayout->addWidget(contentContainer);

    framelessPatcher->patch(this);
    this->setWindowTitle("Husky Markdown");
    this->resize(800, 600);
    this->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light.css"));
    centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
}

MainWindow::~MainWindow() {
    delete framelessPatcher;
}
