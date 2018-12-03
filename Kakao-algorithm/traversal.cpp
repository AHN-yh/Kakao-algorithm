#include <stack>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Node {
public:
	Node *left;
	Node *right;
	char data;
public:
	char getData() {
		return data;
	}
	void setData(char data) {
		this->data = data;
	}
	void setLeft(Node *left) {
		this->left = left;
	}
	void setRight(Node *right) {
		this->right = right;
	}
	Node *getRight() {
		return this->right;
	}
	Node * getLeft() {
		return this->left;
	}
	Node(char n) {
		this->data = n;
	}
};

class Graph {
public:
	Node *top;
	int size;
};

void visit(Node* v) {
	cout << v->getData();
}

void PreOrder(Node *v) {
	if (v == NULL) {
		return;
	}
	visit(v);
	PreOrder(v->getLeft());
	PreOrder(v->getRight());
}

void InOrder(Node *v) {
	if (v == NULL) {
		return;
	}
	InOrder(v->getLeft());
	visit(v);
	InOrder(v->getRight());
}

void PostOrder(Node *v) {
	if (v == NULL) {
		return;
	}
	PostOrder(v->getLeft());
	PostOrder(v->getRight());
	visit(v);
}

void search(Node *v) {
	if (v == NULL)
		return;


}

int solve_1991() {
	int T;
	cin >> T;
	Graph *graph = new Graph();
	graph->size = T;
	for (int i = 0; i < T; i++) {
		char data1, data2, data3;
		Node *cur = graph->top;
		cin >> data1 >> data2 >> data3;


		if (data1 == '.') {
			return 0;
		}
		Node *newN = new Node(data1);

		if (data2 == '.') {
			newN->setLeft(NULL);
		}
		else {
			Node *newL = new Node(data2);
			newN->setLeft(newL);
		}

		if (data3 == '.') {
			newN->setRight(NULL);
		}
		else {
			Node *newR = new Node(data3);
			newN->setLeft(newR);
		}

		if (i == 0) {
			graph->top = newN;
		}
	}
	PreOrder(graph->top);
	InOrder(graph->top);
	PostOrder(graph->top);

	return 0;
}
