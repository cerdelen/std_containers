#pragma once

#include <memory>

// template<typename T, typename Alloc = std::allocator<T> >
// class list



namespace ft {

    template<typename T, typename Alloc = std::allocator<T> >
    class list {
        private:
            struct Node {
                Node* next;
                Node* prev;
                T*      val;
            };
        public:
            typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;

            list(){};
            list(const list&) {};
            list& operator=(const list&) ;
            list(list&&) {};
            list& operator=(list&&) ;
            ~list() {};





            size_type size() const {return 0;};
    };
}
