#include "QApplication"
#include "QLocale"
#include "QTranslator"
#include "mainwindow/mainwindow.hxx"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    /* 开发者工具 · 如需要开启请取消注释，number(<PORT>)中为端口号。要使用开发者工具，请在本机正常浏览器中访问localhost:<PORT>
     * DevTools · Uncomment if devtools is needed. The port number is set on number(<PORT>).
     * To use devtools, visit localhost:<PORT> on any browser.
     */

    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", QByteArray::number(9000));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Husky-Markdown_" + QLocale(locale).name();
        if (translator.load(":/locales/locales/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
