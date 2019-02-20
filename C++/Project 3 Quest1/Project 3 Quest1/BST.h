#pragma once
#include "stdafx.h"
using namespace std;

template <class T>
struct Node {
	T value ;
	int distance1 = 0;
	int distance2 = 0;
	Node *left = nullptr;
	Node *right = nullptr;

	Node(T val, int distance, int distance2) {
		this->value = val;
		this->distance1 = distance;
		this->distance2 = distance2;
	}

	Node(T val, Node<T> left, Node<T> right) {
		this->value = val;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class BST {

private:
	Node<T> *root;

	void addHelper(Node<T> *root, T val, int distance, int distance2) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val, distance, distance2);
			}
			else {
				addHelper(root->left, val, distance, distance2);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val, distance, distance2);
			}
			else {
				addHelper(root->right, val, distance, distance2);
			}
		}
	}

	void printHelper(Node<T> *root) {
		if (!root) return;
		printHelper(root->left);
		cout << "City: " << root->value.c_str() << " X co-ordinate: " << root->distance1 << " Y co-ordinate: " << root->distance2 << endl;
		printHelper(root->right);
	}

	int nodesCountHelper(Node<T> *root) {
		if (!root) return 0;
		else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
	}

	int heightHelper(Node<T> *root) {
		if (!root) return 0;
		else return 1 + max(heightHelper(root->left), heightHelper(root->right));
	}

	void printMaxPathHelper(Node<T> *root) {
		if (!root)
		{
			cout << endl;
			return;
		}
		cout << root->value.c_str() << "  ";
		if (heightHelper(root->left) > heightHelper(root->right)) {
			printMaxPathHelper(root->left);
		}
		else {
			printMaxPathHelper(root->right);
		}
	}

	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

public:
	void add(T val, int distance1, int distance2) {
		if (root) {
			this->addHelper(root, val, distance1, distance2);
		}
		else {
			root = new Node<T>(val, distance1, distance2);
		}
	}

	void print() {
		printHelper(this->root);
	}

	int nodesCount() {
		return nodesCountHelper(root);
	}

	int height() {
		return heightHelper(this->root);
	}

	void printMaxPath() {
		printMaxPathHelper(this->root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->root, value);
	}
};