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
	(*head) = new_node;/*!Estabelecendo o novo node como o novo head*/
}

/*! Insere um dado após o elemento refenciado
 *  @param node_ref Referência para o nodulo
 *  @param data Valor que será inserido após o nodulo referênciado
*/
void insert(Node* node_ref, int data){	
	Node* new_node = new Node();/*!Instanciamento do novo nodulo*/
	new_node->data = data;/*!Atribuição do novo dado ao novo nodulo*/
	new_node->next = node_ref->next;/*Fazendo o novo node pegar o!*/
	node_ref->next = new_node;
}
/*! Insere um dado na ultima posição da lista
 *  @param head Referência para o head da lista
 *  @param data Valor que será inserido após o nodulo referênciado
*/
void append(Node** head, int data) {
	Node* new_node = new Node();//!< Instanciando o novo Nodulo
	Node* last = *head; //!< Instanciando o novo n
	new_node->data = data;
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
		return;
	}

	while(last->next != NULL )
		last = last->next;

	last->next = new_node;
}

void deleteNode( Node** head, int key){
	Node * temp = *head, *prev;

	if(temp != NULL && temp->data == key){
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) return;

	prev->next = temp->next;

	free(temp);
}


void printList(Node *node){
	while(node != NULL){
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << "\n";
}

