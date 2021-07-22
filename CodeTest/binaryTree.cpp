#include "binaryTree.h"

BinaryTree::BinaryTree()
	:left(nullptr),
	right(nullptr),
	value(-1)
{
}

BinaryTree::~BinaryTree()
{
	left = right = nullptr;
	value = -1;
}

bool BinaryTree::Create()
{
	return true;
}

void BinaryTree::Sort()
{

}

void BinaryTree::PreOrderVisit()
{

}

void BinaryTree::InOrderVisit()
{

}

void BinaryTree::PostOrderVisit()
{

}

bool BinaryTree::Insert(int value)
{
	return false;
}

bool BinaryTree::Delete(int value)
{
	return false;
}

