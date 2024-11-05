#pragma once

#include <iostream>
#include <memory>
#include "list_iterator.hpp"

// template<typename T, typename Alloc = std::allocator<T> >
// class list

namespace ft {

    template<typename T, typename Alloc = std::allocator<T> >
    class list {
            struct Node;
        public:
            typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;

            typedef typename ft::list_iterator<Node> 					iterator;
			typedef	typename ft::const_list_iterator<const Node>		        const_iterator;
			// typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

            list() {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                this->_base.val = T{};
            };
            list(const list& other) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                *this = other;
            };
            list& operator=(const list& other) {
                if (this == &other)
                    return *this;
                this->clear();
                if (other._size == 0) {
                    this->_base.val = T{};
                    return *this;
                }
                Node* ptr = other._base.prev;
                while (ptr != &other._base) {
                    this->push_front(ptr->val);
                    ptr = ptr->prev;
                }
                return *this;
            };
            list(const list&& other) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                *this = other;
            };
            list& operator=(list&& other) {
                if (this == &other)
                    return *this;
                this->clear();
                if (other._size == 0) {
                    this->_base.val = T{};
                    return *this;
                }
                Node* ptr = other._base.prev;
                while (ptr != &other._base) {
                    this->push_front(ptr->val);
                    ptr = ptr->prev;
                }
                return *this;
            };
            ~list() { this->clear(); };

            inline size_type size() const noexcept {return _size;};

            inline bool empty() const noexcept {return _size == 0;};

            // Parameters:
            //     pos          -	iterator to the element to remove
            //     first, last	-	range of elements to remove
            // Return value:
            //     1) If pos refers to the last element, then the end() iterator is returned.
            //     2) If last == end() prior to removal, then the updated end() iterator is returned.
            //            If [first, last) is an empty range, then last is returned.
            // Complexity:
            //     1) Constant
            //     2) Linear in distance between first and last
            // Exceptions:
            //     No Exceptions
            iterator erase( iterator pos ) noexcept { return this->begin();};
            iterator erase( iterator first, iterator last ) noexcept{ return this->begin();};

            // Parameters:
            //     pos          -	iterator before which the content will be inserted (pos may be the end() iterator)
            //     value	    -	element value to insert
            //     count	    -	number of elements to insert
            //     first, last	-	the range of elements to insert, cannot be iterators into container for which insert is called
            // Return value:
            //     1) Iterator pointing to the inserted value.
            //     2) Iterator pointing to the first element inserted, or pos if count == 0.
            //     3) Iterator pointing to the first element inserted, or pos if first == last.
            // Complexity:
            //     1) Constant
            //     2) Linear in count
            //     3) Linear in std::distance(first, last).
            // Exceptions:
            //     If an exception is thrown for any reason, these functions have no effect (strong exception safety guarantee).
            iterator insert( const_iterator pos, const T& value ) {
                Node* prev = (Node*)pos._ptr->prev;
                Node* next = (Node*)pos._ptr;
                Node* new_node = get_node(value);
                __insert(*prev, *next, *new_node);
                return iterator(new_node);
            };
            iterator insert( const_iterator pos, size_type count, const T& value ) { return this->begin();};
            template< class InputIt >
            iterator insert( const_iterator pos, InputIt first, InputIt last ) { return this->begin();};

            void clear() {
                Node* ptr = this->_base.next;

                while(ptr != &this->_base) {
                    ptr = ptr->next;
                    __remove(ptr->prev, false);
                }
                this->_base.next = &this->_base;
                this->_base.prev = &this->_base;
            };

            // Parameters:
            //     value: the value of the element to prepend
            // Return value:
            //     (none)
            // Complexity:
            //     Constant
            // Exceptions:
            //     If an exception is thrown for any reason, these functions have no effect (strong exception safety guarantee).
            void push_front(const T& value) {
                __insert(this->_base, *this->_base.next, *get_node(value));
            };

            // Parameters:
            //     value: the value of the element to append
            // Return value:
            //     (none)
            // Complexity:
            //     Constant
            // Exceptions:
            //     If an exception is thrown for any reason, these functions have no effect (strong exception safety guarantee).
            void push_back(const T& value) {
                __insert(*this->_base.prev, this->_base, *get_node(value));
            };

            // Parameters
            //     (none)
            //
            // Return value
            //     (none)
            //
            // Complexity
            //     Constant.
            //
            // Exceptions
            //      Throws nothing.
            void pop_back() noexcept {
                if (this->_size > 0)
                    __remove(this->_base.prev, true);
            }
            void pop_front() noexcept {
                if (this->_size > 0)
                    __remove(this->_base.next, true);
            }

            iterator begin() {return iterator(this->_base.next);};
            iterator end() {return iterator(&this->_base);};
            const_iterator begin() const {return const_iterator(this->_base.next);};
            const_iterator end() const {return const_iterator(&this->_base);};

            // Parameters
            //     (none)
            // Return value
            //     Reference to the first element.
            // Complexity
            //     Constant.
            // Notes
            //     For a container c, the expression c.front() is equivalent to *c.begin().
            reference front() {return *(this->begin());};
            // const_reference front() const {};

            reference back() {
                return *(--(this->end()));
            };
            // const_reference back() const {};

            // Parameters
            //     count	-	new size of the container
            //     value	-	the value to initialize the new elements with
            // Type requirements
            //     -T must meet the requirements of DefaultInsertable in order to use overload (1).
            //     -T must meet the requirements of CopyInsertable in order to use overload (2).
            // Complexity
            //     Linear in the difference between the current size and count.
            //
            // Notes
            //     If value-initialization in overload (1) is undesirable, for example, if the elements are of non-class type and zeroing out
            //     is not needed, it can be avoided by providing a custom Allocator::construct.
            void resize( size_type count ) {
                value_type val{};
                resize(count, val);
            }
            void resize( size_type count, const value_type& value ) {
                while (count > _size) {
                    this->push_back(value);
                }
                while (count < _size) {
                    this->pop_back();
                }
            }



            void print(){
                std::cout << "[ ";
                for(iterator it = this->begin(); it != this->end(); it++){
                    std::cout << *it << ", ";
                }
                std::cout << "]" << std::endl;
            }


        private:
            struct Node {
                Node* next;
                Node* prev;
                T      val;
                typedef T value_type;
                // this would be good coding praxis but in praxis except for constructor of lsit itself
                // this would only unnecessarily set next and prev 2 times
                // Node() {
                //     this->next = this;
                //     this->prev = this;
                // }
            };
            size_type   _size = 0;
            Node        _base;

            std::allocator<Node> node_alloc;
            allocator_type _alloc;

            // helper functions
            void __insert(Node& prev, Node& next, Node& _new_node) {
                _new_node.next = &next;
                _new_node.prev = &prev;

                next.prev = &_new_node;
                prev.next = &_new_node;
                this->_size++;
                if (_new_node.next == &this->_base)
                    this->_base.val = _new_node.val;
            };

            void __remove(Node* node, bool linking) noexcept {
                this->_size -= 1;
                if (linking) {
                    node->next->prev = node->prev;
                    node->prev->next = node->next;
                    if (_size == 0)
                        this->_base.val = value_type();
                    else if (node->next == &this->_base)
                        this->_base.val = this->_base.prev->val;
                }
                node_alloc.deallocate(node, 1);
            };

            Node* get_node(const T& val) {
                Node* out = node_alloc.allocate(1);

                out->val = val;
                return out;
            };
    };
}





template< class T, class Alloc >
bool operator==( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    if (lhs.size() != rhs.size())
        return false;
    if (&lhs == &rhs)
        return true;
    typename ft::list<T, Alloc>::const_iterator l_it = lhs.begin();
    typename ft::list<T, Alloc>::const_iterator r_it = rhs.begin();
    while(l_it != lhs.end()) {
        if (*l_it != *r_it)
            return false;
        l_it++;
        r_it++;
    }
    return true;
};

template< class T, class Alloc >
bool operator!=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    return !(lhs == rhs);
};

template< class T, class Alloc >
bool operator<( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    if (&lhs == &rhs)
        return false;
    typename ft::list<T, Alloc>::const_iterator l_it = lhs.begin();
    typename ft::list<T, Alloc>::const_iterator r_it = rhs.begin();
    while (l_it != lhs.end() && r_it != rhs.end()) {
        if ( *l_it == *r_it ) {
            l_it++;
            r_it++;
            continue; ;
        }
        if ( *l_it < *r_it )
            return true;
        return false;
    }
    if ( r_it != rhs.end() )
        return true;
    return false;
};

template< class T, class Alloc >
bool operator>( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    if (&lhs == &rhs)
        return false;
    typename ft::list<T, Alloc>::const_iterator l_it = lhs.begin();
    typename ft::list<T, Alloc>::const_iterator r_it = rhs.begin();
    while (l_it != lhs.end() && r_it != rhs.end()) {
        if ( *l_it == *r_it ) {
            l_it++;
            r_it++;
            continue; ;
        }
        if ( *l_it > *r_it )
            return true;
        return false;
    }
    if ( l_it != lhs.end() )
        return true;
    return false;
};

template< class T, class Alloc >
bool operator<=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    return !(lhs > rhs);
};

template< class T, class Alloc >
bool operator>=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
    return !(lhs < rhs);
};
