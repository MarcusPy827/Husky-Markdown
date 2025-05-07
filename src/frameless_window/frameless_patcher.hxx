#ifndef FRAMELESS_PATCHER_HXX
#define FRAMELESS_PATCHER_HXX

#include "QMainWindow"
#include "QGraphicsDropShadowEffect"
#include "null_log.hxx"

class FramelessPatcher {
    public:
        static void patch(QMainWindow * mainwindow);
};



#endif //FRAMELESS_PATCHER_HXX
