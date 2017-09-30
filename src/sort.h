#ifndef SORT_H
#define SORT_H

#include <vector>
#include <QVector>
#include <QList>

namespace NAMESPACE {

void insertSort(int* array, const int size);
void insertSort(QVector<int >& array);
void insertSort(QList<int >& array);

void insertSort_BinarySerach(QVector<int >& array);

}


#endif // SORT_H
