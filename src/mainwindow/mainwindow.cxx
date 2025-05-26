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
    contentLayout->addWidget(navigationRail, 0, Qt::AlignLeft);

    auto * navigationRailLayout = new QVBoxLayout;
    navigationRailLayout->setContentsMargins(20, 20, 20, 32);
    navigationRailLayout->setSpacing(4);
    navigationRail->setLayout(navigationRailLayout);

    fab->setObjectName("fab");
    fab->setIconSize(QSize(24, 24));
    navigationRailLayout->addWidget(fab, 0, Qt::AlignTop);

    auto * notesBtnLayout = new QVBoxLayout;
    notesBtnLayout->setContentsMargins(0, 0, 0, 0);
    notesBtnLayout->setSpacing(8);
    navigationRailLayout->addLayout(notesBtnLayout, 0);

    notesBtn->setObjectName("notes_btn");
    notesBtn->setIcon(QIcon(":/icons/icons/notes_icon_active_material_blue_light.svg"));
    notesBtn->setIconSize(QSize(24, 24));
    notesBtn->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_active.css"));
    notesBtnLayout->addWidget(notesBtn);

    notesDesc->setObjectName("notes_desc");
    notesDesc->setText(tr("My Notes"));
    notesDesc->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_label_active.css"));
    notesBtnLayout->addWidget(notesDesc, 0, Qt::AlignCenter);

    auto * searchBtnLayout = new QVBoxLayout;
    searchBtnLayout->setContentsMargins(0, 2, 0, 0);
    searchBtnLayout->setSpacing(8);
    navigationRailLayout->addLayout(searchBtnLayout);

    searchBtn->setObjectName("search_btn");
    searchBtn->setIcon(QIcon(":/icons/icons/search_icon_material_blue_light.svg"));
    searchBtn->setIconSize(QSize(24, 24));
    searchBtn->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_normal.css"));
    searchBtnLayout->addWidget(searchBtn);

    searchDesc->setObjectName("search_desc");
    searchDesc->setText(tr("Search"));
    searchDesc->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_label_normal.css"));
    searchBtnLayout->addWidget(searchDesc);

    auto * settingsBtnLayout = new QVBoxLayout;
    settingsBtnLayout->setContentsMargins(0, 2, 0, 0);
    settingsBtnLayout->setSpacing(8);
    navigationRailLayout->addLayout(settingsBtnLayout);

    settingsBtn->setObjectName("settings_btn");
    settingsBtn->setIcon(QIcon(":/icons/icons/settings_icon_active_material_blue_light.svg"));
    settingsBtn->setIconSize(QSize(24, 24));
    settingsBtn->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_normal.css"));
    settingsBtnLayout->addWidget(settingsBtn);

    settingsDesc->setObjectName("settings_desc");
    settingsDesc->setText(tr("Settings"));
    settingsDesc->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light_navigation_rail_btn_label_normal.css"));
    settingsBtnLayout->addWidget(settingsDesc);

    auto * navigationRailSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    navigationRailLayout->addSpacerItem(navigationRailSpacer);

    avatarView->setObjectName("avatar_view");
    avatarView->setIcon(QIcon(":/icons/icons/default_avatar_material_blue_light.svg"));
    avatarView->setIconSize(QSize(32, 32));
    navigationRailLayout->addWidget(avatarView, 0, Qt::AlignHCenter);

    auto * activityLayout = new QVBoxLayout;
    activityLayout->setContentsMargins(0, 0, 2, 2);
    activityLayout->setSpacing(0);
    contentLayout->addLayout(activityLayout);

    header->setObjectName("header");
    header->insertWidget(0, searchBar);
    header->setCurrentIndex(0);
    header->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    activityLayout->addWidget(header, 0, Qt::AlignTop);

    pageContainer->setObjectName("page_container");
    pageContainer->insertWidget(0, webView);
    pageContainer->setCurrentIndex(0);
    pageContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    activityLayout->addWidget(pageContainer);

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowTitle("Husky Markdown");
    this->resize(800, 600);
    this->setStyleSheet(ThemeLoader::FromFile(":/styles/styles/material_blue_light.css"));
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