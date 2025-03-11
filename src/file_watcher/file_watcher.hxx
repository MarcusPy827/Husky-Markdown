#ifndef FILE_WATCHER_HXX
#define FILE_WATCHER_HXX

#include "QObject"
#include "QFileSystemWatcher"
#include "QJsonObject"
#include "QJsonArray"
#include "QDir"
#include "QDebug"

class FileWatcher : public QObject {
    Q_OBJECT

    public:
        FileWatcher(QString targetDir);

    public slots:
        void startWatch(QString targetDir);

    private:
        QFileSystemWatcher watcher;

        QString rootDir;

        QJsonObject genRootTree();

        QJsonArray getFileList(QString targetDir);

    private slots:
        void dirChanged(const QString &targetDir);

        void fileChanged(const QString &targetFile);

    signals:
        void jsonUpdated(QJsonObject result);
};

#endif // FILE_WATCHER_HXX
