#pragma once

#include "_includes.h"

// How to add new node type?
// 1. Define new node type class derived from ITreeNode
// 2. Add visit method for new node type to ITreeVisitor and existing concrete visitors

// How to add new visitor?
// 1. Derive from ITreeVisitor and implement visit methods for all known node types

class TreeNode1;
class TreeNode2;
class TreeNode3;

class ITreeVisitor {
public:
	virtual void visit(TreeNode1* tn) = 0;
	virtual void visit(TreeNode2* tn) = 0;
	virtual void visit(TreeNode3* tn) = 0;
};

class ITreeNode {
private:
	ITreeNode* parent;
	std::list<ITreeNode*> children;

	void setParent(ITreeNode* p) {
		parent = p;
	};

public:
	ITreeNode() : parent(nullptr) {};

	[[nodiscard]] virtual std::string getType() const = 0;
	virtual void acceptVisitor(ITreeVisitor* v) = 0;

	void addChild(ITreeNode* c) {
		children.push_back(c);
		c->setParent(this);
	};

	[[nodiscard]] const std::list<ITreeNode*>& getChildren() const { 
		return children;
	};
};

class TreeNode1 : public ITreeNode {
private:
	std::string data;

public:
	TreeNode1() : data("1") {};

	[[nodiscard]] std::string getType() const override {
		return "Node 1";
	};

	void acceptVisitor(ITreeVisitor* v) override {
		v->visit(this);
	};

	void setData(const std::string& d) {
		data = d;
	};
	
	const std::string& getData() const {
		return data;
	};
};

class TreeNode2 : public ITreeNode {
private:
	int data;

public:
	TreeNode2() : data(2) {};

	[[nodiscard]] std::string getType() const override {
		return "Node 2";
	};

	void acceptVisitor(ITreeVisitor* v) override {
		v->visit(this);
	};

	void setData(int d) {
		data = d;
	};
	
	[[nodiscard]] int getData() const {
		return data;
	};
};

class TreeNode3 : public ITreeNode {
private:
	char data;

public:
	TreeNode3() : data('3') {};

	[[nodiscard]] std::string getType() const override {
		return "Node 3";
	};
	
	void acceptVisitor(ITreeVisitor* v) override {
		v->visit(this);
	};

	void setData(char d) {
		data = d;
	};
	
	[[nodiscard]] char getData() const {
		return data;
	};
};

class TreeVisitor1 : public ITreeVisitor {
public:
	void visit(TreeNode1* tn) override {
		std::cout << "Visitor 1 # node type: " + tn->getType() + ", node data: " + tn->getData() + "\n";
	};
	
	void visit(TreeNode2* tn) override {
		std::cout << "Visitor 1 # node type: " + tn->getType() + ", node data: " + std::to_string(tn->getData()) + "\n";
	};
	
	void visit(TreeNode3* tn) override {
		std::cout << "Visitor 1 # node type: " + tn->getType() + ", node data: " + tn->getData() + "\n";
	};
};

class TreeVisitor2 : public ITreeVisitor {
public:
	void visit(TreeNode1* tn) override {
		std::cout << "Visitor 2 # node type: " + tn->getType() + ", node data: " + tn->getData() + "\n";
	};
	
	void visit(TreeNode2* tn) override {
		std::cout << "Visitor 2 # node type: " + tn->getType() + ", node data: " + std::to_string(tn->getData()) + "\n";
	};

	void visit(TreeNode3* tn) override {
		std::cout << "Visitor 2 # node type: " + tn->getType() + ", node data: " + tn->getData() + "\n";
	};
};

// Visit tree nodes recursively
void visitTree(ITreeNode* tn, std::list<ITreeVisitor*>* visitors) {
	for (const auto v : *visitors) {
		tn->acceptVisitor(v);
	}

	if (!tn->getChildren().empty()) {
		for (const auto& child : tn->getChildren()) {
			visitTree(child, visitors);
		}
	}
}
