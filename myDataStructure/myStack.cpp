#include"myBinaryTree.h"
using namespace std;

BinaryTree *btArrya[20];
int currentPtr=0;
//判断栈是否为空
bool MyStackIsNULL(){
	return currentPtr <= 0 ? true : false;
}

//进栈
void MyPush(BinaryTree* node){
	btArrya[currentPtr] = node;
	currentPtr++;
}
//出栈
BinaryTree* MyPop(){
	BinaryTree* no = btArrya[currentPtr-1];
	btArrya[currentPtr-1] = NULL;
	currentPtr--;
	return no;
}
//返回栈顶
BinaryTree* MyTop(){
	BinaryTree* no = btArrya[currentPtr-1];
	return no;
}

bool IsExit(BinaryTree* node){
	for (int i = 0; i < currentPtr; i++){
		if (btArrya[i] == node)
			return true;
	}
	return false;
}
