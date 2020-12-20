
    /*!
 * Programa de uso temporário para testar o array.
 *
 * @date 20 de outubro de 2020
 * @author Selan
 * @file driver_array.cpp
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

#include "../include/vector.h" // O array "caseiro".
#define which_lib sc
template< typename T>
void func( const sc::vector<T> & a )
{
    std::cout << a.at(2) << std::endl;
}

int main( void )
{
    std::vector<int> a{1, 2, 3, 4}; // construtor com lista inicializadora.
    which_lib::vector<int> b; // construtor padrão.
    which_lib::vector<int> c= {1, 2, 3, 4, 5, 6, 7, 9}; // construtor com lista inicializadora.

    func( c );

    // b[0] = 4;
    // x = b[0]; // Cadeado const.

    // std::cout << "Valor de b[0] = " << (b.at(0) = 3) << std::endl;
    std::cout << "Tamanho de b: " << b.size() << std::endl;

    int x;
    try {
        // x = c.at( 12 );
        c.at(0) = 1000;
        std::cout << ">>> ENdereco: " << c.at(12) << std::endl;
    }
    catch( const std::out_of_range & e )
    {
        std::cout << "Excecao caputada: " << e.what() << std::endl;
    }

    std::cout << ">>> Vamos consultar o array\n";
    auto y = c.at(0);
    cout << y << "\n";
    // Imrpimir os elementos de `a`.
    for ( size_t i{0} ; i < c.size() ; ++i ) // size().
        std::cout << c.at(i) << " "; // operator[]().

    std::cout << "\n";

    return 0;
}


