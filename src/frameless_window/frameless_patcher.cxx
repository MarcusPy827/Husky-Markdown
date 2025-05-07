#include "frameless_patcher.hxx"

void FramelessPatcher::patch(QMainWindow * mainwindow) {
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
}
