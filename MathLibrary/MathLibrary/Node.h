#pragma once
#include <iostream>

using namespace std;

struct Node {
	int info;
	Node *next;
	
	Node(int i) { info = i; next = NULL; };
	Node() {};
};
void insertNode(Node *p,int i) {
	Node *node = new Node();
	node->info = i;
	node->next = p->next;
	p->next = node;
}
bool searchNode(Node* p, int i) {
	Node* n = p;
	while (n != NULL) {
		if (n->info == i) {
			return true;
		}
		n = n->next;
	}
	return false;
}