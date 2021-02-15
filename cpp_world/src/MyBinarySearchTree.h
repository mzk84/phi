#pragma once
#include "_std_includes.h"

struct Node {
	int data;
	Node* parent, *leftChild, *rightChild;
	explicit Node(int d) : data(d), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {};
};

class MyBinarySearchTree {
private:
	Node* root;

public:
	MyBinarySearchTree() : root(nullptr) { };

	void insert(int data);
	void inorder_traversal();

};
