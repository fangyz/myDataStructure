#include "myBinaryTree.h"

//��ʼ��������
void InitBiTree(BinaryTree* root)
{
	BinaryTree* node1=new BinaryTree();
	BinaryTree* node2=new BinaryTree();
	BinaryTree* node3=new BinaryTree();
	BinaryTree* node4=new BinaryTree();
	BinaryTree* node5=new BinaryTree();
	node1->value=4;
	node2->value=12;
	node3->value=5;
	node4->value=10;
	node5->value=15;
	root->leftTree=node1;
	root->rightTree=node2;
	node1->rightTree=node3;
	node2->leftTree=node4;
	node2->rightTree=node5;
}
//����ݹ����
void RecursionMiddleTraverse(BinaryTree* root)
{
	if(root==NULL)
		return;
	if(root->leftTree)
		MiddleTraverse(root->leftTree);
	printf("%d ",root->value);
	if(root->rightTree)
		MiddleTraverse(root->rightTree);
}

//�����������Ľڵ�
void AddBiTree(BinaryTree* root,int key)
{
	if(root==NULL)
		return;
	BinaryTree* keyNode=new BinaryTree();
	keyNode->value=key;
	BinaryTree* node=root;
	BinaryTree* prevNode=NULL;
	if(key>node->value)
	{
		while(node&&node->value<key)
		{
			prevNode=node;
			node=node->rightTree;
		}
		if(node==NULL)				//node�ڵ��ʱ�п�����NULL
			prevNode->rightTree=keyNode;
		else
		{
			//����node��value�Ǳ�key���
			prevNode->rightTree=keyNode;
			keyNode->rightTree=node;
		}
	}
	else
	{
		while(node&&node->value>key)
		{
			prevNode=node;
			node=node->leftTree;
		}
		if(node==NULL)				//node�ڵ��ʱ�п�����NULL
			prevNode->leftTree=keyNode;
		else
		{
			//����node��value�Ǳ�keyС��
			prevNode->leftTree=keyNode;
			keyNode->leftTree=node;
		}
	}
}
//����һ���ڵ㣬�õ�����ڵ�������Լ����ڵ�
void QueryBiTree(BinaryTree *root,int key,BinaryTree **keyNode,BinaryTree **parentNode)
{
	if(root==NULL)
		return;
	if(root->value==key)
	{
		*keyNode=root;
		return;
	}
	BinaryTree* node=root;
	if(root->leftTree&&root->leftTree->value==key)
	{
			*keyNode=root->leftTree;
			*parentNode=root;
			return;
	}
	if(root->rightTree && root->rightTree->value==key)
	{
			*keyNode=root->rightTree;
			*parentNode=root;
			return;
	}
	if(root->value>key)
		QueryBiTree(root->leftTree,key,keyNode,parentNode);
	if(root->value<key)
		QueryBiTree(root->rightTree,key,keyNode,parentNode);
}
//ɾ��һ���ڵ�
void DeleteBiTree(BinaryTree* root,int key)
{
	if(root==NULL)
		return;
	//�����ҵ�����ڵ�
	bool isLeft=false;
	BinaryTree* keyNode=NULL;
	BinaryTree* parentNode=NULL;
	QueryBiTree(root,key,&keyNode,&parentNode);
	if(parentNode&&parentNode->leftTree==keyNode)
		isLeft=true;
	//1.����ýڵ�����������Ѱ��������������ڵ㣬����ڵ�Ҳ�����Ǹ��ڵ㡣
	if(keyNode->rightTree)
	{
		BinaryTree* leftNode=keyNode->rightTree;
		//�����ɾ���ڵ���Һ��ӽڵ����ڵ�Ϊ��
		if(leftNode->leftTree==NULL)
		{
			//���Һ��ӽڵ��ֵ����keyNode��ɾ��keyNode->rightNode;
			keyNode->value=keyNode->rightTree->value;
			keyNode->rightTree=keyNode->rightTree->rightTree;	
		}
		else
		{
			BinaryTree* parentLeftNode=NULL;
			//��ͣ��Ѱ��������������ڵ�
			while(leftNode->leftTree)
			{
				//leftNode�ĸ��ڵ�
				parentLeftNode=leftNode;
				leftNode=leftNode->leftTree;
			}
			//��ʱleftNode�����������������ڵ㣬Ȼ������ڵ��ֵ����keyNode
			keyNode->value=leftNode->value;
			parentLeftNode->leftTree=leftNode->rightTree;
		}
		delete leftNode;
		return;
	}
	//2.����ýڵ�ֻ��������,����Ҫ��������ۣ���ΪҪɾ���Ľڵ��п����Ǹ��ڵ�
	if(keyNode->leftTree&&keyNode->rightTree==NULL)
	{
		//�����ʱɾ���Ľڵ��Ǹ��ڵ�
		if(parentNode==NULL)
			root=root->leftTree;
		else
		{
			//�����ɾ���ڵ��������Ϊ�գ���ֱ��ȥ������ڵ�
			if(isLeft)
				parentNode->leftTree=keyNode->leftTree;
			else
				parentNode->rightTree=keyNode->leftTree;
			delete keyNode;
		}
		return;
	}
	//3.����ýڵ㱾����Ҷ�ӽڵ�
	if(keyNode->leftTree==NULL&&keyNode->rightTree==NULL)
	{
		//�����ʱ�ڵ��Ǹ��ڵ�
		if(keyNode==root)
			root=NULL;
		else
		{
			if(isLeft)
				parentNode->leftTree=NULL;
			else
				parentNode->leftTree=NULL;
		}
		delete keyNode;
	}
}