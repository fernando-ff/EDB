/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <math.h>
// #include "../include/searching.h"
#include "../include/searching.h"

using namespace sa;

int main( void )
{
    // int count { 0 };
    std::ofstream l_data, b_data, br_data;
    // int lenghts[5] { 10000, 100000, 1000000, 10000000, 100000000 };
    // int** array = new int*[100000];
    // for (int k = 0; k <= 100000; k++)
    // {
    //     array[k] =  new int[100000];
    // }
    // for ( int i = 0; i < 100000; i++)
    // {
    //    for (int j = 0; j < 100000; j++)
    //    {
    //        array[i][j] = j;
    //    }
       
    // }
    int *array = new int[1000000000];
    for (long int i = 0; i < 1000000000; i++)
    {
        array[i] = i+1;
    }
    long int increase = 100000000;
    // typedef  int test_t; // The testing type for increment.
    std::cout << "\n> LINEAR SEARCH ANALISES EMPICAL <\n" << std::endl;
    std::cout << "|  ELEMENTS  |   MILISECONDS  |" << std::endl;
    std::cout << "-------------|------------------" << std::endl;
    l_data.open("../data/linear.data");
    while (increase <= 1000000000)
    {
        auto start = std::chrono::steady_clock::now();
            lsearch(array, array+increase, 0);
        auto end = std::chrono::steady_clock::now();        
        std::chrono::duration<double> diff = end - start;
        std::cout << " "<< increase << "     |   " << std::chrono::duration <double, std::milli> (diff).count() << " ms"<< std::endl;
        l_data << increase << "\t" << std::chrono::duration <double, std::milli> (diff).count()  << "\n";
        std::cout << "-------------|------------------" << std::endl;
        increase += 18000000;
    }
    l_data.close();

    increase = 100000000;
    std::cout << "\n \t   > RECURSIVE BINARY SEARCH ANALISES EMPICAL <\n" << std::endl; 
    std::cout << "|  ELEMENTS  |   MICROSECONDS  |" << std::endl;
    std::cout << "-------------|------------------" << std::endl;
    b_data.open("../data/bsearch.data");
    while (increase <= 1000000000)
    {
        auto start = std::chrono::steady_clock::now();
            bsearch_recursive(array, array+increase, 0);
        auto end = std::chrono::steady_clock::now();            
        std::chrono::duration<double> diff = end - start;
        // auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
        std::cout << "    "<< increase << " |   " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
        b_data << increase << "\t" << std::chrono::duration <double, std::milli> (diff).count()  <<"\n";
        increase += 18000000;
    }
    b_data.close();

    std::cout << "\n \t   > RECURSIVE BINARY SEARCH ANALISES EMPICAL <\n" << std::endl; 
    std::cout << "|  ELEMENTS  |   MICROSECONDS  |" << std::endl;
    std::cout << "-------------|------------------" << std::endl;
    br_data.open("../data/brsearch.data");
    while (increase <= 1000000000)
    {
        auto start = std::chrono::steady_clock::now();
            bsearch_recursive(array, array+increase, 0);
        auto end = std::chrono::steady_clock::now();            
        std::chrono::duration<double> diff = end - start;
        // auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
        std::cout << "    "<< increase << " |   " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
        br_data << increase << "\t" << std::chrono::duration <double, std::milli> (diff).count()  <<"\n";
        increase += 18000000;
    }
    br_data.close();

    return EXIT_SUCCESS;
}
