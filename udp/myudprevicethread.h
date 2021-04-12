#ifndef MYUDPREVICETHREAD_H
#define MYUDPREVICETHREAD_H
#include <QThread>
#include <QUdpSocket>
#include <QTimer>
struct SendInfo{
    QString ip;//对方ip
    int  port;//对方端口
    QByteArray data;//原数据
    int length;//原数据长度
    int errornum;

};
Q_DECLARE_METATYPE(SendInfo)


class MyUdpReviceThread : public QThread
{
    Q_OBJECT
public:
    MyUdpReviceThread(QString ip,int port);
    ~MyUdpReviceThread();
    void stop();
    QList<QByteArray> *mReciveMesDataList;
    QList<SendInfo> *mSendDataList;
    void SendUdpTXServerData(QByteArray &data,QString ip,int port);
signals:
    void Request();
private slots:
    void setSendData();
protected:
    void run();
private:
    QUdpSocket *mSocket;
    QString hostip;
    quint16 hostport;
    QByteArray mReceviceByteArray;
    void  dealRecive(QByteArray requestData);
    bool mStopped;

    bool chandlepack(QByteArray buffer);
    void handledata(QByteArray data);
    void  ChangWFHDwToCharGaoQ(ulong dourceData, uchar destChar[],int offset, int ChangCut);
    unsigned int crc(QByteArray data, unsigned int Size);
    int number;




};



#endif // MYUDPREVICETHREAD_H
