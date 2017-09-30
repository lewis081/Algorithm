#ifndef SORT_H
#define SORT_H

#include <vector>
#include <QVector>

namespace NAMESPACE {

void insertSort(int* array, const int size);

void insertSort(std::vector<int >& array);

void insertSort(QVector<int >& array);

}


#endif // SORT_H
