#include"myBinaryTree.h"
#include"sort.h"

/*
����һ���������ݽṹ�Ļ�����������������Ĳ��������ҡ���������ѧϰ��
*/

//����������
void OperateBTree()
{
	BinaryTree* root = new BinaryTree();
	root->value = 6;
	//��ʼ������������
	InitBiTree(root);

	//�����ڵ�
	AddBiTree(root, 3);
	//MiddleTraverse(root);
	//printf("\n");
	AddBiTree(root, 9);
	//MiddleTraverse(root);
	//printf("\n");

	//ɾ���ڵ�
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
	//�鲢����
	//MergeSort(bArray, length);

	//ѡ������
	//SimpleSelectSort(bArray, length);
	//HeapSelectSort(bArray, length);

	//��������
	//DirectInsertSort(bArray, length);
	//HalfInsertSort(bArray, length);
	//ShellSort(bArray, length);
	//BetterShellSort(bArray, length);

	//��������
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
	//����������
	OperateBTree();

   //�������
	//Sort();

}
