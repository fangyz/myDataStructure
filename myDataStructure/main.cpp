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
	//��ʼ��������
	InitBiTree(root);

	//�����ڵ�9,5
	AddBiTree(root, 3);
	MiddleTraverse(root);
	printf("\n");
	AddBiTree(root, 9);
	MiddleTraverse(root);
	printf("\n");

	//ɾ���ڵ�
	//DeleteBiTree(root,3);
	//DeleteBiTree(root,4);
	//DeleteBiTree(root,5);
	//DeleteBiTree(root,6);
	//DeleteBiTree(root,9);
	DeleteBiTree(root, 12);
	MiddleTraverse(root);
	printf("\n");
}

void Sort()
{
	int aArray[8] = { 4, 5, 2, 43, 21, 25, 11, 1 };
	int bArray[9] = { 4, 5, 2, 43, 21, 25, 11, 1, 18 };
	//��������
	MergeSort(bArray, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", bArray[i]);
	}
}

void main()
{
	//����������
	//OperateBTree();

   //�������
	Sort();

}
