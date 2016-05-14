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

//初始化二叉树
void InitBiTree(BinaryTree* root);
//中序遍历
void MiddleTraverse(BinaryTree* root);
//新增二叉树
void AddBiTree(BinaryTree* root, int key);
//查询一个节点
void QueryBiTree(BinaryTree *root, int key, BinaryTree **keyNode, BinaryTree **parentNode);
//删除一个节点
void DeleteBiTree(BinaryTree* root, int key);

//栈数据结构
void MyPush(BinaryTree* node);
BinaryTree* MyPop();
BinaryTree* MyTop();
bool MyStackIsNULL();
bool IsExit(BinaryTree* node);

//二叉树的非递归前序、中序、后序遍历
void FrontTraverse(BinaryTree* root);
void MiddleTraverse(BinaryTree* root);
void NextTraverse(BinaryTree* root);


#endif // MYLIB_H_INCLUDED
