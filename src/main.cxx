#include "QApplication"
#include "QLocale"
#include "QTranslator"
#include "mainwindow/mainwindow.hxx"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

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
