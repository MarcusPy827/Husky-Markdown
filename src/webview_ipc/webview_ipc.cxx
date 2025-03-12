#include "webview_ipc.hxx"

WebviewIPC::WebviewIPC() {}

void WebviewIPC::updateJSON(QString in) {
    emit onRootPathChanged(in);
}
