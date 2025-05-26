#include "webview.hxx"

WebView::WebView(QWidget *parent) : QWidget(parent) {
    auto * layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

    view = new QWebEngineView();
    view->page()->profile()->installUrlSchemeHandler("huskymarkdown", new RequestHandler());
    view->setUrl(QUrl("qrc:/webview/webview/index.html"));
    layout->addWidget(view);
    setObjectName("web_view");
}
