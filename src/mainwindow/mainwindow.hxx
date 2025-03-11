#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QMainWindow"
#include "QWebEngineView"
#include "QWebEnginePage"
#include "QWebEngineProfile"
#include "QHBoxLayout"
#include "QFileDialog"
#include "QStandardPaths"
#include "../file_watcher/file_watcher.hxx"

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

        enum noteType {
            MARKDOWN,
            PDF,
            UNSUPPORTTED
        };

        static QString getUserHomePath();

    private:
        Ui::MainWindow *ui;

        QWebEngineView webView;

        FileWatcher *fileWatcher;

    private slots:
        void openFolder();

        void openNote();

        noteType getNoteType(QString filename);
};
#endif // MAINWINDOW_HXX
