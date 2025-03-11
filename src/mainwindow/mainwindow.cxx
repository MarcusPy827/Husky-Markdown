#include "mainwindow.hxx"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    /* 初始化Webview
     * Initialize webview
     */
    webView.setPage(new QWebEnginePage(this));
    webView.setUrl(QUrl("qrc:/webview/webview/index.html"));
    webView.setStyleSheet("QMenu { color: #000000; background: #FFFFFF; border: 2px solid #3684DD; border-radius: 7px; padding: 7px; icon-size: 0px; } QMenu::item { color: #000000; background: #FFFFFF; padding: 7px; left: 0px; } QMenu::item:selected { color: #FFFFFF; background: #3684DD; border-radius: 7px; } QMenu::separator { height: 0px; background: transparent; margin: 0px; }");
    ui->mainLayout->addWidget(&webView);
    webView.show();

    /* 链接信号、槽
     * Connect signals and slots
     */
    QObject::connect(ui->action_open_note, &QAction::triggered, this, &MainWindow::openNote);
    QObject::connect(ui->action_open_folder, &QAction::triggered, this, &MainWindow::openFolder);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::getUserHomePath() {
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

MainWindow::noteType MainWindow::getNoteType(QString filename) {
    MainWindow::noteType result;

    QString extensionName = "";
    for(int i = filename.length() - 1; i >= 0; i--) {
        if(filename.at(i) == ".") {
            break;
        }

        else {
            extensionName.append(filename.at(i).toUpper());
        }
    }

    if(extensionName == "pdf") {
        result = MainWindow::noteType::PDF;
    }

    else if(extensionName == "md" || extensionName == "maekdown") {
        result = MainWindow::noteType::MARKDOWN;
    }

    else {
        result = MainWindow::noteType::UNSUPPORTTED;
    }

    return result;
}

void MainWindow::openFolder() {
    QString targetFolder = QFileDialog::getExistingDirectory(
        nullptr,
        tr("Open Folder"),
        getUserHomePath()
    );

    fileWatcher = new FileWatcher(targetFolder);
    /*
    connect(&fileWatcher, &FileWatcher::jsonUpdated, [&](const QJsonObject &json) {
        QString script = QString("updateFileTree(%1);").arg(QString(QJsonDocument(json).toJson(QJsonDocument::Compact)));
        webView.page()->runJavaScript(script);  // 发送 JSON 到网页
    });
    */
}

void MainWindow::openNote() {
    QString noteFile = QFileDialog::getOpenFileName(
        nullptr,
        tr("Open Note"),
        getUserHomePath(),
        tr("Note Files (*.markdown, *.pdf)")
    );
}
