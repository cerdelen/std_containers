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
			// typedef	typename ft::const_random_access_iterator<const T>		const_iterator;
			// typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

            list(): _size(0) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
            };
            list(const list& other): _size(other._size){};
            list& operator=(const list& other) ;
            list(list&& other) {};
            list& operator=(list&& other) ;
            ~list() {};

            size_type size() const noexcept {return _size;};



            // Parameters:
            //     value: the value of the element to prepend
            // Return value:
            //     (none)
            // Complexity:
            //     Constant
            // Exceptions:
            //     If an exception is thrown for any reason, these functions have no effect (strong exception safety guarantee).
            void push_front(const T& value) {
                Node* new_node = get_node(value);

                new_node->next = this->_base.next;
                new_node->prev = &(this->_base);

                new_node->next->prev = new_node;

                this->_base.next = new_node;

                _size += 1;
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
                Node* new_node = get_node(value);

                new_node->next = &(this->_base);
                new_node->prev = this->_base.prev;

                new_node->prev->next = new_node;

                this->_base.prev = new_node;

                _size += 1;
            };

            iterator begin() {return iterator(this->_base.next);};
            iterator end() {return iterator(&this->_base);};

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


        private:
            struct Node {
                Node* next;
                Node* prev;
                T      val;
                typedef T value_type;
            };
            size_type   _size;
            Node        _base;

            std::allocator<Node> node_alloc;
            allocator_type _alloc;

            // helper functions
            void insert(Node& prev, Node& _new_node) {
                _new_node.next = prev.next;
                _new_node.prev = prev;

                prev.next->prev = _new_node;
                prev.next = _new_node;
            };

            Node* get_node(const T& val) {
                Node* out = node_alloc.allocate(1);

                out->val = val;
                return out;
            };
    };
}
