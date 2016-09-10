/*
交换排序，其核心思想是循环比较中对数据进行交换已达到关键字移动的目的，交换排序包括冒泡排序和快速排序。
*/

#include"sort.h"

//冒泡排序，时间复杂度为O(n^2)
void BubbleSort(int *a, int length)
{
	if (a == NULL || length<0)
		return;
	int i,j;
	int temp;
	for (i = length-1; i > 0; i--){
		for (j = 0; j < i; j++)
		{
			//一次执行将最大的数交换到最后面
			if (a[j]>a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//优化后的冒泡排序
void BetterBubbleSort(int *a, int length)
{
	if (a == NULL || length<0)
		return;
	int i, j;
	int temp;
	int isChange=0,m;
	for (i = length - 1; i > 0; i=m){
		for (j = 0; j < i; j++)
		{
			//一次执行将最大的数交换到最后面
			if (a[j]>a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				isChange = 1;	//优化点1：//如果一次循环中没有数进行交换那说明已经有序了，
				m = j;			    //优化点2：//里面的for执行完毕后此时的j说明j到i之间的数据已经有序了，j以前的数据可能还不是有序的。
			}
		}
		if (isChange == 0)
			break;
	}
}

/*
快速排序,可以看到它的时间复杂度主要集中在外面的while循环，这个循环的作用是进行比较找到一个位置s将数组分为0~s和s~length，也就是说快速排序的时间复杂度集中在划分区域上。
在划分区域时，首先就算划分了区域，但还是要对这一整个数组进行比较，比较的次数是一个n阶函数，接下来重点就是划分的次数了。
最好情况下如果每次都是划分的中间的区域，那么划分次数为lbn，最坏情况下如果每次划分有一个区域是空的，那将会划分n-1次，故时间复杂度最坏O(n^2)，最好是O(lbn)。
至于为什么平均时间复杂度为O(nlbn)课本上写了一大堆计算公式然而暂时并没有看懂。。。。
*/
void QuickSort(int *a, int start, int end)
{
	if (a == NULL || start < 0 || (start>=end))
		return;
	int s = start, e = end - 1;
	int index;
	int value = a[s];
	while (s < e){
		//一定要注意这个地方加=，因为如果不加的话，就是死循环了。
		//这个地方还有一点要注意，那就是要加上s<e，因为条件是大于或等于，那么这时有可能e会小于s。
		while (a[e]>=value&&s<e)
			e--;
		//现在执行到这个地方说明a[e]<value了，所以要让a[s]=a[e],a[e]=value,但是这里只对a[s]进行了赋值，
		//原因是在循环中，让a[s]=a[e]后，接下来的while循环能够继续执行，当遇到a[s]>value时，此时进行替换的是a[e]，即将大的数放到e这个地方。
		//这样可以发现让a[s]=a[e]后就可以让s向前增加，当s增加到a[s]>value时便让a[e]=a[s]，这样下一次while循环中a[e]便大于value了额，e就可以向后减少了。
		a[s] =a[e];
		while (a[s] <= value&&s<e)
			s++;
		a[e] = a[s];
		//我们还可以发现每次执行到这个地方的时候，数组中有2个重复值，
		//那就是a[e]==a[s]>value，如果不满足s<e跳出循环那就要让a[s]=value。
	}
	a[s] = value;
	if (s < end - 1)
		QuickSort(a, s + 1, end);
	if (s>start + 1)
		QuickSort(a, start, s);
}