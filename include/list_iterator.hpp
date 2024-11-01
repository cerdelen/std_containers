#pragma once
#include "iterator_base.hpp"

namespace ft {

    template<class node_type>
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

        protected:
            node_ptr			_ptr;
    };

    template<class node_type>
	class const_list_iterator : ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
	{
        public:
            typedef const typename	node_type::value_type																value_type;
            typedef				node_type*																				node_ptr;

            typedef const typename	node_type::value_type*																	value_ptr;
            typedef const typename	node_type::value_type&																	value_ref;

            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category				iterator_category;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type				difference_type;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer						pointer;
            typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference						reference;

			~const_list_iterator() {};

			const_list_iterator( void ) : _ptr(nullptr) { }

			const_list_iterator(node_ptr input) : _ptr(input) { }

			const_list_iterator(const const_list_iterator &copy) { *this = copy; }

			const_list_iterator	&operator=(const const_list_iterator &copy) {
				_ptr = copy._ptr;
				return (*this);
			}

			value_ref			operator*( void ) const {
				return (_ptr->val);
			}

			value_ptr			operator->( void ) const {
				return (_ptr->val);
			}

			const_list_iterator		&operator--( void ) {
                _ptr = _ptr->prev;
				return (*this);
			}

			const_list_iterator		&operator++( void ) {
                _ptr = _ptr->next;
				return (*this);
			}

			const_list_iterator		operator++( int ) {
				const_list_iterator		tmp(*this);
				++(*this);
				return (tmp);
			}

			const_list_iterator		operator--( int )
			{
				const_list_iterator		tmp(*this);
				--(*this);
				return (tmp);
			}

			bool				operator==( const const_list_iterator<node_type> & other ) const
			{
				return (_ptr == other._ptr);
			}

			bool				operator!=( const const_list_iterator<node_type> & other ) const
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

        protected:
            node_ptr			_ptr;
    };
}
