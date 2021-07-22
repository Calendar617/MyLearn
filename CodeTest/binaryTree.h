#pragma once

// 二叉树结构
class BinaryTree
{
public:
	BinaryTree();

	virtual ~BinaryTree();

	bool Create();

	void Sort();

	//先序遍历
	static void PreOrderVisit();

	//中序遍历
	static void InOrderVisit();

	//后序遍历
	static void PostOrderVisit();

	bool Insert(int value);

	bool Delete(int value);

private:
	BinaryTree* left;
	BinaryTree* right;

	int value;
};