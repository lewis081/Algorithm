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
            if (array[j] > array[j - 1]){
                break;
            }
            else if (array[j] < array[j - 1]){
                swap(array[j - 1], array[j]);
            }
        }
    }
}

//底层数据结构为数组
//bad:  n*n*1 = n^2
//good: n*1*1 = n
void insertSort(QVector<int> &array)
{
    const int size = array.size();

    for(int idx = 0; idx < size; idx++){//n
        for(int j = idx; j > 0; j--){//bad/good: n/1
            if (array[j] > array[j - 1]){
                break;
            }
            else if (array[j] < array[j - 1]){
                swap(array[j - 1], array[j]);//1
            }

        }
    }
}

//底层数据结构为链表
//
void insertSort(QList<int> &array)
{

}


//大于val的最小值的idx
int findIdxUseBinarySearch(QVector<int> &array, int left, int right, const int val)
{

    while(1){
        const int mid  = (left + right) / 2;

        if (array[mid] > val){
            if (mid == left) return mid;
            else{
                if (array[mid-1] < val) return mid;
                right = mid - 1;
            }
        }
        else if (array[mid] < val){
            if (mid == right) return mid;
            else {
                if (array[mid+1] > val) return mid + 1;
                left = mid + 1;
            }
        }
    }
}

//来自网络的一种方法
//大于val的最小值的idx
int findIdxUseBinarySearch_Internet(QVector<int> &array, int left, int right, const int key)
{
    while (left <= right){
        int middle = (left + right) / 2;
        if (array[middle] > key)
            right = middle - 1;
        else
            left  = middle + 1;
    }

    return left;
}

void insertSort_BinarySerach(QVector<int> &array)
{
    const int size = array.size();

    for(int idx = 1; idx < size; idx++){//n - 1
        int key = array[idx];

//        int backMoveStartIdx = findIdxUseBinarySearch_Internet(array, 0, idx, key);
        int backMoveStartIdx = findIdxUseBinarySearch(array, 0, idx, key);

        for(int moveIdx = idx-1; moveIdx >= backMoveStartIdx; moveIdx--){
            array[moveIdx+1] = array[moveIdx];
        }
        array[backMoveStartIdx] = key;
    }
}



}
