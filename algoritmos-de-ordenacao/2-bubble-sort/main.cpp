#include <iostream>
/*======================
    Troca os elementos
=======================*/
void swap( int *a, int *b){
    int k { *a };
    *a = *b;
    *b = k;
}
/*===================================================================================================
 *Bubble sort  
 *Def := Dado um arranjo A qualquer, Talque a1,a2,...,an são elementos quaisquers pertecentes a A.
 *      Seja BubblenSort uma função, talque
 *      F : A |----> A = { a1,a2, ... ,an}, com a1 < a2 < ... < an   
====================================================================================================*/
void bubbleSort( int A[], size_t size){

    for (size_t i{0}; i < size ; i++){//Irá repetir de acordo com a quantidade de elementos do array.

        for (size_t j{0}; j < size-i-1; j++)//Irá repetir de acordo com a quantidade de elemtentos já ordenados no array.
        {
            if (A[j] > A[j+1])//Compara um elemento a qualquer com o seu sucessor.
            {
                //Caso a condição, a ser menor que a+1, seja satisfeita, trocasse os elementos
                swap(&A[j],&A[j+1]);
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
/*==============================
 *  Lado do cliente
================================*/
int main(){
    int A[] { 64, 34, 25, 12, 22, 11, 90 };
    size_t size { sizeof(A)/sizeof(A[0]) };
    bubbleSort( A, size-1 );
    print( A, size );
}