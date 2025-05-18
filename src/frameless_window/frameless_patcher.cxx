#include "frameless_patcher.hxx"

FramelessPatcher::FramelessPatcher(bool isTypeMainWindow, QMainWindow * mainWindow, QWidget * titleBar) {
    this->isTypeMainWindow = isTypeMainWindow;
    this->targetMainWindow = mainWindow;
    this->titleBar = titleBar;
    if(titleBar == nullptr) NullLog::warn("Frameless Window", "You did not specify title bar, the window will not be draggable.");

    if(targetMainWindow != nullptr) {
        this->isInitialized = true;
        NullLog::ok("Frameless Window", "Initialization for window \"" + mainWindow->windowTitle() + "\" is ready.");
    }

    else NullLog::error("Frameless Window", "Cannot initialize frameless patcher for target main window, the pointer is null.");
}


void FramelessPatcher::patch(QMainWindow * mainwindow) {
    if(isInitialized) {
        NullLog::warn("Frameless Window", "You are about to apply frameless window, please note that this is an experimental feature.");
        NullLog::info("Frameless Window", "If your application crashes, please check if you have set a valid central widget.");
        NullLog::info("Frameless Window", "If you cannot see your window clearly, remember to set a background color for your central widget.");
        NullLog::info("Frameless Window", "Set a 16px margin for your central widget! This is very important!!");

        // 设置窗体自身无边框
        // Remove window frame
        mainwindow->setWindowFlags(Qt::FramelessWindowHint);
        mainwindow->setAttribute(Qt::WA_TranslucentBackground);

        // 设置窗体背景
        // Set window background
        auto * windowShadow = new QGraphicsDropShadowEffect;
        windowShadow->setColor("#BBBBBB");
        windowShadow->setBlurRadius(48);
        windowShadow->setOffset(0, 0);
        mainwindow->setGraphicsEffect(windowShadow);

        // 设置标题栏鼠标拖拽事件
        // Set title bar mouse dragging event
        if(titleBar != nullptr) {
            try {
                titleBar->setMouseTracking(true);
                installEventFilter(titleBar, mainwindow);
            }

            catch(...) {
                NullLog::error("Frameless Window", "Cannot install event filter to title bar");
            }
        }
    }

    else NullLog::error("Frameless Window", "Cannot apply frameless window, the class FramelessPatcher is not initialized properly.");
}


void FramelessPatcher::installEventFilter(QWidget *titleBar, QMainWindow *targetMainWindow) {
    class DragHandler : public QObject {
        QMainWindow * targetMainWindow;
        QWidget * titleBar;
        QPoint lastMousePos;

        bool isDraggingEnabled = false;

        public:
        explicit DragHandler(QWidget* bar, QMainWindow* main)  : titleBar(bar), targetMainWindow(main) {}

            bool eventFilter(QObject* obj, QEvent* event) {
                // 补丁1：防止标题栏以外的控件触发窗口拖拽
                // Patch 1: Prevent widget other than title bar invoking window dragging
                if (obj != titleBar) return false;

                if (event->type() == QEvent::MouseButtonPress) {
                    auto * mouse = static_cast<QMouseEvent*>(event);

                    if (mouse->button() == Qt::LeftButton) {
                        NullLog::info("Frameless Window", "Mouse clicked on main window.");
                        lastMousePos = mouse->globalPosition().toPoint();
                        isDraggingEnabled = true;
                    }
                }

                else if (event->type() == QEvent::MouseMove) {
                    if (isDraggingEnabled) {
                        // NullLog::info("Frameless Window", "The main window is being dragged, we are currently updating position...");
                        auto * mouse = static_cast<QMouseEvent*>(event);
                        if(targetMainWindow->isMaximized()) targetMainWindow->showNormal();
                        QPoint currentMousePos = mouse->globalPosition().toPoint();
                        targetMainWindow->move(targetMainWindow->pos() + (currentMousePos - lastMousePos));
                        lastMousePos = currentMousePos;
                    }

                    // else NullLog::info("Frameless Window", "The main window is being dragged, but we are asked to ignore that.");
                }

                else if (event->type() == QEvent::MouseButtonRelease) {
                    auto* mouse = static_cast<QMouseEvent*>(event);
                    if (mouse->button() == Qt::LeftButton) {
                        isDraggingEnabled = false;
                        NullLog::ok("Frameless Window", "Mouse released, updating process accomplished");
                    }
                }

                else if(event->type() == QEvent::MouseButtonDblClick) {
                    if(targetMainWindow->isMaximized()) {
                        targetMainWindow->showNormal();
                    }

                    else targetMainWindow->showMaximized();
                }

                return false;
            }
    };

    titleBar->installEventFilter(new DragHandler(titleBar, targetMainWindow));
}