#ifndef THEME_LOADER_HXX
#define THEME_LOADER_HXX

#include "QString"
#include "QFile"
#include "QTextStream"
#include "null_log.hxx"

class ThemeLoader {
    public:
        static QString FromFile(QString in);
};



#endif //THEME_LOADER_HXX
