#ifndef FRAMELESS_PATCHER_HXX
#define FRAMELESS_PATCHER_HXX

#include "QMainWindow"
#include "QGraphicsDropShadowEffect"
#include "QEvent"
#include "QMouseEvent"
#include "null_log.hxx"

class FramelessPatcher {
    public:
        FramelessPatcher(bool isTypeMainWindow, QMainWindow * mainWindow, QWidget * titleBar);
        void patch(QMainWindow * mainwindow);

    private:
        void installEventFilter(QWidget *titleBar, QMainWindow *targetMainWindow);

        QMainWindow * targetMainWindow;
        QWidget * titleBar;
        QPoint lastMousePos;

        bool isTypeMainWindow = true;
        bool isInitialized = false;


};



#endif //FRAMELESS_PATCHER_HXX
