#pragma once
#include "iterator_base.hpp"

namespace ft {

template<class node_type>						// it is da node
	class list_iterator : ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
	{
        public:
            typedef typename	node_type::value_type																	value_type;
            typedef				node_type*																				node_ptr;

            typedef typename	node_type::value_type*																	value_ptr;
            typedef typename	node_type::value_type&																	value_ref;

            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category				iterator_category;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type				difference_type;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer						pointer;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference						reference;


			// class	rbt_OutOfBounds : public std::exception{
			// public:
			// 	virtual const char *what( void ) const throw()
			// 	{
			// 		return ("Error: Iterator out of bounds!");
			// 	}
			// };
			~list_iterator() {};

			list_iterator( void ) : _ptr(nullptr) { }

			list_iterator(node_ptr input) : _ptr(input) { }

			list_iterator(const list_iterator &copy) { *this = copy; }

			list_iterator	&operator=(const list_iterator &copy) {
				_ptr = copy._ptr;
				return (*this);
			}

			value_ref			operator*( void ) const {
				return (_ptr->val);
			}

			value_ptr			operator->( void ) const {
				return (_ptr->val);
			}

			list_iterator		&operator--( void ) {
                _ptr = _ptr->prev;
				return (*this);
			}

			list_iterator		&operator++( void ) {
                _ptr = _ptr->next;
				return (*this);
			}

			list_iterator		operator++( int ) {
				list_iterator		tmp(*this);
				++(*this);
				return (tmp);
			}

			list_iterator		operator--( int )
			{
				list_iterator		tmp(*this);
				--(*this);
				return (tmp);
			}

			bool				operator==( const list_iterator<node_type> & other ) const
			{
				return (_ptr == other._ptr);
			}

			bool				operator!=( const list_iterator<node_type> & other ) const
			{
				return (_ptr != other._ptr);
			}

			// bool				operator==( const const_rbt_iterator_new<node_type> & other ) const
			// {
			// 	return (_ptr == other._ptr);
			// }
			//
			// bool				operator!=( const const_rbt_iterator_new<node_type> & other ) const
			// {
			// 	return (_ptr != other._ptr);
			// }

        private:
            node_ptr			_ptr;
    };

}

