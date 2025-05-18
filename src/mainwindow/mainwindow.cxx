#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto agent = new QWK::WidgetWindowAgent(this);
    agent->setup(this);

    centralWidget->setObjectName("central_widget");
    this->setCentralWidget(centralWidget);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    centralWidget->setLayout(mainLayout);

    titleBar->setObjectName("title_bar");
    mainLayout->addWidget(titleBar);
    agent->setTitleBar(titleBar);

    auto * titleBarLayout = new QHBoxLayout;
    titleBarLayout->setContentsMargins(8, 8, 8, 8);
    titleBarLayout->setSpacing(8);
    titleBar->setLayout(titleBarLayout);

    auto * titleBarSpacer = new QSpacerItem(32, 32, QSizePolicy::Expanding, QSizePolicy::Expanding);
    titleBarLayout->addSpacerItem(titleBarSpacer);

    minimizeBtn->setObjectName("minimize_btn");
    connect(minimizeBtn, SIGNAL(clicked(bool)), this, SLOT(minimizeWindow()));
    titleBarLayout->addWidget(minimizeBtn);
    agent->setSystemButton(QWK::WindowAgentBase::Minimize, minimizeBtn);

    maximizeBtn->setObjectName("maximize_btn");
    connect(maximizeBtn, SIGNAL(clicked(bool)), this, SLOT(toggleMaximizeWindow()));
    titleBarLayout->addWidget(maximizeBtn);
    agent->setSystemButton(QWK::WindowAgentBase::Maximize, maximizeBtn);

    closeBtn->setObjectName("close_btn");
    connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
    titleBarLayout->addWidget(closeBtn);
    agent->setSystemButton(QWK::WindowAgentBase::Close, closeBtn);

    auto * contentContainer = new QWidget(centralWidget);
    mainLayout->addWidget(contentContainer);

    this->setWindowTitle("Husky Markdown");
    this->resize(800, 600);
    this->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light.css"));
    centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
}

void MainWindow::minimizeWindow() {
    this->showMinimized();
}

void MainWindow::toggleMaximizeWindow() {
    if (this->isMaximized()) {
        centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
        showNormal();
    }

    else {
        centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_maximize.css"));
        showMaximized();
    }
}

void MainWindow::closeWindow() {
    this->close();
}