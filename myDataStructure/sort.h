#include<stdio.h>
#include<stdlib.h>

//插入排序
void DirectInsertSort(int *a, int length);     //直接插入排序
void HalfInsertSort(int *a, int length);        //折半直接插入排序
void ShellSort(int *a, int length);               //希尔排序排序
void BetterShellSort(int *a, int length);      //优化后的希尔排序

//交换排序


//选择排序
void SimpleSelectSort(int *a, int length);    //简单选择排序
void HeapSelectSort(int *a, int length);      //堆排序

//归并排序
void MergeSort(int* a, int length);

//帮助方法
//1.交换数组a中的两个下标为i和j的数
void Swap(int *a, int i, int j);
