#ifndef HUSKY_MARKDOWN_REQUEST_HANDLER_HXX
#define HUSKY_MARKDOWN_REQUEST_HANDLER_HXX

#include "QWebEngineUrlSchemeHandler"
#include "QWebEngineUrlRequestJob"
#include "QUrl"
#include "QFile"

class RequestHandler: public QWebEngineUrlSchemeHandler{
    public:
        void requestStarted(QWebEngineUrlRequestJob *job) override;
};


#endif //HUSKY_MARKDOWN_REQUEST_HANDLER_HXX
