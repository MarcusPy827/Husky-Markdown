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

    fileBtn->setObjectName("file_btn");
    fileBtn->setText(tr("(F)ile"));
    fileBtn->setShortcut(QKeySequence("Alt+F"));
    agent->setHitTestVisible(fileBtn, true);
    titleBarLayout->addWidget(fileBtn);

    helpBtn->setObjectName("help_btn");
    helpBtn->setText(tr("(H)elp"));
    helpBtn->setShortcut(QKeySequence("Alt+H"));
    agent->setHitTestVisible(helpBtn, true);
    titleBarLayout->addWidget(helpBtn);

    auto * titleBarSpacer0 = new QSpacerItem(32, 32, QSizePolicy::Expanding, QSizePolicy::Expanding);
    titleBarLayout->addSpacerItem(titleBarSpacer0);

    appTitle->setObjectName("app_title");
    appTitle->setText("Husky Markdown");
    titleBarLayout->addWidget(appTitle, 0, Qt::AlignVCenter);

    auto * titleBarSpacer1 = new QSpacerItem(32, 32, QSizePolicy::Expanding, QSizePolicy::Expanding);
    titleBarLayout->addSpacerItem(titleBarSpacer1);

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

    auto * contentLayout = new QHBoxLayout;
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);
    contentContainer->setLayout(contentLayout);

    navigationRail->setObjectName("navigation_rail");
    contentLayout->addWidget(navigationRail);

    auto * navigationRailLayout = new QVBoxLayout;
    navigationRailLayout->setContentsMargins(20, 20, 20, 20);
    navigationRailLayout->setSpacing(4);
    navigationRail->setLayout(navigationRailLayout);

    fab->setObjectName("fab");
    navigationRailLayout->addWidget(fab, 0, Qt::AlignTop);

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowTitle("Husky Markdown");
    this->resize(800, 600);
    this->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light.css"));
    centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
}

void MainWindow::minimizeWindow() {
    this->showMinimized();
}

void MainWindow::toggleMaximizeWindow() {
    if (this->isMaximized()) showNormal();
    else showMaximized();
}

void MainWindow::closeWindow() {
    this->close();
}

void MainWindow::changeEvent(QEvent *event) {
    if (event->type() == QEvent::WindowStateChange) {
        if(isMaximized()) centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_maximize.css"));
        else centralWidget->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_central_widget_normal.css"));
    }

    QMainWindow::changeEvent(event);
}