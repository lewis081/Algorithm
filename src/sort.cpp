#include "sort.h"


namespace NAMESPACE {

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void insertSort(int *array, const int size)
{
    if(array == 0 || size <=0 ) return;

    for(int idx = 0; idx < size; idx++){
        for(int j = idx; j > 0; j--){
            if (array[j - 1] > array[j]){
                swap(array[j - 1], array[j]);
            }
        }
    }
}

void insertSort(std::vector<int >& array)
{
    const int size = array.size();

    for(int idx = 0; idx < size; idx++){
        for(int j = idx; j > 0; j--){
            if (array[j - 1] > array[j]){
                swap(array[j - 1], array[j]);
            }
        }
    }
}

//n*n*1 = n^2
void insertSort(QVector<int> &array)
{
    const int size = array.size();

    for(int idx = 0; idx < size; idx++){//n
        for(int j = idx; j > 0; j--){//n
            if (array[j - 1] > array[j]){
                swap(array[j - 1], array[j]);//1
            }
        }
    }
}



}
