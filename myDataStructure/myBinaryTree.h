#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

struct BinaryTree{
	int value;
	BinaryTree* leftTree;
	BinaryTree* rightTree;
	BinaryTree()
	{
		leftTree = NULL;
		rightTree = NULL;
	}
};

//��ʼ��������
void InitBiTree(BinaryTree* root);
//�������
void MiddleTraverse(BinaryTree* root);
//����������
void AddBiTree(BinaryTree* root, int key);
//��ѯһ���ڵ�
void QueryBiTree(BinaryTree *root, int key, BinaryTree **keyNode, BinaryTree **parentNode);
//ɾ��һ���ڵ�
void DeleteBiTree(BinaryTree* root, int key);

//ջ���ݽṹ
void MyPush(BinaryTree* node);
BinaryTree* MyPop();
BinaryTree* MyTop();
bool MyStackIsNULL();
bool IsExit(BinaryTree* node);

//�������ķǵݹ�ǰ�����򡢺������
void FrontTraverse(BinaryTree* root);
void MiddleTraverse(BinaryTree* root);
void NextTraverse(BinaryTree* root);


#endif // MYLIB_H_INCLUDED
