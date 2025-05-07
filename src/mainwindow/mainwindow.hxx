#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QHBoxLayout"
#include "null_log.hxx"
#include "../frameless_window/frameless_patcher.hxx"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        QWidget * titleBar = new QWidget(this);
        FramelessPatcher * framelessPatcher = new FramelessPatcher(true, this, titleBar);

    private slots:

};
#endif // MAINWINDOW_HXX
