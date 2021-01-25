//
// Created by Butter on 2021/1/15.
//

#include "MaxHeap.h"

void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//建立大根堆
void BuildMaxHeap(int A[],int len){
    for (int i = len/2; i >0 ; i--) {
        HeadAdjust(A,i,len);
    }
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[],int k,int len) {
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) i++;
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

//堆排序的完整逻辑
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);
    for (int i = len; i > 1 ; i--) {
        Swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
}

