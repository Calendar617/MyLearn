#include "RBTree.h"

template<class T>
RBTree<T>::RBTree() : mRoot(NULL)
{

}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

template<class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if (tree)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

template<class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
	if (tree)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

template<class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
	if (tree)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}

template<class T>
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}

template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if (x == NULL || x->key == key)
	{
		return x;
	}

	if (key < x->key)
	{
		return search(x->left, key);
	}
	else
	{
		return search(x->right, key);
	}
}

template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);
}

template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	while (x && x->key != key)
	{
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}


template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
}

template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->left)
	{
		tree = tree->left;
	}
	return tree;
}
         
template<class T>
T RBTree<T>::minimum()
{
	RBTNode<T>* p = minimum(mRoot);
	if (p != NULL)
	{
		return p->key;
	}
	return (T)NULL;
}

template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->right)
	{
		tree = tree->right;
	}
	return tree;
}

template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T>* p = maximum(mRoot);
	if (p != NULL)
	{
		return p->key;
	}
	return (T)NULL;
}

template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
{
	if (x->right)
	{
		return minimum(x->right);
	}
	RBTNode<T>* y = x->parent;
	while (y && y->right == x)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
{
	if (x->left)
	{
		return maximum(x->left);
	}
	RBTNode<T>* y = x->parent;
	while (y && y->left == x)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->right;
	x->right = y->left;
	if (y->left)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}
	x->parent = y;
	y->left = x;
}

template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	RBTNode<T>* y = x->left;
	x->left = y->right;
	if (y->right)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}
	y->right = x;
	x->parent = y;
}

//����ڵ�
//1.����²���Ľڵ�û�и��ڵ㣬��ֱ�ӵ������ڵ���룬ͬʱ������ɫΪ��ɫ
//2.������ڵ�Ϊ��ɫ�������ڵ�Ϊ���ڵ�����ӽڵ㣬ֱ�Ӳ��룬������
//3.������ڵ� A ���常�ڵ� B ���Ǻ�ɫ��үү�ڵ� C �Ǻ�ɫ������ֱ�Ӳ���
//  ���� A �� B Ϊ��ɫ������ C Ϊ��ɫ�����������ˣ����� C �ڵ�ĸ��ڵ����
//  �Ǻ�ɫ����Ҫ������ϵ���

template<class T>
void RBTree<T>::insertFixup(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* parent, * gparent;
	//�����ڵ���ڣ��Ҹ��ڵ����ɫ�Ǻ�ɫ
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);
		//�����ڵ����游�ڵ������
		if (parent == gparent->left)
		{
			//case 1 ; ����ڵ��Ǻ�ɫ
			RBTNode<T>* uncle = gparent->right;
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(parent);
				rb_set_black(uncle);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			else
			{
				//case 2: �����Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
				if (node == parent->right)
				{
					leftRotate(root, parent);
					RBTNode<T>* tmp = parent;
					parent = node;
					node = tmp;
				}
				//case 3: �����Ǻ�ɫ���ҵ�ǰ�ڵ�������
				rb_set_black(parent);
				rb_set_red(gparent);
				rightRotate(root, gparent);
			}
		}
		else
		{
			RBTNode<T>* uncle = gparent->left;
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(parent);
				rb_set_black(uncle);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			else
			{
				if (node == parent->left)
				{
					rightRotate(root, parent);
					RBTNode<T>* tmp = parent;
					parent = node;
					node = tmp;
				}
				rb_set_black(parent);
				rb_set_red(gparent);
				leftRotate(root, gparent);
			}
		}
	}
	rb_set_black(root);
}

template<class T>
void RBTree<T>::insert(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* y = NULL;
	RBTNode<T>* x = root;
	while (x != NULL)
	{
		y = x;
		if (node->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}
	}
	else
	{
		root = node;
	}
	//���ýڵ���ɫΪ��ɫ
	node->color = RED;
	//����Ϊ���������
	insertFixup(root, node);
}

template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = NULL;
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
	{
		return;
	}
	insert(mRoot, z);
}

template<class T>
void RBTree<T>::removeFixup(RBTNode<T>*& root, RBTNode<T>* node)
{
	while (node != root && rb_is_black(node))
	{
		RBTNode<T>* parent = rb_parent(node);
		if (node == parent->left)
		{
			RBTNode<T>* other = parent->right;
			if (rb_is_red(other))
			{
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->right;
			}
			if (rb_is_black(other->left) && rb_is_black(other->right))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (rb_is_black(other->right))
				{
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(other->right);
				rb_set_black(parent);
				leftRotate(root, parent);
				node = root;
			}
		}
		else
		{
			RBTNode<T>* other = parent->left;
			if (rb_is_red(other))
			{
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if (rb_is_black(other->left) && rb_is_black(other->right))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (rb_is_black(other->left))
				{
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(other->left);
				rb_set_black(parent);
				rightRotate(root, parent);
				node = root;
			}
		}
	}
	rb_set_black(node);
}

template<class T>
void RBTree<T>::remove(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* pnode, * rnode;
	if (node->left == NULL || node->right == NULL)
	{
		pnode = node;
	}
	else
	{
		pnode = successor(node);
	}
	if (pnode->left)
	{
		rnode = pnode->left;
	}
	else
	{
		rnode = pnode->right;
	}
	rnode->parent = pnode->parent;
	if (pnode->parent == NULL)
	{
		root = node;
	}
	else
	{
		if (pnode = pnode->parent->left)
		{
			pnode->parent->left = rnode;
		}
		else
		{
			pnode->parent->right = rnode;
		}
	}
	if (node != pnode)
	{
		node->key = pnode->key;
	}
	if (pnode->color == BLACK)
	{
		removeFixup(root, rnode);
	}
	delete pnode;
}

template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T>* node;
	if ((node = search(mRoot, key)) != NULL)
	{
		remove(mRoot, node);
	}
}

template<class T>
void RBTree<T>::destroy(RBTNode<T>*& tree)
{
	if (tree == NULL)
	{
		return;
	}
	if (tree->left != NULL)
	{
		return destroy(tree->left);
	}
	if (tree->right != NULL)
	{
		return destroy(tree->left);
	}
	delete tree;
	tree = NULL;
}

template<class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

template<class T>
void RBTree<T>::print(RBTNode<T>* root, T key, int direction)
{

}

template<class T>
void RBTree<T>::print()
{
	if (mRoot)
	{
		print(mRoot, mRoot->key, 0);
	}
}