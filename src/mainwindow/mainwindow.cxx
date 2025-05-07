#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget->setObjectName("central_widget");
    this->setCentralWidget(centralWidget);

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
    connect(minimizeBtn, SIGNAL(clicked(bool)), this, SLOT(minimizeWindow()));
    titleBarLayout->addWidget(minimizeBtn);

    maximizeBtn->setObjectName("maximize_btn");
    connect(maximizeBtn, SIGNAL(clicked(bool)), this, SLOT(toggleMaximizeWindow()));
    titleBarLayout->addWidget(maximizeBtn);

    closeBtn->setObjectName("close_btn");
    connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
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

void MainWindow::minimizeWindow() {
    this->showMinimized();
}

void MainWindow::toggleMaximizeWindow() {
    if (this->isMaximized()) {
        centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
        mainLayout->setContentsMargins(16, 16, 16, 16);
        showNormal();
    }

    else {
        centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_maximize.css"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        showMaximized();
    }
}

void MainWindow::closeWindow() {
    this->close();
}