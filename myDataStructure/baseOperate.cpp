#include "myBinaryTree.h"

//初始化二叉树
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
//中序递归遍历
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

//新增二叉树的节点
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
		if(node==NULL)				//node节点此时有可能是NULL
			prevNode->rightTree=keyNode;
		else
		{
			//现在node的value是比key大的
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
		if(node==NULL)				//node节点此时有可能是NULL
			prevNode->leftTree=keyNode;
		else
		{
			//现在node的value是比key小的
			prevNode->leftTree=keyNode;
			keyNode->leftTree=node;
		}
	}
}
//查找一个节点，得到这个节点的引用以及父节点
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
//删除一个节点
void DeleteBiTree(BinaryTree* root,int key)
{
	if(root==NULL)
		return;
	//首先找到这个节点
	bool isLeft=false;
	BinaryTree* keyNode=NULL;
	BinaryTree* parentNode=NULL;
	QueryBiTree(root,key,&keyNode,&parentNode);
	if(parentNode&&parentNode->leftTree==keyNode)
		isLeft=true;
	//1.如果该节点有右子树，寻找右子树的最左节点，这个节点也可能是根节点。
	if(keyNode->rightTree)
	{
		BinaryTree* leftNode=keyNode->rightTree;
		//如果被删除节点的右孩子节点的左节点为空
		if(leftNode->leftTree==NULL)
		{
			//将右孩子节点的值赋给keyNode并删除keyNode->rightNode;
			keyNode->value=keyNode->rightTree->value;
			keyNode->rightTree=keyNode->rightTree->rightTree;	
		}
		else
		{
			BinaryTree* parentLeftNode=NULL;
			//不停的寻找右子树的最左节点
			while(leftNode->leftTree)
			{
				//leftNode的父节点
				parentLeftNode=leftNode;
				leftNode=leftNode->leftTree;
			}
			//此时leftNode则是右子树里的最左节点，然后将这个节点的值赋给keyNode
			keyNode->value=leftNode->value;
			parentLeftNode->leftTree=leftNode->rightTree;
		}
		delete leftNode;
		return;
	}
	//2.如果该节点只有左子树,这里要分情况讨论，因为要删除的节点有可能是根节点
	if(keyNode->leftTree&&keyNode->rightTree==NULL)
	{
		//如果此时删除的节点是根节点
		if(parentNode==NULL)
			root=root->leftTree;
		else
		{
			//如果被删除节点的右子树为空，则直接去掉这个节点
			if(isLeft)
				parentNode->leftTree=keyNode->leftTree;
			else
				parentNode->rightTree=keyNode->leftTree;
			delete keyNode;
		}
		return;
	}
	//3.如果该节点本身是叶子节点
	if(keyNode->leftTree==NULL&&keyNode->rightTree==NULL)
	{
		//如果此时节点是根节点
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