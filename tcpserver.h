#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QTcpServer>
#include <QFile>
#include <QTime>

namespace Ui {
    class TcpServer;
}

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();
    void refused(); //拒绝

    void initServer();  //初始化服务器


protected:
    void changeEvent(QEvent *e);    //变更事件

private:
    Ui::TcpServer *ui;
    qint16 tcpPort; //tcp端口号
    QTcpServer *tcpServer;  //Qt的tcp服务类
    QString fileName;
    QString theFileName;
    QFile *localFile;

    qint64 TotalBytes;  //请求内容的大小；总量
    qint64 bytesWritten;    //已发送的字节数
    qint64 bytesToWrite;    //未发送的字节数
    qint64 loadSize;    //载入容量
    QByteArray outBlock;//缓存一次发送的数据

    QTcpSocket *clientConnection; //客户端连接的Socket

    QTime time;//计时器

private slots:
    void on_serverCloseBtn_clicked();   //服务断开按钮事件
    void on_serverSendBtn_clicked();    //服务发送按钮事件
    void on_serverOpenBtn_clicked();    //服务打开按钮事件
    void sendMessage();     //发送消息

   void updateClientProgress(qint64 numBytes);  //更新服务器进程
signals:
    void sendFileName(QString fileName);    //发送文件名信号

};

#endif // TCPSERVER_H
