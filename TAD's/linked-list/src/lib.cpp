#include<iostream>
/*!Definição da classe Node */
class Node {
public:
	int data;/*!Armazena o valor de uma inteiro qualquer*/
	Node* node;/*!Faz o link com o próximo elemento da lista*/
};

/*! Insere o elemento no início da lista.
 *	@param head Referência para o head da lista.
 *  @param a Dado que será inserido na lista.
 */ 
void push( Node** head, int a){
	Node* n = new Node();/*!Instanciamento do novo Node*/
	n->data = a;/*!Atribuição do novo dado ao novo Node*/
	n->node = (*head);/*!Fazendo  node como o novo head*/
	(*head) = n;/*!Estabelecendo o novo node como o novo head*/
}

void printList(Node *n){
	while(n != NULL){
		std::cout << n->data << " ";
		n = n->node;
	}
	std::cout << "\n";
}

