#include<stdio.h>
#include<stdlib.h>

//��������
void DirectInsertSort(int *a, int length);     //ֱ�Ӳ�������
void HalfInsertSort(int *a, int length);        //�۰�ֱ�Ӳ�������
void ShellSort(int *a, int length);               //ϣ����������
void BetterShellSort(int *a, int length);      //�Ż����ϣ������

//��������
void BubbleSort(int *a, int length);            //ԭʼð������
void BetterBubbleSort(int *a, int length);   //�Ż����ð������
void QuickSort(int *a, int start, int end);    //��������

//ѡ������
void SimpleSelectSort(int *a, int length);    //��ѡ������
void HeapSelectSort(int *a, int length);      //������

//�鲢����
void MergeSort(int* a, int length);

//��������
//1.��������a�е������±�Ϊi��j����
void Swap(int *a, int i, int j);
