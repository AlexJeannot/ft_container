#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "../sequence_containers/ListElem.hpp"

namespace ft
{
    template < typename T, typename V >
    class ListIterator
    {
            public:
                /* Alias assignment */
                typedef V value_type;
                typedef value_type* pointer;
                typedef const value_type* const_pointer;
                typedef value_type& reference;
                typedef const value_type& const_reference;
                typedef T list_elem;
                typedef list_elem* list_elem_pointer;
                typedef const list_elem* const_list_elem_pointer;
                typedef list_elem& list_elem_reference;
                typedef const list_elem& const_list_elem_reference;
                typedef std::ptrdiff_t difference_type;

            protected:
                list_elem_pointer _iter;

            public:
                /* Constructor, Copy assignement and Destructor */
                ListIterator(void) : _iter(nullptr) {}

                ListIterator(list_elem_pointer elem) : _iter(elem) {}

                ListIterator(const ListIterator &other) : _iter(other._iter) {}

                ListIterator &operator=(const ListIterator &other)
                {
                    if (this != &other)
                        this->_iter = other._iter;
                    return (*this);
                }

                virtual ~ListIterator(void) {}


                /* Accessors operators */
                reference operator*(void) {
                    return (this->_iter->get_value());
                }

                const_reference operator*(void) const {
                    return(this->_iter->get_value());
                }

                pointer operator->(void) {
                    return (&(this->_iter->get_value()));
                }

                const_pointer operator->(void) const {
                    return (&(this->_iter->get_value()));
                }

                list_elem_pointer get_elem(void) {
                    return (this->_iter);
                }

                const_list_elem_pointer get_elem(void) const {
                    return (this->_iter);
                }


                /* Increment/Decrement operators */
                ListIterator operator++() {
                    this->_iter = this->_iter->get_next_elem();
                    return (*this);
                }

                ListIterator operator++(int) {
                    ListIterator<list_elem, value_type> copy(*this);
                    this->_iter = this->_iter->get_next_elem();
                    return (copy);
                }

                ListIterator operator--() {
                    this->_iter = this->_iter->get_prev_elem();
                    return (*this);
                }

                ListIterator operator--(int) {
                    ListIterator<list_elem, value_type> copy(*this);
                    this->_iter = this->_iter->get_prev_elem();
                    return (copy);
                }


                /* Comparison operators */
                bool operator==(const ListIterator &other) {
                    return (this->_iter == other._iter);
                }

                bool operator!=(const ListIterator &other) {
                    return (this->_iter != other._iter);
                }
    };
}

#endif