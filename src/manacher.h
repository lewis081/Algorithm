#ifndef MANACHER_H
#define MANACHER_H

#include <QElapsedTimer>

class Manacher
{
public:
    Manacher();
};

struct ManacherBackInfo{
    int maxLenCenterIdx;
    int maxLenRadius;
};

ManacherBackInfo manacher_core(const QString& str);
QString preProcess(const QString& str);
QString proProcess(const QString& str);

QString manacher(const QString& str);


#endif // MANACHER_H
