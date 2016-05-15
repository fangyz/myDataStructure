/*
插入排序，其核心思想是每次将无序区中的一个记录插入有序区中中合适的地方以保证有序区仍然有序。
插入排序可分为直接插入排序、折半插入排序、二路插入排序和希尔排序
*/


#include"sort.h"

/*直接插入排序：每次从无序区中选择第一个插入到有序区中。
对于时间复杂度，最好情况下数据是有序的无需比较与移动；
最坏情况下数组是一个倒序的，n-2次循环中，每次都要移动i次，时间复杂度是O(n^2)；
整体来看的话，肯定是要执行n次的，每次执行时比较与移动次数是n的一阶函数，故平均时间复杂度也是O(n^2)。
缺点是时间复杂度为n^2,效率较低，因此改进的方法是折半插入排序。
*/
void DirectInsertSort(int *a, int length)
{
	if (a == NULL || length < 0)
		return;
	int i,index;
	int value;
	//进行i次循环，每次循环将i插入到0~i-1的有序区中
		for (i = 1; i < length; i++){
			if (a[i] < a[i - 1])
			{
				index = i;
				value = a[index];
				while (value<a[index-1]&&index>0)
				{
					a[index] = a[index - 1];
					index--;
				}
				a[index] = value;
			}
		}
}


//折半插入排序，就是在无序区中取出数据插入到有序区时采用折半的思想，每次是和有序区中间的数进行比较。
//它仅仅只是减少了比较的次数，移动次数没有减少，故时间复杂度仍然为O(n^2)。
void HalfInsertSort(int *a, int length)
{
	if (a == NULL || length < 0)
		return;
	int i, index,m,n,mid;
	int value;
	//进行i次循环，每次循环将i插入到0~i-1的有序区中
	for (i = 1; i < length; i++){
		if (a[i] < a[i - 1])
		{
			index = i;
			//接下来进行折半查找，有序区范围是m~n
			m = 0;
			n = i - 1;
			value = a[index];
			while (m<n)
			{
				mid = (n + m) / 2;
				if (a[mid] ==value)
				{
					m = mid;
					break;
				}
				if (a[mid]>value)
					n = mid;
				else
					m = mid;
				//如果发生以下这种情况，
				if (n - m == 1||n==m){
					if (a[m] > value)
						m--;
					//只要发生这些特殊情况，一律退出，此时m=-1或者a[m]小于value而a[n]大于value
					break;
				}
			}
			//上面折半查找后m所在位置的数是小于或等于value的，而m后面的数则是大于或等于value的
			while (index>m+1)
			{
				a[index] = a[index - 1];
				index--;
			}
			a[index] = value;
		}
	}
}

/*希尔排序是一种分组插入排序，它的基本思想如下：
1.取一个正整数d1为它的增量，并将整个数组分为d1组。接下来对于k(k=0,1,2..d1-1)而言: k,k+d1,k+2d1....作为一组进行直接插入排序。
2.对d1组进行一次直接插入排序后，再选取新的增量d2<d1继续进行分组插入排序直到dn=1，对所有数据来一次插入排序。
思考：
刚开始接触希尔排序觉得有点麻烦，静下心来思考后就会发现希尔排序比直接插入排序时间复杂度低。首先循环次数将不再是n-2次了，而是将分组的次数。
对于每一次循环时间因为仍然是直接插入排序复杂度仍然是O(n^2)，可是由于进行分组现在的n已经减小了，故Tn总体上也会减小。
而且还有一点，直接插入排序的特点是数组越有序那移动比较次数越少，希尔排序中越往后数组越有序因此效率还会提高。
下面第一个希尔排序是我自己思考后写出来的，查阅资料后进行改进得到了第二个希尔排序写法。
*/

//这里将增量d初始化为length的一半，之后每次减半直到1
void ShellSort(int *a, int length){
	int i, j,k;
	int d;//增量
	int value,index;//直接插入排序中需要的变量
	//循环次数为lbn，
	for (d = length / 2; d >= 1; d = d / 2)
	{
		//一次循环，进行分组，对每一组执行希尔排序
		for (j = 0; j < d; j++)
		{
			//对每一组进行直接插入排序,要注意插入排序是从第二位数开始进行循环比较的。
			for (k = j+d; k < length; k = k + d)
			{
				if (a[k] < a[k - d]){
					value = a[k];
					index = k;
					while (a[index-d]>value&&index>0)
					{
						a[index] = a[index - d];
						index = index - d;
					}
					a[index] = value;
				}
			}

		}

	}

}


//更好的希尔排序
void BetterShellSort(int *a, int length){
	int d;//作为增量
	int i, j;
	int index, value;//直接插入排序需要用到的变量
	for (d = length / 2; d >= 1; d = d / 2)
	{
		//优化的思想主要是这里，上面是对每一个分组单独放在for循环里面去执行，但是这些分组其实就是在一条序列上的，只要相加的值不同仍然可以每次与同组成员进行比较。
		for (j = d; j < length; j++){
			if (a[j] < a[j - d]){
				value = a[j];
				index = j;
				while (a[index-d]>value&&index>0)
				{
					a[index] = a[index - d];
					index = index - d;
				}
				a[index] = value;
			}
		}
	}
}