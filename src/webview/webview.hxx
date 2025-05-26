#ifndef HUSKY_MARKDOWN_WEBVIEW_HXX
#define HUSKY_MARKDOWN_WEBVIEW_HXX

#include "QWidget"
#include "QHBoxLayout"
#include "QWebEngineView"
#include "QWebEngineUrlScheme"
#include "QWebEngineProfile"
#include "../request_handler/request_handler.hxx"

class WebView : public QWidget {
    Q_OBJECT

    public:
        explicit WebView(QWidget *parent = nullptr);
        ~WebView() override = default;

    private:
        QWebEngineView *view;
};

#endif //HUSKY_MARKDOWN_WEBVIEW_HXX