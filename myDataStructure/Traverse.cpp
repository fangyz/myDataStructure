#include"myBinaryTree.h"

//二叉树的非递归遍历

//非递归前序遍历，重点就是 输出节点-找它的左节点-无左节点就指向栈顶节点的右节点
void FrontTraverse(BinaryTree *root)
{
	BinaryTree *node = root;
	while (node != NULL||!MyStackIsNULL()){
		//输出节点，并压栈，等于左节点
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

//非递归中序遍历更好的写法，重点是 一直找最左节点直至那个节点是最左节点，然后输出并等于栈顶的右孩子节点
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
		//现在节点是空的
		if (!MyStackIsNULL()){
			node = MyPop();
			printf("%d ", node->value);
			node = node->rightTree;
		}
	}
}

//二叉树的后序非递归遍历
void NextTraverse(BinaryTree *root)
{
	if (root == NULL)
		return;
	BinaryTree *node = root;
	BinaryTree *pre = NULL;
	MyPush(node);
	//要输出节点的情况：一是叶子节点，一是
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