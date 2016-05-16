#include"myBinaryTree.h"
#include"sort.h"

/*
这是一个关于数据结构的基本操作，包括链表的操作、查找、排序、树的学习。
*/

//操作二叉树
void OperateBTree()
{
	BinaryTree* root = new BinaryTree();
	root->value = 6;
	//初始化二叉排序树
	InitBiTree(root);

	//新增节点
	AddBiTree(root, 3);
	//MiddleTraverse(root);
	//printf("\n");
	AddBiTree(root, 9);
	//MiddleTraverse(root);
	//printf("\n");

	//删除节点
	//DeleteBiTree(root,3);
	//DeleteBiTree(root,4);
	//DeleteBiTree(root,5);
	//DeleteBiTree(root,6);
	//DeleteBiTree(root,9);
	//DeleteBiTree(root, 12);
	//MiddleTraverse(root);
	//FrontTraverse(root);
	//MiddleTraverse(root);
	NextTraverse(root);
	printf("\n");
}

void Sort()
{
	int aArray[8] = { 4, 5, 2, 43, 21, 25, 11, 1 };
	int bArray[9] = { 2, 6, 5, 4, 21, 25, 11, 1, 18 };
	int length = 9;

	for (int i = 0; i < length; i++)
	{
		printf("%d ", bArray[i]);
	}
	printf("\n");
	//归并排序
	//MergeSort(bArray, length);

	//选择排序
	//SimpleSelectSort(bArray, length);
	//HeapSelectSort(bArray, length);

	//插入排序
	//DirectInsertSort(bArray, length);
	//HalfInsertSort(bArray, length);
	//ShellSort(bArray, length);
	//BetterShellSort(bArray, length);

	//交换排序
	//BubbleSort(bArray, length);
	BetterBubbleSort(bArray, length);
	QuickSort(bArray, 0, length);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", bArray[i]);
	}
	printf("\n");
}

void main()
{
	//操作二叉树
	OperateBTree();

   //排序操作
	//Sort();

}
