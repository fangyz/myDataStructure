//归并排序，指的是将两个或两个以上的有序序列合并成一个有序序列，若采用线性表则易于实现。

/*基本步骤：
1.首先可将整个序列看成是n个长度为1的有序序列；
2.接着将有序序列分成n/2个长度为2或1的序列，并对n/2个序列进行排序得到n/2个有序的长度为2或1的有序序列；
3.重复第二步，直到得到有序序列的长度为n为止。

从上可以看出总共会经过lbn次划分，每次划分后要比较n次，故时间复杂度为nlbn。
*/

#include"sort.h"


//这个方法的目的就是让first到last这之间的数据变成有序的，前提是first到mid，mid到last之间的数据已经是有序的
void Merge(int *a, int first, int mid, int last)
{
	//start1为第一个序列的开始索引，end1为第一个序列的结束索引
	//start2为第一个序列的开始索引，end2为第一个序列的结束索引
	int start1 = first, end1 = mid;
	int start2 = mid + 1, end2 = last;
	int k = 0, i = 0;
	//临时数组，用来存储first到last的有序的数组
	int *temp = new int[last - first + 1];
	//执行这个while循环后可保证至少有一个序列已经全部放入temp中
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] <= a[start2])
			temp[k++] = a[start1++];
		else
			temp[k++] = a[start2++];
	}

	//之所以要在这里加上2个while，是因为有可能上面的while执行时，
	//第一个序列的所有值全都比第二列小，那么执行完的时候并没有将start1到end2的所有值全部赋值给temp
	//两个while都是小于等于是因为当start1=end1时当前start1的值并没有存入temp。
	while (start1 <= end1)
		temp[k++] = a[start1++];
	while (start2 <= end2)
		temp[k++] = a[start2++];

	//最后在将temp的值赋值给a
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
	delete[]temp;
}

//进行数组的分组
void InitSort(int a[], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		InitSort(a, first, mid);//左边有序
		InitSort(a, mid + 1, last);//右边有序
		Merge(a, first, mid, last);//合并两个有序数列
	}
}

//归并排序
void MergeSort(int* a, int length)
{
	InitSort(a, 0, length - 1);
}






