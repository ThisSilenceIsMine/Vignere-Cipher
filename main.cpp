#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>
#include "vignere.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vignere cryptor(nullptr,"LEMON");

    QByteArray string = "helloworld";
    qInfo() << "Before encrypting: " << string;

    QByteArray encrypted = cryptor.encrypt(string);
    qInfo() << "Encrypted: " << encrypted;

    QByteArray decrypted = cryptor.encrypt(encrypted);
    qInfo() << "Decrypted: " << decrypted;

    return a.exec();
}
