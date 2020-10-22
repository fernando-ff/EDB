/*
 */

#include <iostream>
#include "../include/searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        size_t size = last - first;
        for (size_t i = 0; i < size; i++)
        {
            if(*(first+i) == value) return (first+i);
        }
        return first+size; 
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
         value_type* last_backup = last;
        while(first != last){
            size_t size = last - first;
            int middle = (size-1)/2;
            if(*(first+middle) == value) return (first+middle);
            else if(*(first+middle) < value) {
                first = (first+middle+1);
            }
            else {
                last = (first+middle);
            }
        }
        return last_backup;
    }

    value_type * bsearch_recursive( value_type* first, value_type * last, value_type value){
        int middle { 0 };
        if(first != last){
            size_t size = last - first;
            if(*first > value) return last;
            if(*(first+middle) == value){
                return (first+middle);
            }
            if(*(first+middle) < value){
                return bsearch_recursive((first+middle+1), last,value);
            }
            return bsearch_recursive(first, (first+middle), value);
            middle = (size-1)/2;

        }
        return last;
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
    if(value < *(first)) return first;
    while (first != last)
    {
        size_t array_size =  last-first;          
        int middle = (array_size-1)/2;
        
        if(*(first+middle) == value){
            if(*(first+middle-1) != value){
                return (first+middle);
            }
            else {
                last = (first+middle);
            }
        }
        else if(*(first+middle) < value){
            first = (first+ middle+1);
        }
        else {
            last = (first+middle);
        }
    }
    return last;
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
    //     auto count = std::distance( first, last );//Armazena a distância do array.
	//     while (count > 0){
	// 	auto step = count/2;
	// 	auto m {first};//interador auxiliar, aponta para o elemento do meio.
	// 	std::advance(m,step);
	// 	if (*m <= value)
	// 	{
	// 		first = ++m;
	// 		count -= (step+1);
	// 	}
	// 	else count = step;
	// }
	// return last;
    // short epoch {1};
    int* last_backup { last };
    // std::cout << "===> Starting Upper Bound Function <===" << std::endl;
    while (first != last_backup)
    {
        size_t array_size =  last_backup-first;    
        int middle = (array_size-1)/2;
        if(*(first+middle) == value){
            if(*(first+middle+1) != value){
                return (first+middle+1);
            }
            else {
                first = (first+middle+1);
            }
        }
        else if(*(first+middle) < value){
            first = (first+ middle+1);
        }
        else {
            last_backup = (first+middle);
        }
    }
    return last_backup;
    }
    
}

