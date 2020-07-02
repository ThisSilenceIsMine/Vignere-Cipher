#ifndef VIGNERE_H
#define VIGNERE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QByteArray>

class Vignere : public QObject
{
    Q_OBJECT
public:
    explicit Vignere(QObject *parent = nullptr, QByteArray key = QByteArray());
    QByteArray encrypt(QByteArray string);
    QByteArray decrypt(QByteArray encoded);
signals:

private:
    QByteArray _key;
};

#endif // VIGNERE_H
