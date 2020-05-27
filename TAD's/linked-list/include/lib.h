#ifndef LIB_H
#define LIB_H

#include <iostream>

class Node{
	public:
		int data;
		Node* next;
};
void push( Node** head, int a);
void insert(Node* node_ref, int data);
void printList(Node *node);

#endif
