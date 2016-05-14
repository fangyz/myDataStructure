#include"myBinaryTree.h"
using namespace std;

BinaryTree *btArrya[20];
int currentPtr=0;
//�ж�ջ�Ƿ�Ϊ��
bool MyStackIsNULL(){
	return currentPtr > 0 ? true : false;
}

//��ջ
void MyPush(BinaryTree* node){
	btArrya[currentPtr] = node;
	currentPtr++;
}
//��ջ
BinaryTree* MyPop(){
	BinaryTree* no = btArrya[currentPtr];
	btArrya[currentPtr] = NULL;
	currentPtr--;
	return no;
}
//����ջ��
BinaryTree* MyTop(){
	BinaryTree* no = btArrya[currentPtr];
	return no;
}

bool IsExit(BinaryTree* node){
	for (int i = 0; i < currentPtr; i++){
		if (btArrya[i] == node)
			return true;
	}
	return false;
}
