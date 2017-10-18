#include <QCoreApplication>
#include <iostream>
#include <QtCore>
#include "sort.h"
#include "manacher.h"

using namespace NAMESPACE;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QVector<int > arrays{100, 17, 13, 12, 10, 9, 4, 1, 0};
//    insertSort_BinarySerach(arrays);
//    qDebug()<< arrays;

    QString str;
    const int N = 1000000;
    for(int i = 0; i < N; i++){
        str.append("xx1csadasdsadasc1xx");
    }

    qDebug()<< "init done";
    QElapsedTimer timer;
    timer.start();
    QString sss =manacher(str);
    qDebug()<< sss.size();
    qDebug()<< N<< "manacher done:"<< timer.elapsed()<< "ms";

    return a.exec();
}
