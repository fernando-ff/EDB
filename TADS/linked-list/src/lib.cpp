#include<iostream>
/*!Definição da classe Node */
class Node {
public:
	int data;/*!Armazena o valor de uma inteiro qualquer*/
	Node* node;/*!Faz o link com o próximo elemento da lista*/
};

void printList(Node *n){
	while(n != NULL){
		std::cout << n->data << " ";
		n = n->node;
	}
	std::cout << "\n";
}

