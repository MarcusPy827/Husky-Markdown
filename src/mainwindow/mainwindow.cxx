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
}

MainWindow::~MainWindow() {
    delete ui;
}
