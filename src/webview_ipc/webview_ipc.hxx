#ifndef WEBVIEW_IPC_HXX
#define WEBVIEW_IPC_HXX

#include "QObject"

class WebviewIPC : public QObject {
    Q_OBJECT
    Q_PROPERTY(NOTIFY onRootPathChanged FINAL)

    public:
        WebviewIPC();

    public slots:
        void updateJSON(QString in);

    signals:
        void onRootPathChanged(QString rootFolder);
};

#endif // WEBVIEW_IPC_HXX
