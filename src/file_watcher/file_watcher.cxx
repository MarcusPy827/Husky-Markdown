#include "file_watcher.hxx"

FileWatcher::FileWatcher(QString targetDir) {
    if(targetDir == nullptr) return;
    rootDir = targetDir;
    startWatch(rootDir);

    connect(&watcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::dirChanged);
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &FileWatcher::fileChanged);
}

void FileWatcher::dirChanged(const QString &targetDir) {
    qDebug() << "[INFO] FileWatcher - Directory changed: The directory\"" + targetDir +"\" has been changed." << Qt::endl;
    emit jsonUpdated(genRootTree());
}

void FileWatcher::fileChanged(const QString &targetFile) {
    qDebug() << "[INFO] FileWatcher - File changed: The file\"" + targetFile +"\" has been changed." << Qt::endl;
    emit jsonUpdated(genRootTree());
}

QJsonObject FileWatcher::genRootTree() {
    QJsonObject result;
    result["path"] = rootDir;
    result["files"] = getFileList(rootDir);
    tree = result;
    return result;
}

void FileWatcher::startWatch(QString targetDir) {
    QDir currentDir(targetDir);
    if(!currentDir.exists()) return;
    if(!watcher.directories().contains(targetDir)) {
        watcher.addPath(targetDir);
        emit jsonUpdated(genRootTree());
    }

    /*
     * watch所有文件，并且watch子目录
     * Watch all the fuile and all the subfolders recursively
     */
    //QFileInfoList fileList = currentDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    //for(const QFileInfo& file : fileList) if(file.isDir()) startWatch(file.absoluteFilePath());
}

QJsonArray FileWatcher::getFileList(QString targetDir) {
    QDir currentDir(targetDir);
    if(!currentDir.exists()) return {};

    QJsonArray fileArray;
    QFileInfoList fileList = currentDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for(const QFileInfo &file : fileList) {
        QJsonObject fileObject;
        fileObject["name"] = file.fileName();
        fileObject["type"] = file.isDir() ? "directory" : "file";
        fileObject["path"] = file.absoluteFilePath();
        qDebug() << "[INFO] FileWatcher - File object added:" << file.fileName() << Qt::endl;

        //if(file.isDir()) fileObject["files"] = getFileList(file.absoluteFilePath());
        fileArray.append(fileObject);
    }

    return fileArray;
}

/* 此函数用于初始化后获取初始的文件夹内容
 * This function is used to get initial folder content
 */

QJsonObject FileWatcher::getTree() {
    return tree;
}
