#pragma once

#include <memory>

// template<typename T, typename Alloc = std::allocator<T> >
// class list



namespace ft {

    template<typename T, typename Alloc = std::allocator<T> >
    class list {
        public:
            typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;

            list(): _size(0), _begin(nullptr), _end(nullptr) {};
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
                Node* new_node = node_alloc.allocate(1);

                new_node->val = value;
                new_node->next = _begin;
                new_node->prev = nullptr;


                if (_begin == nullptr) {
                    _end = new_node;
                } else {
                    _begin->prev = new_node;
                }

                _begin = new_node;
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
                Node* new_node = node_alloc.allocate(1);

                new_node->val = value;
                new_node->prev = _end;
                new_node->next = nullptr;


                if (_begin == nullptr) {
                    _begin = new_node;
                } else {
                    _end->next = new_node;
                }

                _end = new_node;
                _size += 1;
            };

            // Parameters
            //     (none)
            // Return value
            //     Reference to the first element.
            // Complexity
            //     Constant.
            // Notes
            //     For a container c, the expression c.front() is equivalent to *c.begin().
            reference front() {*(this->begin())};
            const_reference front() const {};


        private:
            struct Node {
                Node* next;
                Node* prev;
                T      val;
            };
            size_type   _size;
            Node*   _begin;
            Node*   _end;
            std::allocator<Node> node_alloc;
            allocator_type _alloc;
    };
}
