#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

enum Type {
    INT, 
    FLOAT, 
    CSTRING
};

namespace graal {

/*! 
 * Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function.Comparison functor.
 *
 * @param first_ Pointer to the first element of the range we want to copy (inclusive).
 * @param last_ Pointer to the last element of the range we want to copy (exclusive).
 * @param cmp The comparison function that return true if the first element is *less* than the second.
 *
 * @return A pair of the smallest and greatest elements.
 *
 */
    template <typename Itr, typename Compare >
    std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
    {
        auto min{first};
        auto max{first};

        // Trivial cases, 0 or 1 element in the range.
        if ( first == last or ++first == last )
            return std::make_pair( min, max );

        // Let us classify the second element.
        if ( cmp( *first, *min ) )
            min = first;
        else max = first;

        // Traverse the remaining elements.
        while( ++first != last )
        {
            // The current value is either
            // (1) less than min, in this case we update the min iterator
            // (2) greater or equal to the min. In this case it might become the greatest.
            if ( cmp( *first, *min ) )
                min = first;
            else
            {
                if ( ( not cmp( *max, *first ) and not cmp ( *first, *max ) ) or // equal or
                     cmp( *max, *first ) ) // greater than the current greatest...
                {
                    // ... we update, because we want the `last` greatest element.
                    max = first;
                }
            }
        }

        return { min, max };
    }
    /**
     * @brief reverses the order of the elements in a range
     * 
     * @tparam BidirIt Iterator to the range.
     * @param first Pointer to the first element of the range.
     * @param last Pointer to the last element of the range.
     */
    template<class BidirIt>
    void reverse(BidirIt first, BidirIt last)
    {
            Type k;
            while ((first != last) && (first != --last))
            {
                k = Type(*first);
                *first = *last;
                *last = k;
                first++; 
            }
    }
    /**
     * @brief copies the range  values  into  a  new  range  beginning  at dfirst
     * 
     * @tparam InputIt Iterator to the range.
     * @param first Pointer to the first element of the range.
     * @param last Pointer to the last element of the range.
     * @param d_first pointer pointing to the address just past the last element of the destination range
     * @return InputIt Iterator to the range.
     */
    template<class InputIt>
    InputIt copy(InputIt first, InputIt last,InputIt d_first)
    {
        while(first != last)
        {
            *d_first = *first;
            first++;
            d_first++;
        }
        return d_first;
    }
    /**
     * @brief receives  a  range[first;last) over an array, and returns a pointer (iterator) 
     * to the first element in the range for which a given predicate p returns true
     * 
     * @tparam InputIt  Iterator to the range
     * @tparam UnaryPredicate  Iterator to the predicate
     * @param first Pointer to the first element of the range.
     * @param last Pointer to the last element of the range.
     * @param p predicate
     * @return InputIt  Iterator to the range
     */
    template<class InputIt, class UnaryPredicate>
    InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
    {
        while(first != last)
        {
            if(p(Type(*first))) 
                return first;
            first++;
        }
        return last;
    }
    /**
     * @brief receives a range[first;last), a target value,and returns a pointer (iterator)
     * to the first element in the range that is equal to the valuepassed to the function
     * 
     * @tparam InputIt Iterator to the range
     * @tparam T Iterator to the value
     * @tparam Equal Iterator to the predicate
     * @param first Pointer to the first element of the range.
     * @param last Pointer to the last element of the range.
     * @param value Value that we want to find.
     * @param eq predicate
     * @return InputIt Iterator to the range
     */
    template<class InputIt, class T, class Equal>
    InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
    {
        while(first != last )
        {
            if(eq(Type(*first), Type(value)))
                return first;
            first++;
        }
        return last;
    }
    
    template<class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        while(first != last){
            if(!p(*first)) return false;
            first++;
        }
        return true;
    }

    template<class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        while(first != last)
        {
            if(p(*first)) return true;
            first++;
        }
        return false;
    }

    template<class InputIt, class UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        while(first != last){
            if(p(*first)) return false;
            first++;
        }
        return true;
    }

    template<class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1, 
               InputIt2 first2,
               Equal eq)
    {
        while(first1 != last1)
        {
            if( !eq( Type(*first1), Type(*first2) )) 
                return false;
            first1++;
            first2++;
        }
        return true;
    }

    template<class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               Equal eq )
    {
        while(first1 != last1)
        {
            if(!eq( Type(*first1), Type(*first2) ) ) 
                return false;
            first2++;
            first1++;
        }
        return true;
    }


    template<class InputIt, class Equal>
    InputIt unique( InputIt first, InputIt last, Equal eq )
    {
        // TODO
        return first;
    }

    template<class ForwardIt, class UnaryPredicate>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
    {
        size_t i { 0 }, j { 0 };
        Type k  = Type(*first);
        while(first+j != last)
        {
            if(p(  Type(*(first+j))    ))
            {
                k = Type(*(first+i));
                *(first+i) = *(first+j);
                *(first+j) = k; 
                i++;
            }
            j++;
        }
        return first+i;
    }

    template<class ForwardIt, class Comparison>
    void sort(ForwardIt first, ForwardIt last, Comparison cmp)
    {
        ForwardIt k;
        for (short i = 0; (first+i) != last; i++)
        {
            for (short j = i+1; (first+j) != last; j++)
            {   
                if( !cmp(Type(*(first+i)), Type(*(first+j)))   )
                {
                    *k = *(first+i);
                    *(first+i) = *(first+j);
                    *(first+j) = *k;
                }
            }
        }
    }
    /**
     * @brief receives a range[first;last)and an iter-atornfirstin that
     * range and does a left rotation on the elements in[first;last)in  
     * such  a  way  thatn first becomes  the  first  element  of  the  rotated 
     * range  andnfirst-1becomes the last element
     * 
     * @tparam ForwardIt  Iterator to the range
     * @param first 
     * @param n_first 
     * @param last 
     * @return ForwardIt 
     */
    template<class ForwardIt>
    ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
    {
        // TODO
        return first;
    }

}


#endif
