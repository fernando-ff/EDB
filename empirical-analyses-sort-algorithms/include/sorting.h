/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + insertion sort
 *  + selection sort
 *  + bubble sort
 *  + shell sort
 *  + quick sort
 *  + merge sort
 *  + radix sort
 * 
 * \authors Vitor Hugo e  Fernando Ferreira
 * \date Set, 2020.
 */

#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <random>
#include<fstream>
#include <sstream>

#include <limits>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*! \mainpage Empirical analyses
 * \section Starting
 *
 * \subsection clone clone this project
 * $ git clone https://projetos.imd.ufrn.br/fernandoff/edb1-empirical-analysis.git
 * 
 * \subsection Access
 * $ cd edb1-empirical-analysis
 * 
 * \subsection Compile to compile
 * $ mkdir build && cd build
 * $ cmake ../
 * $ make
 *
 * \subsection Run run where the data collection occurs
 * $ ./timing_template 
 *
 * \subsection Tests run the tests
 * $ ./run_tests
 * 
 * \subsection References 
 * + https://www.geeksforgeeks.org
 * + https://www.youtube.com/user/mycodeschool
 * + https://www.wikipedia.org/
 * 
 * Remember to create the build folder and compile into it   
 *
 * 
 */


/**
 * @brief Search Algorithms analysed in this projct
 * 
 */
namespace sa {

    /// just an alias for an integer type.
    using value_type = unsigned int;
    /**
     * @brief given a pivot it divides the array into two parts, elements less than 
     * or equal to the pivot and elements greater than or equal to the pivot
     * 
     * @param  pointer to the first element in the array
     * @param last pointer to the last element in the array
     * @return value_type* pointer to the pivot
     */
    value_type * partition(value_type * first, value_type * last);
    /**
     * @brief simple sorting algorithm that works similar to the 
     * way you sort playing cards in your hands.
     * 
     * @param first pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void insertion( value_type * first, value_type * last);
    /**
     * @brief algorithm sorts an array by repeatedly finding 
     * the minimum element (considering ascending order) 
     * from unsorted part and putting it at the beginning.
     * 
     * @param first pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void selection( value_type * first, value_type * last);
    /**
     * @brief simplest sorting algorithm that works by repeatedly
     * swapping the adjacent elements if they are in wrong order.
     * 
     * @param first 
     * @param last 
     */
    void bubble( value_type * first, value_type * last);
    /**
     * @brief The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h.
     *  We keep reducing the value of h until it becomes 1.
     *  An array is said to be h-sorted if all sublists of every h’th element is sorted
     * 
     * @param first 
     * @param last 
     */
    void shell( value_type * first, value_type * last);
    /**
     * @brief A divide and conquer algortihm.It picks an element as
     * pivot and partitions the given array around the picked pivot
     * 
     * @param first pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void quicksort( value_type * first, value_type * last);
    /**
     * @brief A divide and conquer algortihm. It divides divides
     * input array in two halves, calls itself for the two halves
     * and then merges the two sorted halves.
     * 
     * @param first pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void mergesort( value_type * first, value_type * last);
    /**
     * @brief non-comparative sorting algorithm. It avoids comparison 
     * by creating and distributing elements into buckets according to 
     * their radix. For elements with more than one significant digit, 
     * this bucketing process is repeated for each digit, while 
     * preserving the ordering of the prior step, until all digits have been considered
     * 
     * @param first pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void radix(value_type *first, value_type *last);

}
/**
 * @brief Functions to create the simulations
 * 
 */
namespace scenario
{
    /// just an alias for an array type.
    using array_type = unsigned int;

    /**
     * @brief arrange the elements in non-decreasing order
     * 
     * @param pointer to the first element in the array
     * @param last pointer to the last element in the array
     */
    void first( array_type *first, array_type * last);
    /**
     * @brief arrange the elements in non-increasing order
     * 
     * @param first to the first element in the array
     * @param last pointer to the last element in the array
     */
    void second( array_type * first, array_type * last);
    /**
     * @brief get an array with elements 100% of its random elements
     * 
     * @param first to the first element in the array
     * @param last pointer to the last element in the array
     */
    void third( array_type * first, array_type * last);
    /**
     * @brief get an array with elements 75% of its elements in definitive position
     * 
     * @param first to the first element in the array
     * @param last pointer to the last element in the array
     */
    void fourth( array_type * first, array_type * last);
    /**
     * @brief get an array with elements 25% of its elements in definitive position
     * 
     * @param first to the first element in the array
     * @param last pointer to the last element in the array
     */
    void fifth( array_type * first, array_type * last);
    /**
     * @brief get an array with 50% of its elements in definitive position
     * 
     * @param first to the first element in the array
     * @param last pointer to the last element in the array
     */
    void sixth( array_type * first, array_type * last);


} // namespace name

/**
 * @brief Store functions that render informations
 * about the project and helped to debug the same
 * 
 */
namespace render
{
    /// just an alias for an integer type.
    using array_type = unsigned int;
    /**
     * @brief Render the array, is useful to debbug.
     * 
     * @param first 
     * @param last 
     */
    void array(array_type * first, array_type * last );
    /**
     * @brief Render the intro message that show the name
     * of creator this coding 
     */
    void intro();
    /**
     * @brief Render the a guide line that help the user
     * use this project
     */
    void guide();
    /**
     * @brief Render more instructions how to use this project
     */
    void open_file_guide();
    /**
     * @brief render the data generate by analyses
     * 
     * @param sample sample analyzed
     * @param result time taken 
     * @param function analyzed function
     * @param epoch epoch  being analyzed
     * @param scn scenario analyzed
     */
    void body(  unsigned long int sample,std::chrono::duration<double> result, std::string function, unsigned short int epoch, unsigned short int scn);
    /**
     * @brief Render the help message when the user enter in the
     * command line with : './timing_template --help'
     */
    void help();

} // namespace name

#endif // SORTING_H
