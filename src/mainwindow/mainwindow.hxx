#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "null_log.hxx"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override = default;

    private:


    private slots:

};
#endif // MAINWINDOW_HXX
