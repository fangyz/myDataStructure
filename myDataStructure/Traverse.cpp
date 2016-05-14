#include"myBinaryTree.h"

//二叉树的非递归遍历

//非递归前序
void FrontTraverse(BinaryTree* root)
{
	if (root == NULL){
		return;
	}
	BinaryTree* node = root;
	while(node!=NULL)
	{
		printf("%d ", node->value);
		if (node->leftTree)                          //如果当前节点的左节点不为空
		{                                    
			MyPush(node);                           //只要当前节点的左节点不为空，就将当前节点放入栈中
			node = node->leftTree;
		}
		else                                                
		{
			//没有左孩子节点，那就让node等于右孩子节点
			if (node->rightTree)
				node = node->rightTree;
			else
				node = MyPop()->rightTree;   //node等于栈中顶部的指针，并出栈
		}
	}
}

//非递归中序
void MiddleTraverse(BinaryTree* root)
{
	if (root == NULL)
		return;
	BinaryTree* node = root;
	while (node != NULL)
	{
		if (node->leftTree)                          
		{
			MyPush(node);                          
			node = node->leftTree;
		}
		else                                                
		{
			//执行到这个地方说明没有左孩子节点，中序遍历是左、根、右，因此直接输出节点。
			printf("%d ", node->value);
			//判断节点是不是叶子节点，如果不是的话就让节点等于右孩子节点
			if (node->rightTree){
				node = node->rightTree;
			}
			else
			{
				node = MyPop();
				printf("%d ", node->value);
				if (node->rightTree)//如果节点的右节点不为null
					node = node->rightTree;
				else
					node = MyPop();
			}
		}
	}
}


//二叉树的后序非递归遍历
void NextTraverse(BinaryTree* root)
{
	if (root == NULL)
		return;
	BinaryTree* node = root;
	//当节点不为空或者栈不为空时
	while (node != NULL||!MyStackIsNULL())
	{
		if (node == NULL)
			node = MyTop();
		//只要有孩子节点的，那么就要入栈
		if ((node->leftTree || node->rightTree))
		{
			if (IsExit(node) == false){
				MyPush(node);
				if (node->leftTree)
					node = node->leftTree;
				else
					node = node->rightTree;
			}
			else
			{
				//说明节点有左、右子树，且已经入账，那么它的左右孩子已经执行完，现在该输出它了
				MyPop();
				printf("%d ", node->value);
				//现在让节点等于栈顶的节点
				node=MyTop();
			}	

		}
		else
		{
			//说明这个节点是叶子节点，进行输出
			printf("%d ", node->value);
			//因为是后序遍历，左、右、根，故首先执行完左节点后要去执行右节点，
			//所以要让node等于栈顶节点的右节点
			if (MyTop()->rightTree == node)
				//但是要注意一种情况，当根节点的右孩子节点执行到这个地方的时候，如果还让node等于栈顶节点的右孩子节点，则它会进入死循环
				node = MyTop();
			else
				node = MyTop()->rightTree;
		}
	}
}