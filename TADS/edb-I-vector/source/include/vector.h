#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using std::cout;
#include <initializer_list>
using std::initializer_list;
#include <algorithm>
using std::copy;
#include <memory>
using std::unique_ptr;
#include<typeinfo>

/// Namespace where will be creates our data structs squencial container.

namespace sc {
    /*!
     * This class represent a C++ generic static vector, that is a sequencial
     * container type
     * @tparam T data type that will be stored in the vector.
     */
    template < typename T >
    class vector {
        public:
            // alias for types
            using value_type             = T;
            using size_type              = size_t;
            using pointer                = T*;
            using const_pointer          = const T*;
            using reference              = T&;
            using const_reference        = const T&;
            
        public:

            class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                T *m_ptr; //!< This is the reagular pointer, that stay inherit in the iterator class.
            public:
                iterator( T* pt_ = nullptr ) : m_ptr{ pt_ }
                { /* empty */ }
                ~iterator( void ) = default;
                iterator( const iterator& ) = default;
                iterator& operator=( const iterator& ) = default;
             
                /**
                 * @brief advances iterator to the next location within the vector.
                 * 
                 * @return iterator& 
                 */
                iterator& operator++(void) 
                { 
                    m_ptr++; 
                    return *this; 
                }
                /**
                 * @brief  advances iterator to the next location within the vector
                 * 
                 * @return iterator 
                 */
                iterator operator++(int) 
                { 
                    iterator retval{*this}; 
                    m_ptr++; 
                    return retval; 
                }
                /**
                 * @brief  return a iterator pointing to the n -th successor in the vector from it
                 * 
                 * @param n amount container that it will pass
                 * @param it initial iterator
                 * @return iterator 
                 */
                friend iterator operator+(int n, iterator it) 
                { 
                    it.m_ptr+= n;
                    return it; 
                }
                /**
                 * @brief return a iterator pointing to the n -th successor in the vector from it
                 * 
                 * @param it 
                 * @param n 
                 * @return iterator 
                 */
                friend iterator operator+(iterator it, int n) 
                { 
                    it.m_ptr+= n;
                    return it; 
                }
                /**
                 * @brief return a reference to the object located at the position pointed by the iterator
                 * 
                 * @return T& 
                 */
                T& operator*(void) const 
                { 
                    return *m_ptr; 
                }


                iterator& operator--(void) 
                { 
                    m_ptr--; 
                    return *this; 
                }
                iterator operator--(int) 
                { 
                    iterator retval{*this}; 
                    m_ptr--; 
                    return retval; 
                }
                T& operator->()
                {
                    return *m_ptr; 
                }
                /**
                 * @brief returns true if both iterators refer to the same location within the vector, and false otherwis
                 * 
                 * @param other vector that will be compare
                 * @return true if both iterators refer to the same location within the vector
                 * @return false if both iterators no refer to the same location within the vector
                 */
                bool operator==( const iterator& other ) const  
                { 
                    return m_ptr==other.m_ptr; 
                }
                /**
                 * @brief returns true if both iterators refer to a different location within the vector, and false otherwise.
                 * 
                 * @param other vector that will be compare
                 * @return true  if both iterators refer to a different location within the vector
                 * @return false  if both iterators refer to same location within the vector,
                 */
                bool operator!=( const iterator& other) const 
                { 
                    return ! ( *this==other ); 
                }

        };

            class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                const T *m_ptr; //!< this is a regular pointer, that stay ihnerti in the iterator class.
            public:
                const_iterator( const T* pt_ = nullptr ) : m_ptr{ pt_ }
                { /* empty */ }
                ~const_iterator( void ) = default;
                const_iterator( const const_iterator& ) = default;
                const_iterator& operator=( const const_iterator& ) = default;

               /**
                * @brief advances iterator to the next location within the vector
                * 
                * @return const_iterator& 
                */
                const_iterator& operator++(void) 
                { 
                    m_ptr++; 
                    return *this; 
                }
                /**
                 * @brief advances iterator to the next location within the vector
                 * 
                 * @return const_iterator 
                 */
                const_iterator operator++(int) 
                { 
                    const_iterator retval{*this}; 
                    m_ptr++; 
                    return retval; 
                }
                /**
                 * @brief return a reference to the object located at the position pointed by the iterator
                 * 
                 * @return const T& 
                 */
                const T& operator*(void) const 
                { 
                    return *m_ptr; 
                }
                
                /**
                 * @brief 
                 * 
                 * @return const_iterator& 
                 */
                const_iterator& operator--(void) 
                { 
                    m_ptr--; 
                    return *this; 
                }
                /**
                 * @brief 
                 * 
                 * @return const_iterator 
                 */
                const_iterator operator--(int) 
                { 
                    const_iterator retval{*this}; 
                    m_ptr--; return retval; 
                }
                /**
                 * @brief returns true if both iterators refer to the same location within the vector, and false otherwis
                 * 
                 * @param other vector that will be compare
                 * @return true if both iterators refer to the same location within the vector
                 * @return false if both iterators no refer to the same location within the vector
                 */
                bool operator==( const const_iterator& other ) const  
                { 
                    return m_ptr==other.m_ptr; 
                }
                /**
                 * @brief returns true if both iterators refer to a different location within the vector, and false otherwise.
                 * 
                 * @param other vector that will be compare
                 * @return true if both iterators refer to a different location within the vector.
                 * @return false if both iterators refer to same location within the vector.
                 */
                bool operator!=( const const_iterator& other) const 
                { 
                    return ! ( *this==other ); 
                }

        };

        private:
            pointer data = nullptr;//!< Pointer which stores the address of the container.
            size_type elements{ 0 };//!< numbers of elements present currently in the vector.
            size_type SIZE{ 0 };//!< total storage.
        public:
            /**
             * @brief Default constructor that creates an empty list
             * 
             */
            vector() 
            {/*empty*/}
            /**
             * @brief Constructs the list with count default-inserted instances of T .
             * 
             * @param count 
             */
            explicit vector(size_t count)
            {
                SIZE = count;//adding a new size to the vector.
                // delete[] data;//cleaning the memory.
                data = new value_type[SIZE];//creating a new space memory to store the data.
                elements = 0;
                //initializing each new local memory in the space memory.
                for(unsigned short i{0}; i < SIZE; i++)
                    data[i] = value_type{};
            }
            /**
             * @brief Constructs the list with the contents of the range [first, last) .
             * 
             * @tparam InputIt 
             * @param first begin of the range
             * @param last end of the range
             */
            template<typename InputIt>
            vector(InputIt first, InputIt last)
            {
                SIZE = std::distance(first, last);//taking distance between the first and last inputIT, this will be our size now.
                // delete[] data;//cleaning the memory.
                data = new value_type[SIZE];//creating a new space memmory to store the data.
                for(unsigned short i{0};first != last;i++)
                {
                    data[i] = *first;
                    first++;//iterando for the memmory
                    elements++;//counting elements presents in the sequence         
                }
            } 
            /**
             * @brief Copy constructor. Constructs the list with the deep copy of the contents of other.
             * 
             * @param other vector that will be copy.
             */
            vector( const vector & other )
            {
                SIZE = other.capacity();//taking the size 
                // delete[] data;//cleaning the memory.
                data = new value_type[SIZE]; //creating a new space memmory to store the data.
                elements = other.size();
                std::copy( other.cbegin(), other.cend(), begin() );
            }
            /**
             * @brief Constructs the list with the contents of the initializer list init 
             * 
             * @param il 
             */
            vector( const std::initializer_list<T> & il )
            {
                SIZE = il.size();////taking the list size 
                // delete[] data;//cleaning the memory.
                data = new value_type[SIZE];//creating a new space memmory to store the data.
                elements = il.size();//taking the amount elements present in the list 
                auto itr = il.begin();
                for ( size_type i{0ul}; i < SIZE ; i++ )
                    data[i] = *itr++; 
            }
            /**
             * @brief  Destructs the list
             * 
             */
            ~vector()
            {
                delete[] data;
            }
            /**
             * @brief Replaces the contents with a copy of the contents of other
             * 
             * @param other 
             * @return vector& 
             */
            vector& operator=(const vector& other)
            {
                delete[] data;//cleaning the memory
                SIZE = other.capacity();//taking the other vector size
                elements = other.size();//taking the other vector amount elements
                data = new value_type[SIZE];//adding a new space of memory
                std::copy( other.cbegin(), other.cend(), begin() );
                return *this;
            }
            /**
             * @brief Replaces the contents with those identified by initializer list ilist .
             * 
             * @param il initializer list.
             * @return vector& address to this vector
             */
            vector& operator=(const std::initializer_list<T> & il)
            {
                delete[] data;//cleaning the memory
                SIZE = il.size();//taking the list size
                data = new value_type[SIZE];//adding a new space of memory
                elements = SIZE;//taking the amount elements
                std::copy(il.begin(), il.end(), data);
                return *this;
            }

            /**
            * @brief return the number of elements in the container.
            * 
            * @return size_type number of elements in the container.
            */
            size_type size(void) const
            { 
                return elements; 
            }
            /**
             * @brief remove all elements from the container
             * 
             */
            void clear()
            {
                for (unsigned short i{0}; i < elements; i++)
                    data[i] = value_type{};
                elements = 0;  
            }

            /**
             * @brief say if the container contains elements or no.
             * 
             * @return true if the container no contains elements.
             * @return false if the container contains elements.
             */
            bool empty() const
            { 
                return elements == 0; 
            }
            /**
             * @brief adds value to the front of the vector
             * 
             * @param value value add to the front of the vector.
             */
            void push_front(const T& value )
            {
                if(SIZE == 0)//in case the size equal to zero.
                {
                    SIZE++;//increase the SIZE.
                    data = new value_type[SIZE];//creating a new space of memory.
                    elements++;//increase the amount of elements.
                    data[0] = value;//adding the value to first space in the new space of memory.
                }
                else if(elements == SIZE)//in case the size equal the amount of elements.
                {
                    SIZE++;//increase the SIZE.
                    value_type *array = new value_type[SIZE];//creating a new space of memory.
                    array[0] = value;//adding the new value to the first space of memory.
                    std::copy(cbegin(),cend(), array+1);
                    delete[] data;//cleaning the memory
                    data = array;//making the "connection" with the new space of memory
                    elements ++;//increase the amount of elments 
                }
                else if(elements < SIZE)//in case the amounts elements less than SIZE.
                {
                    value_type *array = new value_type[SIZE];//creating a new space of memory.
                    array[0] = value;//adding the new element in the first space in the new space of memmory
                    std::copy(cbegin(),cend(),array+1);
                    delete[] data;//cleaning the space of memory
                    data = array;//making the "connection" with the new space of memory.
                    elements ++;//increse the amount of elements.
                }
            }
            /**
             * @brief adds value to the end of the vector
             * 
             * @param value value that will be adds in the end of the vector
             */
            void push_back(const T& value)
            {
                if(SIZE == 0)//in case to SIZE equal zero.
                {
                    SIZE++;//increase the SIZE.
                    data = new value_type[SIZE];//creating a new space of memory.
                    data[0] = value;//adding to the first space of the space of memory the value.
                    elements++;//increase the amount of elements.
                }
                else if(elements == SIZE)//in case to the amount of elements equal SIZE
                {
                    SIZE++;//increase the SIZE.
                    value_type *array = new value_type[SIZE];//creating a new space of memory.
                    for(unsigned short i{0}; i < elements;i++)//copy the elements
                        array[i] = data[i];
                    delete[] data;//cleaning the memory
                    array[elements] = value;//adding to the last position to the new space of memory the value.
                    data = array;//making the "connection" with the new space of memory.
                    elements ++;//increase the elements.
                }
                else if(elements < SIZE)//in case the amounts of elements less than SIZE.
                {
                    data[elements] = value;//the last position of memory recieve the value.
                    elements++;//increse the amount of elements.
                }
            }
            /**
             * @brief removes the object at the end of the list.
             * 
             */
            void pop_back()
            {
                if(elements <= 0)//in case the amounts elements less than or equal zero, do it nothing
                    return;
                //in case the amounts of elements more than zero
                data[elements] = T{};//cleaning the last space memory with elements.
                elements--;//decreasing the amount of elements,
            }
            /**
             * @brief removes the object at the front of the list.
             * 
             */
            void pop_front()
            {
                pointer array = new value_type[SIZE];//creating a new space of memory.
                for(unsigned short i{0}; i< elements;i++)//copy the elements of data to array minus the first element in data
                    array[i] = data[i+1];
                delete[] data;//cleaning the memory.
                data = array;//making the "connection"
                elements--;//decreasing the amount of elements.
            }
            /**
             * @brief replaces the content of the list with count copies of value .
             * 
             * @param count amount of copies.
             * @param value value that will be copy.
             */
            void assign(size_type count, const T& value)
            {
                if(count >  SIZE)//if the count is more than SIZE
                    SIZE = count;//SIZE receive the count 
                
                pointer array = new value_type[SIZE];//creating a new space of memroy
                elements = count;//elements receive count 
                
                for(unsigned short i{0}; i < count;i++)//copy the value in each new space of memory  
                    array[i] = value;
                delete[] data;//cleaning the memory
                data = array;//making the "connection"
            }

            /**
             * @brief return the object at the index position in the array,
             * with no bounds-checking.
             * 
             * @param pos index position.
             * @return reference reference to the index position.
             */
            reference operator[]( size_type pos )
            { 
                return data[ pos ]; 
            }
            /**
             * @brief  return the element in the position poss for write
             *           
             * @param pos element index in vector
             * @return The value in the `pos` position
             * @throws std::out_of_range,  if !`pos < size()`.
             */
            value_type at( size_type pos ) const
            {
                if ( pos >= SIZE )
                    throw std::out_of_range("Reading attempt for vector...");
                return data[ pos ];
            }

            /**
             * @brief return the element in the position poss for write
             * 
             * @param pos position to write
             * @return reference to the element that will be write
             */
            reference at( size_type pos )
            {
                if ( pos >= SIZE )
                    throw std::out_of_range("Writing attempt for vector...");
                return data[ pos ];
            }
            /**
             * @brief return the internal storage capacity of the array
             * 
             * @return size_type size of the vector
             */
            size_type capacity(void) const
            { 
                return SIZE; 
            }
            /**
             * @brief increase the storage capacity of the array to a value that’s is greater or equal to new_cap
             * 
             * @param new_cap new capacity
             */
            void reserve( size_type new_cap )
            {
                if(capacity() < new_cap)
                {
                    pointer array = new value_type[new_cap];
                    for(short i{0};i < SIZE;i++)
                        array[i] = data[i];
                    delete[] data;
                    data = array;
                    
                    SIZE = new_cap;
                }   
            }
            /**
             * @brief Requests the removal of unused capacity.
             * 
             */
            void shrink_to_fit()
            {
                if(SIZE == elements)//in case the SIZE equal to the amount of elements
                    return;// do it nothing
                // in case to the SIZE more than amount of elements.
                SIZE = elements;//making the size equal to the amount of  elements
                pointer array = new value_type[elements];//create a new space of memory.
                for(unsigned short i{0}; i<elements;i++)//copy the data elements to new space of memory.
                    array[i] = data[i];
                delete[] data;//cleaning the memory.
                data = array;//make the "connection"
            }
            
            /**
             * @brief Checks if the contents of the lhs and rhs are equal.
             * 
             * @param rhs vector in the right side of the "=="  
             * @return true if the contents are equal.
             * @return false if the contents not are equal.
             */
            bool operator==(const vector& rhs)
            {
                if(this->size() != rhs.size())
                    return false;
                for(value_type i{0}; i < this->size(); i++)
                {
                    if(this->data[i] != rhs[i])
                        return false;
                }
                return true;
            }
            /**
             * @brief Checks if the contents of the lhs and rhs are different.
             * 
             * @param rhs vector in the right side of the "!="  
             * @return true if the contents are different
             * @return false if the contents aren't different
             */
            bool operator!=(const vector& rhs)
            {
                if(this->capacity() != rhs.capacity())
                    return true;
                for(value_type i{0}; i < this->capacity(); i++)
                {
                    if(this->data[i] != rhs[i])
                        return true;
                }
                return false;  
            }
           
            /**
             * @brief returns an iterator pointing to the first item in the      .
             * 
             * @return iterator to the first element
             */
            iterator begin(void) 
            { 
                return iterator( &data[0] ); 
            }
           /**
            * @brief returns a constant iterator pointing to the first item in the list
            * 
            * @return const_iterator pointing to the first item in the list
            */
            const_iterator cbegin(void) const 
            {
                return const_iterator( &data[0] ); 
            }
            /**
             * @brief  returns an iterator pointing to the end mark in the list, i.e. the position just after the last element of the list
             * 
             * @return iterator pointing to the end mark in the list.
             */
            iterator end(void) 
            { 
                return iterator( &data[elements] ); 
            }
            /**
             * @brief  returns a constant iterator pointing to the end mark in the list, i.e. the position just after the last element of the list.
             * 
             * @return const_iterator pointing to the end mark in the list
             */
            const_iterator cend(void) const 
            { 
                return const_iterator( &data[elements] ); 
            }

            /**
             * @brief return the first element in the vector.
             * 
             * @return reference to the first element in the vector.
             */
            reference front(void)
            { 
                return *begin(); 
            }
            
            /**
             * @brief return the last element in the vector.
             * 
             * @return reference to the last element in the vector.s
             */
            reference back(void)
            { 
                return *--end();
            }

            /**
             * @brief return the first element in the vector.
             * 
             * @return const_reference to the first element in the vector.
             */
            /// Retorna o elemento no início do vector.
            const_reference front(void) const
            { 
                return *cbegin(); 
            }
            
            /**
             * @brief /// return the end element in the vector.
             * 
             * @return const_reference to the last element in the vector.
             */
            const_reference back(void) const
            { 
                return *--cend(); 
            }
            /**
             * @brief access the element in the position pos to read, without check of limit.
             * 
             * @param pos position of the element.
             * @return const_reference const reference to the element in the postion.
             */
            const_reference operator[] ( size_type pos ) const 
            { 
                return data[ pos ]; 
            }
            /**
             * @brief inserts elements from the range [first; last) before pos.
             * 
             * @tparam InItr 
             * @param pos 
             * @param first 
             * @param last 
             * @return iterator 
             */
            template<typename InItr>
            iterator insert(iterator pos, InItr first, InItr last)
            {
                iterator it_test = begin();
                bool outside { true };
                while(it_test != end())
                {
                    if(it_test == pos)
                    {
                        outside = false;
                        break;
                    }
                    it_test++;
                        
                }
                if(it_test == pos)
                    outside = false;
                if(outside)
                    return pos;
                SIZE += (std::distance(first, last));
                pointer array = new value_type[SIZE]; 
                iterator it = begin();
                unsigned short i{0};
                while(it != end())
                {
                    while(it == pos and first != last)
                    {
                        array[i] = *first;
                        first++;
                        i++;
                    }
                    array[i] = *it;
                    i++;
                    it++;
                }
                if(pos == end())
                {
                    array[i] = *it;
                    while(first != last)
                    {
                        array[i] = (*first);
                        i++;
                        first++;
                    }
                        
                }

                delete[] data;
                data = array;
                elements = SIZE;
                return pos;
            }
            /**
             * @brief adds value into the list before the position given by the iterator pos
             * 
             * @param pos 
             * @param value 
             * @return iterator to theposition of the inserted item
             */
            iterator insert(iterator pos, const T& value)
            {
                if(SIZE == elements)
                    SIZE++;
                pointer array = new value_type[SIZE];
                iterator it = begin();
                unsigned short i{0};
                while(it != end())
                {
                    if(it == pos)
                    {
                        array[i] = value;
                        i++;
                        array[i] = *it;
                        pos = &array[i];
                    }
                    else
                    {
                        array[i] = *it;
                    }    
                    it++;
                    i++;
                }
                if(pos == end())
                {
                    array[i] = value;
                }
                elements++;

                delete[] data;
                data = array;
                return pos;
            }
            /**
             * @brief inserts elements from the initializer list ilist before pos.
             * 
             * @param pos 
             * @param il Initializer list 
             * @return iterator to the element that follows pos before the call
             */
            iterator insert(iterator pos, const std::initializer_list<T> & il)
            {
                iterator it_test = begin();
                bool outside { true };
                while(it_test != end())
                {
                    if(it_test == pos)
                    {
                        outside = false;
                        break;
                    }
                    it_test++;
                        
                }
                if(it_test == pos)
                    outside = false;
                if(outside)
                    return pos;

                SIZE += il.size();//increasing the SIZE

                auto it = begin();
                pointer array = new value_type[SIZE];//creating a new space of memory
                unsigned short i{0};//count to control the space of memory that will stores the elements
                while(it != end())
                {
                    if(it == pos)
                    {
                        auto it_il = il.begin();
                        while(it_il != il.end())
                        {
                            array[i] = *it_il;
                            i++;
                            it_il++;
                        }  
                        array[i] = *it;                           
                    }
                    else
                        array[i] = *it;
                    i++;
                    it++;
                }
                if(pos == end())
                {
                    auto it_il = il.begin();
                    while(it_il != il.end())
                        {
                            array[i] = *it_il;
                            i++;
                            it_il++;
                        }
                }
                elements += il.size();

                delete[] data;
                data = array;

                return pos;
            }

           /**
            * @brief removes the object at position pos .
            * 
            * @param pos position that will be remvoved the object.
            * @return iterator to the element that follows pos before the call
            */
            iterator erase(iterator pos)
            {
                iterator it = begin();//iterator to container begin 
                pointer array = new value_type[capacity()-1];//new space of memory
                unsigned short i{0},aux;//counter and auxiliar variable
                while(it != end())
                {

                    if(it != pos)
                    {
                        array[i] = *it;
                        i++;
                    }
                    else 
                        aux = i;
                    it++;
                    
                }
                delete[] data;//cleaning the memory
                data = array;//making data pointer to new space of memory
                elements--;//decreasing the amount of elements
                return std::next(begin(),aux);//return the 
                    
                
            }
            /**
             * @brief removes elements in the range [first; last).
             * 
             * @param first begin of the range
             * @param last  end of the range
             * @return iterator  iterator to the element that follows 
             */
            iterator erase(iterator first, iterator last)
            {
                iterator past { first };
                iterator current { last };
                while( first != current )
                {   
                    *first = *last;
                    elements--;
                    first++;
                    last++;
                }
                return past;
            }
    };
}

#endif
