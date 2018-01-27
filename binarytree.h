#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<vector>
#include<queue>

using namespace std;
template<typename Key,typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;
		Node(Key key,Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
		Node(Node* node)
		{
			this->key = node->key;
			this->value =node-> value;
			this->left = node->left;
			this->right= node->right;
		}
	};
	Node *root;
	int count;

public:
	BST()
	{
		root = NULL;
		count = 0;
	};
	~BST()
	{
		destroy(root);
		//todo
	};

	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}
	void insert2( Key key, Value value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			count++;
		}
		else
			 __insert2(root, key, value);
	}
	bool contain(Key key)
	{
		return contain(root, key);
	}
	Value *search( Key key)
	{
		return search(root, key);
	}
	bool isEmpty()
	{
		return (count == 0);
	}
	int size()
	{
		return count;
	}
	void preOrder()//将数组按深度优先打印
	{
		preOrder(root);
	}
	void midOrder()//返回有序数组
	{
		midOrder(root);
	}
	void postOrder()//将数组按深度优先搜索
	{
		postOrder(root);
	}
	void layerOrder()
	{
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			(Node*)node = q.front();
			q.pop;
			cout << node->key << endl;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	Key maximum()
	{
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}
	Key minimum()
	{
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}
	void removeMin()
	{
		if (root)
			root = removeMin(root);
	}
	void removeMax()
	{
		if (root)
			root = removeMax(root);
	}
	void remove(Key key)
	{
		assert(contain(key));
		root = remove(root, key);
	}
private:
	Node * insert(Node *node, Key key, Value value)
	{
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}

		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);
		return node;
	}
	void  __insert2(Node* node, Key key, Value value)
	{
		while (true) {
			if (node->key == key) {
				node->value = value;
				return;
			}
			else if (node->key > key) {
				if (node->left == NULL) {
					node->left = new Node(key, value);
					count++;
					return;
				}
				node = node->left;
			}
			else {
				if (node->right == NULL) {
					node->right = new Node(key, value);
					count++;
					return;
				}
				node = node->right;
			}
		}
	}
	bool contain(Node *node, Key key)
	{
		if (node == NULL)
			return false;
		if (node->key == key)
			return true;
		else if (key<node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}
	Value*search(Node *node, Key key)
	{
		if (node == NULL)
			return NULL;
		if (node->key == key)
			return &(node->value);
		else if (key<node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}
	void preOrder(Node *node)
	{
		if (node != NULL)
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void midOrder(Node *node)
	{
		if (node != NULL)
		{
			midOrder(node->left);
			cout << node->key << endl;
			midOrder(node->right);
		}
	}
	void postOrder(Node *node)
	{
		if (node != NULL)
		{
			midOrder(node->left);
			midOrder(node->right);
			cout << node->key << endl;
		}
	}
	void destroy(Node *node)
	{
		if (node != NULL)
		{
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
	void layerOrder(Node*node)
	{
		if (node != NULL)
		{
			layerOrder(node->left);
		}
	}
	Node* maxnimum(Node* node)
	{
		if (node->right == NULL)
			return node;
		return maximum(node);
	}
	Node* minimum(Node* node)
	{
		if (node->left == NULL)
			return node;
		return minimum(node);
	}
	Node* removeMin(Node* node)
	{
		if (node->left == NULL)
		{
			Node* rightnode = node->right;//返回最小值的右节点
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}
	Node* removeMax(Node* node)
	{
		if (node->right == NULL)
		{
			Node* leftnode = node->left; //返回最大值的左节点
			delete node;
			count--;
			return leftnode;
		}
		node->right = removeMax(node->right);
	}
	Node* remove(Node* node, Key key)
	{
		if (node == NULL)
			return NULL;
		if (key < node->key)
		{
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key)
		{
			node->right = remove(node->right, key);
			return node;
		}
		else // key == node->key
		{
			if (node->left == NULL)
			{
				Node* rightnode = node->right;
				count--;
				delete node;
				return rightnode;
			}
			if (node->right == NULL)
			{
				Node* leftnode = node->left; //返回最大值的左节点
				delete node;
				count--;
				return leftnode;
			}
			// left && right != NULL
			//Node* delnode = node;
			Node* minnode = new Node(minimum(node->right));
			count++;
			minnode->right = removeMin(node->right);
			minnode->left = node->left;
			delete node;
			count--;
			return minnode;
		}
	}
};

#endif // !BINARYTREE_H

//
//#include <iostream>
//#include <vector>
//#include <string>
//#include "FileOps.h"
//
//using namespace std;
//
//template <typename Key, typename Value>
//class BST {
//
//private:
//	struct Node {
//		Key key;
//		Value value;
//		Node *left;
//		Node *right;
//
//		Node(Key key, Value value) {
//			this->key = key;
//			this->value = value;
//			this->left = this->right = NULL;
//		}
//	};
//
//	Node *root;
//	int count;
//
//public:
//	BST() {
//		root = NULL;
//		count = 0;
//	}
//	~BST() {
//		// TODO: ~BST()
//	}
//
//	int size() {
//		return count;
//	}
//
//	bool isEmpty() {
//		return count == 0;
//	}
//
//	void insert(Key key, Value value) {
//		root = insert(root, key, value);
//	}
//
//	bool contain(Key key) {
//		return contain(root, key);
//	}
//
//	Value* search(Key key) {
//		return search(root, key);
//	}
//
//private:
//	// 向以node为根的二叉搜索树中,插入节点(key, value)
//	// 返回插入新节点后的二叉搜索树的根
//	Node * insert(Node *node, Key key, Value value) {
//
//		if (node == NULL) {
//			count++;
//			return new Node(key, value);
//		}
//
//		if (key == node->key)
//			node->value = value;
//		else if (key < node->key)
//			node->left = insert(node->left, key, value);
//		else    // key > node->key
//			node->right = insert(node->right, key, value);
//
//		return node;
//	}
//
//	// 查看以node为根的二叉搜索树中是否包含键值为key的节点
//	bool contain(Node* node, Key key) {
//
//		if (node == NULL)
//			return false;
//
//		if (key == node->key)
//			return true;
//		else if (key < node->key)
//			return contain(node->left, key);
//		else // key > node->key
//			return contain(node->right, key);
//	}
//
//	// 在以node为根的二叉搜索树中查找key所对应的value
//	Value* search(Node* node, Key key) {
//
//		if (node == NULL)
//			return NULL;
//
//		if (key == node->key)
//			return &(node->value);
//		else if (key < node->key)
//			return search(node->left, key);
//		else // key > node->key
//			return search(node->right, key);
//	}
//};
