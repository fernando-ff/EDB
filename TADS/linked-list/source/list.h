#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
#include <initializer_list>
using std::initializer_list;


namespace ls
{
    /**
     * @brief data structure that consists of a set of sequentially linked records called nodes
     * 
     * @tparam T genetic type
     */
    template<typename T>
    class list
    {
        private:
            // alias for types
            using value_type             = T;
            using size_type              = size_t;
            using pointer                = T*;
            using const_pointer          = const T*;
            using const_reference        = const T&;
            using reference              = T&;
        /**
         * @brief data struct that contains three fields: two link fields (references to the previous and to the next node in the sequence of nodes) and one data field
         * 
         */
        struct Node 
        {
            Node * previous; //<! Node pointer to the previous Node
            Node * next;     //<! Node pointer to the next Node
            value_type data; //<! Stores the data
            /**
             * @brief Construct a new Node Struct
             * 
             * @param data value that will be stored
             * @param p_ pointer to be the previous Node
             * @param n_ pointer to be the next Node
             */
            Node(const value_type& data = value_type(), Node *p_ = nullptr, Node * n_ = nullptr)
                :data(data), previous(p_), next(n_) {/*Empty*/}
        };

        Node * m_head; //<! pointer to the list head .
        Node * m_tail; //<! pointer to the list tail.
        int m_size;  //<! amount of elements in the list.
        public:
            /**
             * @brief class that encapsulate a pointer to some element within the list
             * 
             */
            class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
            {
			    protected:
				    Node *current;//<! Node pointer that point to the m_size in the list. 
			    public:
                    // ~const_iterator( void ) = default;
                    // const_iterator( const const_iterator& ) = default;
                    const_iterator();
                    const_iterator(  Node * pt_) : current(pt_)
                    {/* empty */}
                    // const_iterator& operator=( const const_iterator& ) = default;
                    /**
                     * @brief return a reference to the object located at the position pointed by the iterator.
                     * 
                     * @return reference reference to the object located at the position pointed by the iterator.
                     */
				    const_reference  operator*(void) const { return current->data; }
                    /**
                     * @brief advances iterator to the next location within the list
                     * 
                     * @return iterator&  to the next location within the list
                     */
				    const_iterator & operator++()
                    { 
                        current = current->next; 
                        return *this; 
                    }
                    /**
                     * @brief advances iterator to the next location within the list
                     * 
                     * @return iterator&  to the next location within the list
                     */
				    const_iterator operator++(int)
                    {
                        const_iterator retval { *this };
                        current = current->next;
                        return retval;
                    }
                    /**
                    /**
                     * @brief advances iterator to the previous location within the list
                     * 
                     * @return iterator&  to the previous location within the list
                     */
				    const_iterator & operator--()
                    { 
                        current = current->previous; 
                        return *this; 
                    }
                    /**
                     * @brief advances iterator to the previous location within the list
                     * 
                     * @return iterator&  to the previous location within the list
                     */
				    const_iterator & operator--(int)
                    {
                        iterator retval { *this };
                        current = current->previous;
                        return retval;
                    }
                    /**
                     * @brief if both are equal
                     * 
                     * @param rhs right iterator
                     * @return true if both are equal
                     * @return false if both aren't equal
                     */
				    bool operator==(const const_iterator & rhs ) const { return current == rhs.current; }
                    /**
                     * @brief if both are different
                     * 
                     * @param rhs right iterator
                     * @return true if both are different
                     * @return false if both aren't different
                     */
				    bool operator!=( const const_iterator& rhs ) const { return current != rhs.current; }
		    };
            /**
             * @brief  class that encapsulate a pointer to some element within the list
             * 
             */
            class iterator : public const_iterator
            {
                                    
                protected:
                	friend class list<T>;
                
                public:
                    /**
                     * @brief Construct a new iterator object
                     * 
                     */
                    iterator() : const_iterator() 
                    {/*empty*/}
                    /**
                     * @brief Construct a new iterator object
                     * 
                     * @param pt_ Node pointer
                     */
                    iterator( Node * pt_ ) : const_iterator(pt_) 
                    {/* empty */}
                    /**
                     * @brief return a reference to the object located at the position pointed by the iterator.
                     * 
                     * @return reference reference to the object located at the position pointed by the iterator.
                     */
				    reference operator*(void) { return const_iterator::current->data; }
                    /**
                     * @brief advances iterator to the next location within the list
                     * 
                     * @return iterator&  to the next location within the list
                     */
				    iterator & operator++()
                    {
                        const_iterator::current = const_iterator::current->next;
                        return *this;
                    }
                    /**
                     * @brief advances iterator to the next location within the list
                     * 
                     * @return iterator  to the next location within the list
                     */
				    iterator operator++(int)
                    {
                        iterator retval { *this };
                        const_iterator::current = const_iterator::current->next;
                        return retval;
                    }
                    /**
                     * @brief advances iterator to the previous location within the list
                     * 
                     * @return iterator&  to the previous location within the list
                     */
				    iterator & operator--()
                    {
                        const_iterator::current = const_iterator::current->previous;
                        return *this;
                    }
                    /**
                     * @brief advances iterator to the previous location within the list
                     * 
                     * @return iterator to the previous location within the list
                     */
				    iterator operator--(int)
                    {
                        iterator temp { *this };
                        const_iterator::current = const_iterator::current->previous;
                        return temp;
                    }
                    /**
                     * @brief if both are different
                     * 
                     * @param rhs right iterator
                     * @return true if both are different
                     * @return false if both aren't equal
                     */
                    bool operator==( const iterator& rhs) const { return const_iterator::current == rhs.current; }
                    /**
                     * @brief if both are equal
                     * 
                     * @param rhs right iterator
                     * @return true if both are equal
                     * @return false if both aren't equal
                     */
                    bool operator!=( const iterator& rhs) const { return const_iterator::current != rhs.current; }

		};
		   
            /**
             * @brief Default constructor that creates an empty list
             * 
             */
            list(/* args */)
                :m_head( new Node() )
                ,m_tail( new Node() )
                ,m_size(0)
                
            {                
                //connecting the head and the tail.
                m_head->next = m_tail;
                m_tail->previous = m_head;
            }
            /**
             * @brief Constructs the list with count default-inserted instances of T.
             * 
             * @param count the size of the list
             */
            explicit list( size_type count ) 
                :m_head( new Node() )
                ,m_tail( new Node() )
                ,m_size(0)
            {
                //connecting the head and the tail.
                m_head->next = m_tail;
	            m_tail->previous = m_head;
            
                Node * temp( m_head ); //creating a new Node pointer that point to the head.

                //We will create new spaces in the memory with Node based in the param count 
                for(unsigned short i{0}; i< count;i++)
                {
                    Node * new_node = new Node(value_type(), temp, temp->next);

                    (temp->next)->previous = new_node;

                    temp->next = new_node;

                    temp = temp->next;
                }
                m_size = count;
            }   
            /**
             * @brief Constructs the list with the contents of the range [first, last).
             * 
             * @tparam InputIt 
             * @param first the begin of the range to copy the m_size from
             * @param last the end of the range to copy the m_size from
             */
            template<typename InputIt>
            list( InputIt first, InputIt last )
                :m_head( new Node() )
                ,m_tail( new Node() )
                ,m_size(0)
            {
                m_head->next =  m_tail;
                m_tail->previous = m_head;
                //passing for the range [first, last)
                while(first != last)
                {
                    push_back(*first);//adding each element in the range in the list.
                    first++;
                }
            }
            /**
             * @brief Copy constructor. Constructs the list with the deep copy of the contents of other .
             * 
             * @param other  another list to be used as source to initialize the m_size of the list with.
             */
            list( const list& other )
                :m_head( new Node() )
                ,m_tail( new Node() )
                ,m_size(0)
            {
                m_head->next = m_tail;
	            m_tail->previous = m_head;

                //passing for each element int the otherlist
                for(auto it = other.cbegin(); it != other.cend(); it++)
                    push_back( *it );//adding each element in the range in the list.
            }
            /**
             * @brief Constructs the list with the contents of the initializer list init .
             * 
             * @param ilist initializer list to initialize the m_size of the list with.
             */
            list( std::initializer_list<T> ilist )
                :m_head( new Node() )
                ,m_tail( new Node() )
                ,m_size(0)
            {

                m_head->next = m_tail;
                m_tail->previous = m_head;

                //passing for each element int the initializer list
                for(auto it = ilist.begin(); it != ilist.end();it++)
                    push_back(*it);

            }
            /**
             * @brief Destructs the list. The destructors of the m_size are called and the used storage is deallocated. Note, that if the m_size are pointers, the pointed-to objects are not destroyed.
             * 
             */
            ~list()
            {
                //cleaning the space of memory
                clear();
                delete m_head;
                delete m_tail;

            }
            /**
             * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
             * 
             * @param other another list to be used as source to initialize the m_size of the list with.
             * @return list& 
             */
            list& operator=( const list& other )
            {
                if(this == &other)//if both lists are equal return this.
                    return *this;
                //otherwise clear this list
                clear();
                //pass for each element in the other list
                for(auto it = other.cbegin(); it != other.cend(); it++)
                    push_back( *it );// and adding each element in the this list
                return *this;
            }
            /**
             * @brief Replaces the contents with those identified by initializer list ilist
             * 
             * @param il  initializer list to initialize the m_size of the list with.
             * @return list& 
             */
            list& operator=( std::initializer_list<T> il )
            {
                clear();
                
                for(auto it = il.begin(); it != il.end(); it++)
                    push_back(*it);
                return *this;
            }

            /**
             * @brief return the number of m_size in the container.
             * 
             * @return size_type number of m_size in the container.
             */
            size_type size() const { return m_size; }
            /**
             * @brief remove all m_size from the container
             * 
             */
            void clear()
            {
                while( m_tail->previous != m_head ) 
                    pop_front();
	            m_size = 0; 
            }
            /**
             * @brief say if the container contains m_size or no.
             * 
             * @return true if the container contains no m_size
             * @return false otherwise.
             */
            bool empty() { return m_size == 0; }
            /**
             * @brief adds value to the front of the list.
             * 
             * @param value the value to insert in the list.
             */
            void push_front( const value_type& value )
            {
                Node * new_node = new Node(value, m_head, m_head->next);

                (m_head->next)->previous = new_node;
                m_head->next = new_node;

                m_size++;
            }
            /**
             * @brief adds value to the end of the list.
             * 
             * @param value the value to insert in the list.
             */
            void push_back( const value_type& value )
            {
                Node * new_node = new Node(value, m_tail->previous, m_tail);

                (m_tail->previous)->next = new_node;
                m_tail->previous = new_node;

                m_size++;
            }
            /**
             * @brief removes the object at the front of the list.
             * 
             */
            void pop_back()
            {
                if(not empty()){
		            Node * tmp = m_tail->previous;
		            (tmp->previous)->next = m_tail;
		            m_tail->previous = tmp->previous;
		            delete tmp;
		            --m_size;	
                    return;
	            }
                throw std::runtime_error("The list is empty");
            }
            /**
             * @brief  returns the object at the end of the list
             * 
             * @return const T& object at the end of the list
             */
            const T& back(){ return (m_tail->previous)->data; }
            /**
             * @brief removes the object at the front of the list.
             * 
             */
            void pop_front()
            {
                if(not empty()){
		            Node * temp = m_head->next;
		            (temp->next)->previous = m_head;
		            m_head->next = temp->next;
		            delete temp;
		            --m_size;
                    return;
                }
                throw std::runtime_error("The list is empty");
            }
            /**
             * @brief Checks if the contents of lhs and rhs are equal
             * 
             * @param lhs left content
             * @param rhs right content
             * @return true if they are equal
             * @return false if they aren't equal
             */
            bool operator==( const list& rhs)
            {
                if(size() != rhs.size()) 
                    return false;
	            auto rhs_it( rhs.cbegin() );
                for (auto lhs_it = cbegin(); lhs_it != cend(); lhs_it++, rhs_it++ )
	            	if( *lhs_it != *rhs_it ) 
                        return false;
                return true;
            }
            /**
             * @brief Checks if the contents of lhs and rhs are different
             * 
             * @param lhs left content
             * @param rhs right content
             * @return true if they are different
             * @return false if they aren't different
             */
            bool operator!=(  const list& rhs)
            {
                if(size() != rhs.size()) 
                    return true;
	            auto rhs_it( rhs.cbegin() );
                for (auto lhs_it = cbegin(); lhs_it != cend(); lhs_it++, rhs_it++ )
	            	if( *lhs_it != *rhs_it ) 
                        return true;
                return false;
            }
            /**
             * @brief returns the object at the end of the list.
             * 
             * @return const value_type& 
             */
            const_reference back() const { return (m_tail->previous)->data; }
            /**
             * @brief  returns the object at the beginning of the list.
             * 
             * @return const value_type& 
             */
            const_reference front() const { return (m_head->next)->data; }
            /**
             * @brief replaces the content of the list with copies of value value.
             * 
             * @param value 
             */
            void assign( size_type count ,const value_type& value )
            {
                for(auto it = begin(); it != end(); it++)
                    *it = value;
            }
            /**
             * @brief returns an iterator pointing to the first item in the list.
             * 
             * @return iterator pointing to the first item in the list
             */
            iterator begin(void) { return iterator (m_head->next); }
            /**
             * @brief  returns a constant iterator pointing to the first item in the list.
             * 
             * @return const_iterator pointing to the first item in the list.
             */
            const_iterator cbegin(void) const { return const_iterator( m_head->next ); }
            /**
             * @brief returns an iterator pointing to the end mark in the list.
             * 
             * @return iterator the position just after the last element of the list.
             */
            iterator end() { return iterator(m_tail); }
            /**
             * @brief returns a constant iterator pointing to the end mark in the list.
             * 
             * @return const_iterator the position just after the last element of the list
             */
            const_iterator cend() const { return const_iterator(m_tail); }
           
           /**
            * @brief removes the object at position pos .
            * 
            * @param pos 
            * @return iterator to the element that follows pos before the call.
            */
            iterator erase( iterator pos )
            {
                iterator it = begin();
	            if(pos == end()) 
                    return nullptr;
	
	            while(it != pos){
	            	if( it == end() ) 
                        return nullptr;  
	            	++it;
	            }

	        ((it.current)->previous)->next = (it.current)->next;
    	    (it.current)->next->previous = (it.current)->previous;

	        --m_size;
	        return ++it;
            }
            
            /**
             * @brief removes the object at range .
             * 
             * @param first iterator to the first element in the range 
             * @param last iterator to the element last in the range
             * @return iterator iterator to the element that follows pos before the call.
             */
            iterator erase( iterator first, iterator last )
            {
                while(first != last) 
                    first = erase(first);
	            return first;
            }    
            
            /**
             * @brief adds value into the list before the position given by the iterator pos .
             * 
             * @param pos position
             * @param value 
             * @return iterator iterator to the element that follows pos before the call.
             */
            iterator insert(iterator pos, const T& value)
            {
                Node * new_node = new Node(value, pos.current->previous, pos.current);

                ((pos.current)->previous)->next = new_node;
                (pos.current)->previous = new_node;

                m_size++;

                return iterator(new_node);
            }

            /**
             * @brief inserts m_size from the range [first; last) before pos .
             * 
             * @tparam InItr 
             * @param pos iterator to the position that will be inserts m_size.
             * @param first first element in the range
             * @param last last element in the range
             * @return iterator an iterator to the position of the inserted item.
             */
            template <typename InItr>
            iterator insert( iterator pos , InItr first , InItr last )
            {
                if(pos.current == nullptr)
                    return 0;
                while(first != last)
                {
                    insert( pos, *first );
                    first++;
                }
                return pos;     
            }

            /**
             * @brief inserts m_size from the initializer list ilist before pos.
             * 
             * @param pos iterator to the position that will be inserts m_size.
             * @param ilist initializer list
             * @return iterator  an iterator to the position of the inserted item.
             */
            iterator insert( iterator pos, std::initializer_list<value_type> ilist)
            {
                for(auto &e : ilist)
                    insert(pos, e);
                
                return iterator(pos.current);
            }
    };

} // namespace ls

#endif
