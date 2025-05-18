#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QSpacerItem"
#include "QPushButton"
#include "null_log.hxx"
#include "QWKWidgets/widgetwindowagent.h"
#include "../frameless_window/frameless_patcher.hxx"
#include "../theme_loader/theme_loader.hxx"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        QWidget * centralWidget = new QWidget(this);
        QVBoxLayout * mainLayout = new QVBoxLayout(centralWidget);
        QWidget * titleBar = new QWidget(this);
        QPushButton * minimizeBtn = new QPushButton();
        QPushButton * maximizeBtn = new QPushButton();
        QPushButton * closeBtn = new QPushButton();

        FramelessPatcher * framelessPatcher = new FramelessPatcher(true, this, titleBar);

    private slots:
        void minimizeWindow();
        void toggleMaximizeWindow();
        void closeWindow();

};
#endif // MAINWINDOW_HXX
