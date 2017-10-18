#include "sort.h"
#include <QDebug>

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

//我的新想法(): 抽离出对二分法查找特点的理解，再做判断
//特点： 二分查找(如果没有找到这个元素)法最终肯定left = right,
//且这个索引的值和目标值邻近,要么在所有大于目标值的最小值索引处，要么在所有小于目标值的最大索引处

//大于val的最小值的idx
//满足right < size
int findIdxUseBinarySearch_MyIdea(QVector<int> &array, int left, int right, const int key)
{
    //binary search: 要么在所有大于目标值的最小值索引处，要么在所有小于目标值的最大索引处, left == right
    while (left < right){
        int middle = (left + right) / 2;
        if (array[middle] > key)
            right = middle - 1;
        else
            left  = middle + 1;
    }

    //judge: 根据二分法最终索引的特点 多加一层判定
    int idx = left;
    if (array[left]  < key) idx = left + 1;
//    qDebug()<< key<< array[left + 1];

    return idx;
}

void insertSort_BinarySerach(QVector<int> &array)
{
    const int size = array.size();

    for(int idx = 1; idx < size; idx++){//n - 1
        int key = array[idx];

//        int backMoveStartIdx = findIdxUseBinarySearch_Internet(array, 0, idx-1, key);
//        int backMoveStartIdx = findIdxUseBinarySearch(array, 0, idx-1, key);
        int backMoveStartIdx = findIdxUseBinarySearch_MyIdea(array, 0, idx-1, key);

        for(int moveIdx = idx-1; moveIdx >= backMoveStartIdx; moveIdx--){
            array[moveIdx+1] = array[moveIdx];
        }
        array[backMoveStartIdx] = key;
    }
}



}
