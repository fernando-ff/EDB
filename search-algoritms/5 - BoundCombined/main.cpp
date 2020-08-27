#include<iostream>

int* lowerBound(int *first, int *last, int value){
	auto count = std::distance( first,last );//Armazena a distância do array.
	while( count > 0 ) {
		auto step = count/2;//
		auto m { first }; // Iterador auxiliar, aponta para o elemento do meio.
		std::advance( m,step );
		if( *m < value ) // Procura pela direita.
		{
			first = ++m ;
			count -= (step +1);
		}
		else	count = step ;
	}
	return first;
}

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
	int *begin = lowerBound( &A[0], &A[size], target );
	int *end = upperBound( &A[0], &A[size], target );
	for (; begin != end; begin++)	std::cout << *begin <<" ";
	std::cout <<"\n";
	return 0;

}