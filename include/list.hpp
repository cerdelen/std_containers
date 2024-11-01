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
			typedef	typename ft::const_list_iterator<const Node>		const_iterator;
			// typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

            list(): _size(0) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                this->_base.val = T{};
            };
            list(const list& other) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                for (auto elem: other) {
                    this->push_back(elem);
                }
            };
            list& operator=(const list& other) ;
            list(const list&& other) {
                this->_base.next = &(this->_base);
                this->_base.prev = &(this->_base);
                for (auto elem: other) {
                    this->push_back(elem);
                }
            };
            list& operator=(list&& other) ;
            ~list() {
                Node *ptr = this->_base.next;
                Node *tmp = nullptr;
                while(ptr != &this->_base) {
                    tmp = ptr->next;
                    __remove(ptr, false);
                    ptr = tmp;
                }
            };

            inline size_type size() const noexcept {return _size;};

            inline bool empty() const noexcept {return _size == 0;};


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
