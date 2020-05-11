#include <iostream>
/*===================================================================================================
 * Selection Sort
 *Def := Dado um arranjo A qualquer, Talque a1,a2,...,an são elementos quaisquers pertecentes a A.
 *      Seja selectionSort uma função, talque
 *      F : A |----> A = { a1,a2, ... ,an}, com a1 < a2 < ... < an
=======================================================================================================*/
void selectionSort( int *first, int *last ){
    
    for (;first != last  ; first++)//Irá passar por toods os elementos do array.
    {
        for ( auto ptr{ first+1 };ptr != last ; ptr++)//Dado um elemento a qualquer pertencente ao array,
                                                     // irá acessar todos os elementos posteriores, ou seja, a+1,..a+n.
        {
            if (*ptr < *first)//Compara os elementos acessados com a.
            {
                //Troca os valores dos elementos caso a condição seja realizada.
                auto k { *first };
                *first = * ptr;
                *ptr = k;

            }
            
        }
        
    }
    
}
/*=========================
        Imprime o array.
===========================*/

void print(int *A, size_t size){
    std::cout << "A = [ " << A[0];
    for (size_t i = 1; i < size; i++)
    {
        std::cout <<", " << A[i];
    }
    std::cout << " ]" << std::endl;
}
/*============================
        Lado do cliente.
=============================*/
int main(void){
    int A[]{ 0, 5, -2, -1, 1, 2, 4, 3, 6 };
    size_t size { sizeof(A)/sizeof(A[0] )};
    selectionSort( A,A+(size-1) );
    print( A, size );
}