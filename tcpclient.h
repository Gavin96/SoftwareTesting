#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QTime>
namespace Ui {
    class TcpClient;
}

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();
    void setHostAddress(QHostAddress address);  //设置主机地址
    void setFileName(QString fileName){localFile = new QFile(fileName);}//设置文件名

protected:
    void changeEvent(QEvent *e);    //变更事件

private:
    Ui::TcpClient *ui;
    QTcpSocket *tcpClient;  //TCP客户端Socket
    quint16 blockSize;  //块大小
    QHostAddress hostAddress;   //主机地址
    qint16 tcpPort; //tcp端口号

    qint64 TotalBytes;      //请求内容的大小；总量
    qint64 bytesReceived;   //已接收的总字节数
    qint64 bytesToReceive;  //未接收的总字节数
    qint64 fileNameSize;    //文件名大小
    QString fileName;       //文件名
    QFile *localFile;       //本地文件
    QByteArray inBlock;     //整块
    QTime time;

private slots:
    void on_tcpClientCancleBtn_clicked();   //tcp客户端取消按钮事件
    void on_tcpClientCloseBtn_clicked();    //tcp客户端关闭按钮事件
    void newConnect();  //新连接
    void readMessage(); //读消息
    void displayError(QAbstractSocket::SocketError);    //显示错误
};

#endif // TCPCLIENT_H
