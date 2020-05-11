#include <iostream>
 /*=============================================================================
 *Insertion Sort
 *	Def:=Dado um arranjo A qualquer, talque o elemento x qualquer pertence a A.
 *		Seja a insertSort uma função, talque
 * 		F:A |------>  x1 < x2 < ... < xn.
 * 		Portanto, insertSort ordena os elementos em ordem decrescente.
 ==============================================================================*/
void insertionSort( int arr[], size_t size ){
    size_t key { 1 };
    for (; key <  size; ++key)
    {
    	for (size_t i{0}; i < size-(size-key); ++i)
    	{
    		
    		if (arr[key] <  arr[i])
    		{
    			
    			auto k { arr[key] };
    			arr[key] = arr[i];
    			arr[i] = k;
    		}
    	}
    }
    
}
/*==================================
 *      Imprime o array
===================================*/
void print( int arr[], int size ){
    
    std::cout << "arr = [ " << arr[0];
    for (int i{1}; i < size; i++)
    {
        std::cout << ", " << arr[i];
    }
    std::cout <<" ]" << std::endl;
    
}
int main(){
    int arr[] { 12, 11, 13, 5, 6 };
    size_t size { sizeof(arr)/sizeof(arr[0]) };
    insertionSort( arr, size );
    print( arr,	size );

}