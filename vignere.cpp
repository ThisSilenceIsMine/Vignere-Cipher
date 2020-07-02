#include "vignere.h"

Vignere::Vignere(QObject *parent, QByteArray string) : QObject(parent)
{
    for (int i = 0; i < string.size(); ++i) {
        char k = string[i];
       if (k >= 'A' && k <= 'Z')
          _key.append(k);
       else if (k >= 'a' && k <= 'z')
          _key.append( k + 'A' - 'a' );
    }
}

QByteArray Vignere::encrypt(QByteArray string)
{
    QByteArray result;

    for(int i = 0, j = 0; i < string.length(); ++i) {

        char c = string[i];
        char k = _key[i];

        if(c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        }
        else if( c >= 'A' || c <= 'Z') {
            continue;
        }
        char r = ( (c + k) % 26 + 'A' );
        result.append(r);
        qInfo() << r;
        j = (j + 1) % _key.length();
    }

    return result;
}

QByteArray Vignere::decrypt(QByteArray encoded)
{
    QByteArray result;

    for(int i = 0, j = 0; i < encoded.length(); ++i) {

        char c = encoded[i];
        char k = _key[i];

        if(c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        }
//        else if( c >= 'A' || c <= 'Z') {
//            continue;
//        }
        char r = ( (c - k + 26) % 26 + 'A' );
        result.append(r);
        qInfo() << r;
        j = (j + 1) % _key.length();
    }

    return result;
}
