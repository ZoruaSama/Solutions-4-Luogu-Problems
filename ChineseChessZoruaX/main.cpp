#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //窗口大小 1200x750
    //先完成基本的图像绘制、走棋、生成棋谱的功能……
    QTextCodec *codec = QTextCodec::codecForName("utf8");//字符编码格式转换

    w.show();

    return a.exec();
}
