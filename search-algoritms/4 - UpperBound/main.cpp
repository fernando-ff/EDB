#include<iostream>
/*Def:= 
 *Dado uma arranjo inteiro A qualquer e inteiroS x's quaisquers; x's pertence a A. 
 *Upper bound retorna o end. de mémoria do ultimo x do arranjo. 
*/
//Autor: Fernando Ferreira de Lima Filho

int* upperBound(int* first, int* last, int value){
	auto count = std::distance( first, last );//Armazena a distância do array.
	while (count > 0){
		auto step = count/2;
		auto m {first};//interador auxiliar, aponta para o elemento do meio.
		std::advance(m,step);
		if (*m <= value)
		{
			first = ++m;
			count -= (step+1);
		}
		else count = step;
	}
	return first;
}
int main(){

	int A[]{1,1,1,1,2,2,2,4,4,5,5,5,6,6,6,7,7,7};
	size_t size{sizeof(A)/sizeof(A[0])};
	int target{1};
	int* result = upperBound( &A[0], &A[size],target);
	std::cout << *result << std::endl;
	return 0;

}