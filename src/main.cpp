#include <QCoreApplication>
#include <iostream>
#include <QtCore>
#include "sort.h"

using namespace NAMESPACE;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int > arrays{100, 17, 13, 12, 10, 9, 4, 1, 0};
    insertSort_BinarySerach(arrays);
    qDebug()<< arrays;

    return a.exec();
}
