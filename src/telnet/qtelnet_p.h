#ifndef QTELNET_P_H
#define QTELNET_P_H

#include <QPair>
#include <QObject>
#include <QTcpSocket>
#include <QSocketNotifier>
#include <QSize>

class QTelnetReceiveBuffer
{
public:
    QTelnetReceiveBuffer() : bytesAvailable(0) {}
    void append(const QByteArray &data) { buffers.append(data); }
    void push_back(const QByteArray &data) { buffers.prepend(data); }
    long size() const { return bytesAvailable; }
    QByteArray readAll()
    {
        QByteArray a;
        while (!buffers.isEmpty()) {
            a.append(buffers.takeFirst());
        }
        return a;
    }

private:
    QList<QByteArray> buffers;
    long bytesAvailable;
};

class QTelnet;
class QTelnetAuth;
class QTelnetPrivate : public QObject
{
    Q_OBJECT
public:
    QTelnetPrivate(QTelnet *parent);
    virtual ~QTelnetPrivate();

    QMap<char, bool> modes;
    QList< QPair<uchar, uchar> > osent;

    QTelnet *q;
    QTcpSocket *socket;
    QTelnetReceiveBuffer buffer;
    QSocketNotifier *notifier;

    QSize windowSize;

    bool connected, nocheckp;
    bool triedlogin, triedpass, firsttry;

    QMap<int, QTelnetAuth*> auths;
    QTelnetAuth *curauth;
    bool nullauth;

    QRegExp loginp, passp, promptp;
    QString login, pass;

    bool allowOption(int oper, int opt);
    void sendOptions();
    void sendCommand(const QByteArray &command);
    void sendCommand(const char *command, int length);
    void sendCommand(const char operation, const char option);
    void sendString(const QString &str);
    bool replyNeeded(uchar operation, uchar option);
    void setMode(uchar operation, uchar option);
    bool alreadySent(uchar operation, uchar option);
    void addSent(uchar operation, uchar option);
    void sendWindowSize();

    int  parsePlaintext(const QByteArray &data);
    int parseIAC(const QByteArray &data);
    bool isOperation(const uchar c);
    bool isCommand(const uchar c);
    QByteArray getSubOption(const QByteArray &data);
    void parseSubAuth(const QByteArray &data);
    void parseSubTT(const QByteArray &data);
    void parseSubNAWS(const QByteArray &data);
    uchar opposite(uchar operation, bool positive);

    void consume();

    void setSocket(QTcpSocket *socket);

public slots:
    void socketConnected();
    void socketConnectionClosed();
    void socketReadyRead();
    void socketError(QAbstractSocket::SocketError error);
    void socketException(int);
};

#endif // QTELNET_P_H
