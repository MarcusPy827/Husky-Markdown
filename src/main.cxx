#include "QApplication"
#include "QLocale"
#include "QTranslator"
#include "null_log.hxx"
#include "mainwindow/mainwindow.hxx"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

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
