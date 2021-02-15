#include "MyBinarySearchTree.h"

void MyBinarySearchTree::insert(int data) {
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		Node* current = root, * parent = nullptr;
		while (1) {
			parent = current;
			if (data < parent->data) {
				current = current->leftChild;
				if (current == nullptr) {
					parent->leftChild = new Node(data);
					return;
				}
			}
			else {
				current = current->rightChild;
				if (current == nullptr) {
					parent->rightChild = new Node(data);
					return;
				}
			}
		}
	}
}

void MyBinarySearchTree::inorder_traversal()
{
}
