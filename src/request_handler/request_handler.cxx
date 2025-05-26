#include "request_handler.hxx"

void RequestHandler::requestStarted(QWebEngineUrlRequestJob *job) {
    QUrl target = job->requestUrl();
    QString path = target.path();

    QFile * file = new QFile(":/webview/webview" + path);
    if (!file->open(QIODevice::ReadOnly)) {
        job->fail(QWebEngineUrlRequestJob::UrlNotFound);
        return;
    }

    QByteArray mime;
    if (path.endsWith(".html")) mime = "text/html";
    else if (path.endsWith(".js")) mime = "application/javascript";
    else if (path.endsWith(".css")) mime = "text/css";
    else mime = "text/plain";

    job->reply(mime, file);
}