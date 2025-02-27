#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QWebEngineView"
#include "QWebEnginePage"
#include "QWebEngineProfile"
#include "QHBoxLayout"
#include "QFileDialog"
#include "QStandardPaths"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

        ~MainWindow();

        static QString getUserHomePath();

    private:
        Ui::MainWindow *ui;

        QWebEngineView webView;

    private slots:
        void openNote();
};
#endif // MAINWINDOW_HXX
