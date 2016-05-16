#include"myBinaryTree.h"

//�������ķǵݹ����

//�ǵݹ�ǰ��������ص���� ����ڵ�-��������ڵ�-����ڵ��ָ��ջ���ڵ���ҽڵ�
void FrontTraverse(BinaryTree *root)
{
	BinaryTree *node = root;
	while (node != NULL||!MyStackIsNULL()){
		//����ڵ㣬��ѹջ��������ڵ�
		while (node != NULL){
			printf("%d ", node->value);
			MyPush(node);
			node = node->leftTree;
		}
		if (!MyStackIsNULL()){
			node = MyPop()->rightTree;
		}
	}
}

//�ǵݹ�����������õ�д�����ص��� һֱ������ڵ�ֱ���Ǹ��ڵ�������ڵ㣬Ȼ�����������ջ�����Һ��ӽڵ�
void MiddleTraverse(BinaryTree *root)
{
	if (root == NULL)
		return;
	BinaryTree *node = root;
	while (node != NULL || !MyStackIsNULL()){
		while (node)
		{
			MyPush(node);
			node = node->leftTree;
		}
		//���ڽڵ��ǿյ�
		if (!MyStackIsNULL()){
			node = MyPop();
			printf("%d ", node->value);
			node = node->rightTree;
		}
	}
}

//�������ĺ���ǵݹ����
void NextTraverse(BinaryTree *root)
{
	if (root == NULL)
		return;
	BinaryTree *node = root;
	BinaryTree *pre = NULL;
	MyPush(node);
	//Ҫ����ڵ�������һ��Ҷ�ӽڵ㣬һ��
	while (!MyStackIsNULL())
	{
		node = MyTop();
		if ((node->leftTree == NULL&&node->rightTree == NULL) || (pre != NULL && (pre == node->leftTree || pre == node->rightTree)))
		{
			printf("%d ", node->value);
			MyPop();
			pre = node;
		}
		else
		{
			if (node->rightTree != NULL)
				MyPush(node->rightTree);
			if (node->leftTree != NULL)
				MyPush(node->leftTree);
		}
	}
}