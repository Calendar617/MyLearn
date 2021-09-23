#pragma once

/// 源码出自
/// https://www.cnblogs.com/alantu2018/p/8462017.html
/// 内含代码解释

#include <iostream>
#include <iomanip>

using namespace std;

enum RBTColor
{
	RED,
	BLACK
};

template<class T>
class RBTNode
{
public:
	T key;
	RBTColor color;
	RBTNode* parent;
	RBTNode* left;
	RBTNode* right;
	RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r):
		key(value), color(c), parent(),left(l), right(r)
	{}
};

//1. 每个节点都是黑色或者红色
//2. 根节点是黑色
//3. 每个叶子节点都是黑色（为空的叶子节点）
//4. 如果一个节点是红色，则它的子节点必须是黑色
//5. 从一个节点到该节点的子孙节点所有路径包含相同数目的黑节点

template<class T>
class RBTree
{
private:
	RBTNode<T>* mRoot;
public:
	RBTree();
	~RBTree();

	void preOrder();

	void inOrder();

	void postOrder();

	RBTNode<T>* search(T key);

	RBTNode<T>* iterativeSearch(T key);

	T minimum();

	T maximum();

	RBTNode<T>* successor(RBTNode<T>* x);

	RBTNode<T>* predecessor(RBTNode<T>* x);

	void insert(T key);

	void remove(T key);

	void destroy();

	void print();

private:
	void preOrder(RBTNode<T>* root) const;
	
	void inOrder(RBTNode<T>* root) const;

	void postOrder(RBTNode<T>* root) const;


	RBTNode<T>* search(RBTNode<T>* root, T key) const;

	RBTNode<T>* iterativeSearch(RBTNode<T>* root, T key) const;

	RBTNode<T>* minimum(RBTNode<T>* root);

	RBTNode<T>* maximum(RBTNode<T>* root);

	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);

	void rightRotate(RBTNode<T>*& root, RBTNode<T>* x);

	void insert(RBTNode<T>*& root, RBTNode<T>* node);

	void remove(RBTNode<T>*& root, RBTNode<T>* node);

	void insertFixup(RBTNode<T>*& root, RBTNode<T>* node);

	void removeFixup(RBTNode<T>*& root, RBTNode<T>* node);

	void destroy(RBTNode<T>*& root);

	void print(RBTNode<T>* root, T key, int direction);

#define rb_parent(r)  ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_black(r) do {(r)->color == BLACK;} while(0)
#define rb_set_red(r) do {(r)->color == RED;} while(0)
#define rb_set_parent(r, p) do{(r)->parent = (p);} while(0)
#define rb_set_color(r, c)  do {(r)->color == c;} while(0)
};

