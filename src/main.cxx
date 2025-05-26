#include "QApplication"
#include "QLocale"
#include "QTranslator"
#include "null_log.hxx"
#include "mainwindow/mainwindow.hxx"

static void registerHuskyMarkdownScheme() {
    QWebEngineUrlScheme scheme("huskymarkdown");
    scheme.setSyntax(QWebEngineUrlScheme::Syntax::HostAndPort);
    scheme.setDefaultPort(0); // 防止警告
    scheme.setFlags(QWebEngineUrlScheme::SecureScheme |
                    QWebEngineUrlScheme::LocalScheme |
                    QWebEngineUrlScheme::LocalAccessAllowed |
                    QWebEngineUrlScheme::CorsEnabled);
    QWebEngineUrlScheme::registerScheme(scheme);
}

static const bool _registered = []() {
    registerHuskyMarkdownScheme();
    return true;
}();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGuiApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "2009");

    NullLog::setIsColorEnabled(true);
    NullLog::info("HuskyMarkdown", "VERSION 0.2");
    NullLog::info("HuskyMarkdown", "I18n module", "Loading i18n module...");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Husky-Markdown_" + QLocale(locale).name();
        if (translator.load(":/locales/locales/" + baseName)) {
            a.installTranslator(&translator);
            NullLog::ok("I18n Module", "Locale support found", "Loaded translation file \"" + baseName + "\".");
            break;
        }
    }

    NullLog::info("MainWindow", "Setting up main window...");
    MainWindow w;
    w.show();
    return a.exec();
}
