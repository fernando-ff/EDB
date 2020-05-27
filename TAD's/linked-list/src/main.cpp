#include "../include/lib.h"
#include <iostream>

int main(){
	Node* head = NULL;/*!Instanciando o primeiro elemento da lista*/
	Node* second = NULL;//*!Instanciando o segundo elemento da lista*/
	Node* third = NULL;/*!Instanciando o terceiro elemento da lista*/

	head = new Node();/*!Instanciando os objetos na heap*/
	second = new Node();/*!Instanciando os objetos na heap*/
	third = new Node();/*!Instanciando os objetos na heap*/

	head->data = 1;/*!Atribuindo um dado ao primeiro elemento da lista*/
	head->next = second;/*!Estabelencendo link com o segundo elemento da lista*/

	second->data = 2;/*!Atribuindo um dado ao segundo elemento da lista */
	second->next = third;/*!Estabelecendo link com o terceiro elemento da lista*/
	third->data = 3;/*!Atribuindo um dado ao terceiro elemento da lista*/
	third->next = NULL;/*!Estabelecendo o fim da lista*/

	push(&head, 0);

	insert(second, 1);
	
	printList(head);

	return 0;


}
