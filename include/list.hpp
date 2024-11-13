#pragma once

#include <iostream>
#include <memory>
#include <utility>
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
                    return *this;
                }
                Node* ptr = other._base.prev;
                while (ptr != &other._base) {
                    this->push_front(*ptr->val);
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
            iterator erase( iterator pos ) noexcept {
                iterator out = pos._ptr->next;
                __remove(pos._ptr, true);
                return out;
            };
            iterator erase( iterator first, iterator last ) noexcept{
                while(first != last) {
                    this->erase(first++);
                }
                return first;
            };

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
                // std::cout << "single insert called" << std::endl;
                __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *get_node(value));
                return iterator(pos._ptr->prev);
            };
            iterator insert( const_iterator pos, size_type count, const T& value ) {
                // std::cout << "count insert called" << std::endl;
                if (count == 0) {
                    return iterator((Node*)pos._ptr);
                }
                for (; count > 0; count--, pos--) {
                    __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *get_node(value));
                }
                return iterator((Node*)pos._ptr);
            };

            // second parameter is to ensure that if the second template is indeed size_type the correct insert gets caleld and not this one
            template< class InputIt , typename = typename std::enable_if<!std::is_integral<InputIt>::value>::type>
            iterator insert( const_iterator pos, InputIt first, InputIt last ) {
                // std::cout << "range insert called" << std::endl;
                if (first == last) {
                    return iterator((Node*)pos._ptr);
                }
                iterator out((Node*)pos._ptr->prev);
                for (; first != last; first++) {
                    __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *get_node(*first));
                }
                return ++out;
            };

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
                while (count > _size) {
                    __insert(*this->_base.prev, this->_base, *get_node());
                }
                while (count < _size) {
                    this->pop_back();
                }
            }
            void resize( size_type count, const value_type& value ) {
                while (count > _size) {
                    this->push_back(value);
                }
                while (count < _size) {
                    this->pop_back();
                }
            }

            void swap( list& other ) {
                __swap(&this->_base, &other._base);
                if (this->_size == 0) {
                    other._base.next = &other._base;
                    other._base.prev = &other._base;
                }
                if (other._size == 0) {
                    this->_base.next = &this->_base;
                    this->_base.prev = &this->_base;
                }
                size_type temp = this->_size;
                this->_size = other._size;
                other._size = temp;
            };

            void merge(list &other ) {
                iterator it_other = other.begin();
                iterator it_this = this->begin();
                while(it_other != other.end()) {
                    while (it_this != this->end() && !(*it_other < *it_this))
                        it_this++;
                    __insert(*(Node*)it_this._ptr->prev, *(Node*)it_this._ptr, *(Node*)it_other++._ptr);
                }
                other.reinit();
            }

            template< class Compare >
            void merge(list &other, Compare comp) {
                iterator it_other = other.begin();
                iterator it_this = this->begin();
                while(it_other != other.end()) {
                    while (it_this != this->end() && !(comp(*it_other, *it_this)))
                        it_this++;
                    __insert(*(Node*)it_this._ptr->prev, *(Node*)it_this._ptr, *(Node*)it_other++._ptr);
                }
                other.reinit();
            }

            void splice( iterator pos, list &other) {
                iterator it_other = other.begin();
                while(it_other != other.end()) {
                    __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *(Node*)it_other++._ptr);
                }
                other.reinit();
            }

            void splice( iterator pos, list &other, iterator it ) {
                iterator before = it;
                before--;
                size_type i = 0;
                while(it != other.end()) {
                    __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *(Node*)it++._ptr);
                    i++;
                }
                before._ptr->next = (Node*)&other._base;
                other._base.prev = (Node*)before._ptr;
                other._size -= i;
            }

            void splice( iterator pos, list &other, iterator first, iterator last ) {
                iterator before = first;
                before--;
                size_type i = 0;
                while(first != last) {
                    __insert(*(Node*)pos._ptr->prev, *(Node*)pos._ptr, *(Node*)first++._ptr);
                    i++;
                }
                before._ptr->next = (Node*)last._ptr;
                last._ptr->prev = before._ptr;
                other._size -= i;
            }

            void reverse() noexcept {
                if (_size == 0)
                    return;
                iterator it = this->begin();
                Node* temp;
                while(it != this->end()) {
                    temp = it._ptr->next;
                    it._ptr->next = it._ptr->prev;
                    it._ptr->prev = temp;
                    it--;
                }
                temp = _base.next;
                _base.next = _base.prev;
                _base.prev = temp;
            }

            void unique() {
                iterator it = this->begin();
                iterator temp = it++;
                while (it != this->end()) {
                    if (*it == *temp) {
                        __remove((it++)._ptr, true);
                    }
                    else {
                        temp = it++;
                    }
                }
            }

            template< class BinaryPredicate >
            void unique( BinaryPredicate p ) {
                iterator it = this->begin();
                iterator temp = it++;
                while (it != this->end()) {
                    if (p(*it, *temp)) {
                        __remove((it++)._ptr, true);
                    }
                    else {
                        temp = it++;
                    }
                }
            }

            void sort() {
                __sort(*this);
            }

            template< class Compare >
            void sort(Compare comp) {
                __sort(*this, comp);
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
                Node*   next;
                Node*   prev;
                T*      val = NULL;
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

            void __swap(Node* first, Node* second) {
                Node* first_next = first->next;
                Node* first_prev = first->prev;
                Node* second_next = second->next;
                Node* second_prev = second->prev;

                first_prev->next = second;
                first_next->prev = second;
                second_prev->next = first;
                second_next->prev = first;

                first->next = second_next;
                first->prev = second_prev;
                second->next = first_next;
                second->prev = first_prev;
            };

            // helper functions
            void __insert(Node& prev, Node& next, Node& _new_node) {
                _new_node.next = &next;
                _new_node.prev = &prev;

                next.prev = &_new_node;
                prev.next = &_new_node;
                this->_size++;
                // if (_new_node.next == &this->_base)
                    // this->_base.val = _new_node.val;
            };

            void __remove(Node* node, bool linking) noexcept {
                this->_size -= 1;
                if (linking) {
                    node->next->prev = node->prev;
                    node->prev->next = node->next;
                    // if (_size == 0)
                    //     this->_base.val = value_type();
                    // else if (node->next == &this->_base)
                    //     this->_base.val = this->_base.prev->val;
                }
                _alloc.deallocate(node->val, 1);
                node_alloc.deallocate(node, 1);
            };

            Node* get_node(const T& val) {
                Node* out = node_alloc.allocate(1);
                pointer ptr = _alloc.allocate(1);

                *ptr = val;

                out->val = ptr;
                return out;
            };

            Node* get_node() {
                Node* out = node_alloc.allocate(1);
                pointer ptr = _alloc.allocate(1);

                out->val = ptr;
                return out;
            };

            void reinit() {
                this->_base.next = &this->_base;
                this->_base.prev = &this->_base;
                this->_size = 0;
            };

            template< class  Compare = std::less<>>
            void __sort(list& l, Compare comp = Compare()) {
                if (l.size() <= 1)
                    return ;

                iterator it = l.begin();
                for (size_type i = 0; i < l.size() / 2; i++)
                    it++;
                list right, left;
                left.splice(left.begin(), l, l.begin(), it);
                right.splice(right.begin(), l, l.begin(), l.end());

                __sort(left, comp);
                __sort(right, comp);

                iterator it_r = right.begin();
                iterator it_l = left.begin();
                while (it_r != right.end() && it_l != left.end()) {
                    it = l.end();
                    if (comp(*it_l, *it_r)) {
                        l.splice(it, left, it_l++, it_l);
                    } else {
                        l.splice(it, right, it_r++, it_r);
                    }
                }
                l.splice(l.end(), left);
                l.splice(l.end(), right);
            }
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
