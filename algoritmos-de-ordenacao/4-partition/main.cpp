#include <iostream>

void swap( int *a, int *b ){
	int k { *a };
	*a = *b;
	*b = k;
}
/**============================================================================================
 * Partition
 * Def := Dado um array inteiro A qualquer, e um inteiro p qualquer, talque p pertença á A.
 *		  Seja partition P: A |------ > {a1,a2,p,a3,..,an} uma função, talque a2 < p e p < a3. 
================================================================================================*/
int partiton( int arr[], int start, int end ){
	//Guarda o último elemento do array, para ser usado como pivô.
	auto pivot { arr[end] };
	auto i { start - 1 };
	//Intera pelo array
	for (int j { start }; j <= end; ++j)
	{
		//Verifica se o elemento em questão é menor do que o pivo.
		if( arr[j] < pivot){
			i++;
			//Troca os valores dos elementos.
			swap(&arr[i], &arr[j] );
		}
	}
	//Faz uma última troca, deixando o pivo como fronteira.
	swap(&arr[i+1],&arr[end]);
	return(i+1);
}
void print( int arr[], size_t size ){
	std::cout <<" arr = [ ";
	for (size_t i {0}; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}
int main(){
	int arr[]{ 5, 1, 2, 4, 3 };
	size_t size { sizeof(arr)/sizeof(arr[0]) };
	partiton( arr, 0, size-1 );
	print( arr, size );

}