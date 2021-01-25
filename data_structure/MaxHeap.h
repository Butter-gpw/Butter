//
// Created by Butter on 2021/1/15.
//

#ifndef ADT_MAXHEAP_H
#define ADT_MAXHEAP_H
#include <iostream>
using namespace std;

void swap(int *a,int *b);
void HeadAdjust(int A[],int k,int len);
void BuildMaxHeap(int A[],int len);
void HeapSort(int A[],int len);

#endif //ADT_MAXHEAP_H
