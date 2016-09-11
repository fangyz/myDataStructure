/*
插入排序，其核心思想是每次将无序区中的一个记录插入有序区中中合适的地方以保证有序区仍然有序。
插入排序可分为直接插入排序、折半插入排序、二路插入排序和希尔排序
*/


#include"sort.h"

/*直接插入排序：每次从无序区中选择第一个插入到有序区中。
对于时间复杂度，最好情况下数据是有序的无需移动，比较次数为n-1；
最坏情况下数组是一个倒序的，n-1次循环中，每次都要移动i+1次，比较次数为i    ，时间复杂度是O(n^2)；
整体来看的话，肯定是要执行n次的，每次执行时比较与移动次数是n的一阶函数，故平均时间复杂度也是O(n^2)。
缺点是时间复杂度为n^2,效率较低，改进可从2个地方改进，一个是比较次数一个是移动次数。
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
	int i;
	int start = 0, end = 0, mid = 0;
	int currentIndex = 0;
	int temp = 0;
	if (a == NULL || length <= 0)
		return;
	for (i = 1; i<length; i++)
	{
		currentIndex = i;
		temp = a[i];
		end = i;
		mid = end;
		//目的是找到一个位置mid，a[mid]>temp而a[mid-1]是小于或等于temp的
		while (end>start&&temp<a[end - 1])
		{
			mid = (start + end) / 2;
			if (a[mid]>temp)
				end = mid;
			else
			{
				if (start == mid)
				{
					mid++;
					break;
				}
				start = mid;
			}
		}
		for (; currentIndex>mid; currentIndex--)
			a[currentIndex] = a[currentIndex - 1];
		a[currentIndex] = temp;
	}
}

/*希尔排序是一种分组插入排序，它的基本思想如下：
1.取一个正整数d1为它的增量，并将整个数组分为d1组。接下来对于k(k=0,1,2..d1-1)而言: k,k+d1,k+2d1....作为一组进行直接插入排序。
2.对d1组进行一次直接插入排序后，再选取新的增量d2<d1继续进行分组插入排序直到dn=1，对所有数据来一次插入排序。
思考：
刚开始接触希尔排序觉得有点麻烦，静下心来思考后就会发现希尔排序比直接插入排序时间复杂度低。首先循环次数将不再是n-2次了，而是将分组的次数。
对于每一次循环时间因为仍然是直接插入排序复杂度仍然是O(n^2)，可是由于进行分组现在的n已经减小了，故Tn总体上也会减小。
而且还有一点，直接插入排序的特点是数组越有序那移动比较次数越少，希尔排序中越往后数组越有序因此效率还会提高。
查阅资料发现希尔排序的时间复杂度是一个关于增量的函数，可以试着计算它的时间复杂度，lbd*d*O((length/d)^2)
可以肯定的是它比O(n^2)快比O(n)慢，速度仅次于快速排序。
*/

//这里将增量d初始化为length的一半，之后每次减半直到1
void ShellSort(int *a, int length){
	int d;				//定义增量
	int i, j;
	int temp;		//暂存量
	int index;		//需要插入的位置
	if (a == NULL || length <= 0)
		return;
	//进行lbd次循环
	for (d = length / 2; d>0; d = d / 2)
	{
		//直接插入排序的循环次数
		for (i = 0; i<d; i++)
		{
			//开始直接插入排序
			for (j = i + d; j<length; j = j + d)
			{
				index = j - d;
				temp = a[j];
				while (temp<a[index] && index >= 0)
				{
					a[index + d] = a[index];
					index = index - d;
				}
				a[index + d] = temp;
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