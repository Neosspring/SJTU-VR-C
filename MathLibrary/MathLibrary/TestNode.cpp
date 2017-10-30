#include "Node.h"
#include <iostream>

using namespace std;

void TestNode() {
	Node* head = new Node(0);
	Node* p = head;
	for (int i = 1; i < 10; i++) {
		insertNode(p, i);
		p = p->next;
	}

	for (Node* p = head; p != NULL; p = p->next) {
		cout << p->info << " ";
	}
	cout << endl;

	int k;

	cout << "Print a number you want to search from the link list: ";
	cin >> k;

	bool flag = searchNode(head, k);
	if (flag) {
		cout << k <<" is in the LinkList." << endl;
	}
	else {
		cout << k << " is not in the LinkList." << endl;
	}
}