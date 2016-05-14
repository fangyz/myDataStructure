#include"myBinaryTree.h"

//�������ķǵݹ����

//�ǵݹ�ǰ��
void FrontTraverse(BinaryTree* root)
{
	if (root == NULL){
		return;
	}
	BinaryTree* node = root;
	while(node!=NULL)
	{
		printf("%d ", node->value);
		if (node->leftTree)                          //�����ǰ�ڵ����ڵ㲻Ϊ��
		{                                    
			MyPush(node);                           //ֻҪ��ǰ�ڵ����ڵ㲻Ϊ�գ��ͽ���ǰ�ڵ����ջ��
			node = node->leftTree;
		}
		else                                                
		{
			//û�����ӽڵ㣬�Ǿ���node�����Һ��ӽڵ�
			if (node->rightTree)
				node = node->rightTree;
			else
				node = MyPop()->rightTree;   //node����ջ�ж�����ָ�룬����ջ
		}
	}
}

//�ǵݹ�����
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
			//ִ�е�����ط�˵��û�����ӽڵ㣬����������󡢸����ң����ֱ������ڵ㡣
			printf("%d ", node->value);
			//�жϽڵ��ǲ���Ҷ�ӽڵ㣬������ǵĻ����ýڵ�����Һ��ӽڵ�
			if (node->rightTree){
				node = node->rightTree;
			}
			else
			{
				node = MyPop();
				printf("%d ", node->value);
				if (node->rightTree)//����ڵ���ҽڵ㲻Ϊnull
					node = node->rightTree;
				else
					node = MyPop();
			}
		}
	}
}


//�������ĺ���ǵݹ����
void NextTraverse(BinaryTree* root)
{
	if (root == NULL)
		return;
	BinaryTree* node = root;
	//���ڵ㲻Ϊ�ջ���ջ��Ϊ��ʱ
	while (node != NULL||!MyStackIsNULL())
	{
		if (node == NULL)
			node = MyTop();
		//ֻҪ�к��ӽڵ�ģ���ô��Ҫ��ջ
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
				//˵���ڵ����������������Ѿ����ˣ���ô�������Һ����Ѿ�ִ���꣬���ڸ��������
				MyPop();
				printf("%d ", node->value);
				//�����ýڵ����ջ���Ľڵ�
				node=MyTop();
			}	

		}
		else
		{
			//˵������ڵ���Ҷ�ӽڵ㣬�������
			printf("%d ", node->value);
			//��Ϊ�Ǻ�����������ҡ�����������ִ������ڵ��Ҫȥִ���ҽڵ㣬
			//����Ҫ��node����ջ���ڵ���ҽڵ�
			if (MyTop()->rightTree == node)
				//����Ҫע��һ������������ڵ���Һ��ӽڵ�ִ�е�����ط���ʱ���������node����ջ���ڵ���Һ��ӽڵ㣬�����������ѭ��
				node = MyTop();
			else
				node = MyTop()->rightTree;
		}
	}
}