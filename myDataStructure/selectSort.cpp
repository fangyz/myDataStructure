//选择排序，基本思想是每次选择序列中关键字最小的、此小的......并依次将选中的关键字放入序列左侧的第一个位置、第二个位置直到整个序列依次有序。
//选择排序可分为简单选择排序、堆排序

#include"sort.h"


//一.简单选择排序，每次选择最小的值放入数组的最前面。平均时间复杂度为O(n^2)
void SimpleSelectSort(int *a,int length)
{
	int index;
	int i, j;
	int temp=0;
	for (i = 0; i < length; i++)
	{
		index = i;
		for (j = i; j < length-1; j++)
		{
			if (temp < a[j])
				index = j;
		}
		//得到无序区中最小的值
		if (index != i)
		{
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
}

/*二.堆选择排序
堆的性质如下
1、堆是一颗采用顺序存储的完全二叉树，K1是根节点。可将所有节点序号设置为Kn,满足Ki<=K2i,Ki<=K2i+1；
2、堆的根节点是关键字中最小值(最大值)，称为小根堆(大根堆)；
3、从根节点到每一叶子节点路径上的元素组成的序列都是递减或递增的；
4、堆中的任意子树也是堆。

堆排序步骤如下，假设这里是最小堆
1、对一组待排序的记录，按堆的定义建立堆；
2、取得堆顶最小值后，此时剩下的元素不是堆了，需要重新将剩下的元素构造成堆。
3、不断的重复步骤2，直到全部记录排好序为止。

现在关键问题是：如何建立堆，如何重新构造堆
*/


//声明方法
void GetHeap(int *a, int index, int n);
void Swap(int *a, int i, int j);

/*堆选择排序,该排序时间复杂度主要集中在创建堆和更新堆。
创建堆时有n/2次循环，每次循环因为判断条件使index<n/2故会比较lbn次，时间复杂度也就是nlbn。
更新堆时循环是n-1次，但是每次循环的比较次数为根的深度，而对于n个节点，深度为lbn+1，故时间复杂度仍然是nlbn。
故堆排序时间复杂度是O(nlbn)。
*/
void HeapSelectSort(int *a, int n)
{
	int i;
	//首先建立堆，因为叶子节点本身就是堆，而从第n/2个节点开始所有节点都是叶子节点即堆。
	//因此我们要从n/2开始依次减小直到根节点，然后以这之间的每个节点创建堆，它们的左右孩子节点都已是根
	for (i = n/2; i >=1; i--)
		GetHeap(a, i, n);//构造最大堆
	//每次取出堆顶放到数组的最后面
	for (i = n-1; i>0; i--)
	{
		Swap(a, 0, i);
		//因为现在是交换堆顶后除顶外其余节点都是堆，因此需要重新构造一次堆，不过只需从堆顶开始构造，即第一个节点
		GetHeap(a, 1, i);
	}
}

void GetHeap(int *a, int index, int n){
	int Son;
	//从index节点开始比较当前index节点与左右孩子节点，并形成从index到叶子节点的递减路径
	while (index<=n/2)
	{
		Son = index * 2 - 1;
		//得到左右孩子的最大节点
		if (Son+1 < n){
			if (a[Son + 1] > a[Son])
				Son++;
		}
		//将最大节点与根节点进行比较，如果根节点比最大孩子节点小则进行互换
		if (a[index - 1] < a[Son])
			Swap(a, index - 1, Son);
		index = Son+1;
	}

}

//交换数组a中的两个数
void Swap(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}