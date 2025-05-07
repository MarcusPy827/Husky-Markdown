#include "theme_loader.hxx"

QString ThemeLoader::FromFile(QString in) {
    QFile target(in);
    if(!target.exists()) {
        NullLog::error("Theme Loader", "Cannot load theme", "The given stylesheet is missing. Please check if the following file exists: \"" + in + "\".");
        return "";
    }

    else if(!target.open(QIODevice::ReadOnly | QIODevice::Text)) {
        NullLog::error("Theme Loader", "Cannot load theme", "Cannot open style sheet, please check if \"" + in + "\" is readable.");
        return "";
    }

    else {
        QTextStream stream(& target);
        stream.setEncoding(QStringConverter::Encoding::Utf8);

        QString content = stream.readAll();
        target.close();

        if (content.isEmpty()) NullLog::warn("Theme Loader", "The theme file \"" + in + "\" is empty, returning an empty string.");
        else NullLog::ok("Theme Loader", "Successfully loaded theme \"" + in + "\".");
        return content;
    }
}