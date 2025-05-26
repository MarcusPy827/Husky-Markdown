#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QSpacerItem"
#include "QPushButton"
#include "QLabel"
#include "QStackedWidget"
#include "null_log.hxx"
#include "../search_bar/search_bar.hxx"
#include "../webview/webview.hxx"
#include "../theme_loader/theme_loader.hxx"
#include "QWKWidgets/widgetwindowagent.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override = default;

    private:
        QWidget * centralWidget = new QWidget(this);
        QVBoxLayout * mainLayout = new QVBoxLayout(centralWidget);
        QWidget * titleBar = new QWidget(this);
        QPushButton * fileBtn = new QPushButton();
        QPushButton * helpBtn = new QPushButton();
        QLabel * appTitle = new QLabel();
        QPushButton * minimizeBtn = new QPushButton();
        QPushButton * maximizeBtn = new QPushButton();
        QPushButton * closeBtn = new QPushButton();
        QWidget * navigationRail = new QWidget();
        QPushButton * fab = new QPushButton();
        QPushButton * notesBtn = new QPushButton();
        QPushButton * notesDesc = new QPushButton();
        QPushButton * searchBtn = new QPushButton();
        QPushButton * searchDesc = new QPushButton();
        QPushButton * settingsBtn = new QPushButton();
        QPushButton * settingsDesc = new QPushButton();
        QPushButton * avatarView = new QPushButton();
        QStackedWidget * header = new QStackedWidget();
        QStackedWidget * pageContainer = new QStackedWidget();

        SearchBar * searchBar = new SearchBar();
        WebView * webView = new WebView();

    private slots:
        void minimizeWindow();
        void toggleMaximizeWindow();
        void closeWindow();

};
#endif // MAINWINDOW_HXX
