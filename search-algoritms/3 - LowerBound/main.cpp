#include<iostream>
/*Def:= 
 *Dado uma arranjo inteiro A qualquer e inteiroS x's quaisquers; x's pertence a A. 
 *Lower bound retorna o end. de mémoria do primeiro x do arranjo. 
*/
int* lower_bound(int *first, int *last, int value){
	auto m = { first };
	while( count > 0){
		auto step = count/2;
		std::advance( m, step );
		if( *m < value){
			first = ++m;
			count -= (step+1);
		} else count = step; 
	}
	return m;
}
int main(){

	int A[]{1,1,1,1,2,2,2,4,4,5,5,5,6,6,6,7,7,7};
	size_t size{sizeof(A)/sizeof(A[0])};
	int target{1};
	int* result = lower_bound( &A[0], &A[size],target);
	std::cout << *result << std::endl;
	return 0;
}