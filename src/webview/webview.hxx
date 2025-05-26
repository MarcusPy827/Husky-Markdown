#ifndef HUSKY_MARKDOWN_WEBVIEW_HXX
#define HUSKY_MARKDOWN_WEBVIEW_HXX

#include "QWidget"

class WebView : public QWidget {
    Q_OBJECT

    public:
        explicit WebView(QWidget *parent = nullptr);
        ~WebView() override = default;

    private:
};

#endif //HUSKY_MARKDOWN_WEBVIEW_HXX