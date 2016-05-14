#include"myBinaryTree.h"
using namespace std;

BinaryTree *btArrya[20];
int currentPtr=0;
//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool MyStackIsNULL(){
	return currentPtr > 0 ? true : false;
}

//½øÕ»
void MyPush(BinaryTree* node){
	btArrya[currentPtr] = node;
	currentPtr++;
}
//³öÕ»
BinaryTree* MyPop(){
	BinaryTree* no = btArrya[currentPtr];
	btArrya[currentPtr] = NULL;
	currentPtr--;
	return no;
}
//·µ»ØÕ»¶¥
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
