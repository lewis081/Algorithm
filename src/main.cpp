#include <QCoreApplication>
#include <iostream>
#include <QtCore>
#include "sort.h"

using namespace NAMESPACE;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int > arrays{13, 1, 10, 9, 4, 12, 100, 0, 17};
    insertSort(arrays);
    qDebug()<< arrays;

    return a.exec();
}
