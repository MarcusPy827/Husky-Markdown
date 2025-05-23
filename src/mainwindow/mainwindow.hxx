#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QSpacerItem"
#include "QPushButton"
#include "QLabel"
#include "null_log.hxx"
#include "QWKWidgets/widgetwindowagent.h"
#include "../theme_loader/theme_loader.hxx"

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

    private slots:
        void minimizeWindow();
        void toggleMaximizeWindow();
        void closeWindow();

    protected:
        void changeEvent(QEvent *event) override;

};
#endif // MAINWINDOW_HXX
