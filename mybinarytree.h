#pragma once
#ifndef  MYBINARYTREE_H
#define MYBINARYTREE_H

using namespace std;
template<typename Key,typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = nullptr;
		}
		Node(Node* node)
		{
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};
	Node* root;
	int count;
public:
	BST()
	{
		root = nullptr;
		count = 0;
	};
//	~BST();
	int size()
	{
		return count;
	}
	bool isempty()
	{
		return count == 0;
	}
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}
	bool contain(Key key)
	{
		return contain(root, key);
	}
	Value* search(Key key)
	{
		return search(root, key);
	}
	void preOrder()
	{
		preOrder(root);
	}
	void midOrder()
	{
		midOrder(root);
	}

private:
	Node * insert(Node* node, Key key, Value value)
	{
		if (node == nullptr)
		{
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
		{
			node->value = value;
		}
		else if (key < node->key)
		{
			node->left = insert(node->left, key, value); //更新左子树
		}
		else
			node->right = insert(node->right, key, value);//更新右子树
		return node;
	}
	bool contain(Node* node, Key key)
	{
		if (node == nullptr)
			return false;
		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left,key);
		else
			return contain(node->right,key);
	}
	Value* search(Node* node, Key key)
	{
		if (node == nullptr)
			return nullptr;
		if (key == node->key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left,key);
		else
			return search(node->right,key);

	}
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->value<<endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void midOrder(Node* node)
	{
		if (node != nullptr)
		{
			midOrder(node->left);
			cout << node->value << endl;
			midOrder(node->right);
		}
	}
};

#endif // ! MYBINARYTREE_H
