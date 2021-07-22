#pragma once

// �������ṹ
class BinaryTree
{
public:
	BinaryTree();

	virtual ~BinaryTree();

	bool Create();

	void Sort();

	//�������
	static void PreOrderVisit();

	//�������
	static void InOrderVisit();

	//�������
	static void PostOrderVisit();

	bool Insert(int value);

	bool Delete(int value);

private:
	BinaryTree* left;
	BinaryTree* right;

	int value;
};