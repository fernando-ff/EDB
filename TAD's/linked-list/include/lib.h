#ifndef LIB_H
#define LIB_H

#include <iostream>

class Node{
	public:
		int data;
		Node* node;
};
void push( Node** head, int a);
void printList(Node *n);

#endif
