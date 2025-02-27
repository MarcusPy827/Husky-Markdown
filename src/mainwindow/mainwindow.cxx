#include "mainwindow.hxx"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    /* 初始化Webview
     * Initialize webview
     */
    webView.setPage(new QWebEnginePage(this));
    webView.setUrl(QUrl("qrc:/webview/webview/index.html"));
    ui->mainLayout->addWidget(&webView);
    webView.show();

    /* 链接信号、槽
     * Connect signals and slots
     */
    QObject::connect(ui->action_open_note, &QAction::triggered, this, &MainWindow::openNote);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::getUserHomePath() {
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

void MainWindow::openNote() {
    QString noteFIle = QFileDialog::getOpenFileName(
        this,
        tr("Open Note"),
        getUserHomePath(),
        tr("Note Files (*.markdown, *.pdf)")
    );
}