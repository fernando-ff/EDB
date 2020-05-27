#include<iostream>
/*!Definição da classe Node */
class Node {
public:
	int data;/*!Armazena o valor de uma inteiro qualquer*/
	Node* next;/*!Faz o link com o próximo elemento da lista*/
};

/*! Insere o elemento no início da lista.
 *	@param head Referência para o head da lista.
 *  @param a Dado que será inserido na lista.
 */ 
void push( Node** head, int data){
	Node* new_node = new Node();/*!Instanciamento do novo Node*/
	new_node->data = data;/*!Atribuição do novo dado ao novo Node*/
	new_node->next = (*head);/*!Fazendo  node como o novo head*/
	(*head) = n;/*!Estabelecendo o novo node como o novo head*/
}

/*! Insere um dado após o elemento refenciado
 *  @param node_ref Referência para o nodulo
 *  @param data Valor que será inserido após o nodulo referênciado
*/
void insert(Node* node_ref, int data){	
	Node* new_node = new Node();/*!Instanciamento do novo nodulo*/
	new_node->data = data;/*!Atribuição do novo dado ao novo nodulo*/
	new_node->next = node_ref->next;
	node_ref->next = new_node;
}
void printList(Node *node){
	while(node != NULL){
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << "\n";
}

