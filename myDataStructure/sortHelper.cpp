
#include"sort.h"


//交换数组a中的两个数
void Swap(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}