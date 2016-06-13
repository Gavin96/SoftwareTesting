#include <QApplication>
#include <QTextCodec>
//新增
#include "widget.h"

int main(int argc, char *argv[])
{

//    // 以下部分解决中文乱码
//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//    QTextCodec::setCodecForTr(codec);
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    // 以上部分解决中文乱码

    QApplication a(argc, argv);
    Widget w;
//    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}
