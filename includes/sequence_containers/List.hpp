#ifndef LIST_HPP
# define LIST_HPP

# include <cmath>
# include <iostream>
# include <exception>
# include "./ListElem.hpp"
# include "../iterators/ListIterator.hpp"
#include "../iterators/ReverseIterator.hpp"


namespace ft
{
    template < typename T, typename Alloc = std::allocator< ListElem<T> > >
    class List
    {
        public:
            /* Alias assignement */
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef ListElem<value_type> list_elem;
            typedef list_elem* list_elem_pointer;
            typedef const list_elem* const_list_elem_pointer;
            typedef list_elem& list_elem_reference;
            typedef const list_elem& const_list_elem_reference;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef ListIterator<list_elem, value_type> iterator;
            typedef ListIterator<const list_elem, const value_type> const_iterator;
            typedef ReverseIterator<iterator> reverse_iterator;
            typedef ReverseIterator<const_iterator> const_reverse_iterator;

        private:
            /* private member variables */
            list_elem_pointer _first;
            list_elem_pointer _begin;
            list_elem_pointer _end;
            size_type _size;
            allocator_type _alloc;


            /* private member functions */
            void setup_border(void)
            {
                this->_end = this->_alloc.allocate(1);
                this->_alloc.construct(this->_end, value_type());
                this->_begin = this->_alloc.allocate(1);
                this->_alloc.construct(this->_begin, value_type());
                this->_end->set_prev_elem(this->_begin);
                this->_begin->set_next_elem(this->_end);
                this->_first = this->_end;
            }

            void reset_border(void)
            {
                this->_size = 0;
                this->_end->set_prev_elem(this->_begin);
                this->_begin->set_next_elem(this->_end);
                this->_first = this->_end;
            }

            static bool is_equal(const_reference x, const_reference y) {
                return (x == y);
            }

            static bool less(value_type first, value_type second) {
                return (first < second);
            }


        public:
            /* Constructors, Copy assignement and Destructor */
            List(const allocator_type& alloc = allocator_type())
            : _first(nullptr), _begin(nullptr), _end(nullptr), _size(0), _alloc(alloc)
            {
                setup_border();
            }

            List(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type())
            : _first(nullptr), _begin(nullptr), _end(nullptr), _size(0), _alloc(alloc)
            {
                setup_border();
                if (n > 0)
                    this->assign(n, val);
            }

            List(const List &other)
            : _first(nullptr), _begin(nullptr), _end(nullptr), _size(0), _alloc(other._alloc)
            {
                setup_border();
                if (other._size > 0)
                    this->assign(other.begin(), other.end());
            }

            ~List()
            {
                this->clear();
                this->_alloc.destroy(this->_end);
                this->_alloc.deallocate(this->_end, 1);
                this->_alloc.destroy(this->_begin);
                this->_alloc.deallocate(this->_begin, 1);
            }

            List &operator=(const List &other)
            {
                if (this != &other)
                    this->assign(other.begin(), other.end());
                return (*this);
            }


            /* Iterator member functions */
            iterator begin(void) {
                return (iterator(this->_first));
            }

            const_iterator begin(void) const {
                return (const_iterator(this->_first));
            }

            iterator end(void) {
                return (iterator(this->_end));
            }

            const_iterator end(void) const {
                return (const_iterator(this->_end));
            }

            const_iterator cbegin(void) const {
                return (const_iterator(this->_first));
            }

            const_iterator cend(void) const {
                return (const_iterator(this->_end));
            }

            reverse_iterator rbegin(void) {
                return (reverse_iterator(this->end()));
            }

            const_reverse_iterator rbegin(void) const {
                return (const_reverse_iterator(this->end()));
            }

            reverse_iterator rend(void) {
                return (reverse_iterator(this->begin()));
            }

            const_reverse_iterator rend(void) const {
                return (const_reverse_iterator(this->begin()));
            }

            const_reverse_iterator crbegin(void) const {
                return (const_reverse_iterator(this->end()));
            }

            const_reverse_iterator crend(void) const {
                return (const_reverse_iterator(this->begin()));
            }


            /* Capacity member functions */
            size_type size(void) const {
                return this->_size;
            }

            size_type max_size(void) const
            {
                return (std::numeric_limits<size_type>::max() / sizeof(list_elem));
                //return (std::min((size_type) std::numeric_limits<difference_type>::max(),
                //        std::numeric_limits<size_type>::max() / sizeof(list_elem)));
            }

            bool empty() const {
                return (this->_size == 0);
            }


            /* Element access member functions */
            reference front(void) {
                return (this->_first->get_value());
            }

            const_reference front(void) const {
                return (this->_first->get_value());
            }

            reference back(void) {
               return (this->_size) ? this->_end->get_prev_elem()->get_value() : this->_end->get_value();
            }

            const_reference back(void) const {
               return (this->_size) ? this->_end->get_prev_elem()->get_value() : this->_end->get_value();
            }
            
            
            /* Modifier member functions */
            void assign(size_type n, const_reference val)
            {
                this->clear();
                for (size_type count = 0; count < n; count++)
                    this->push_back(val);
            }

            template <typename InputIterator>
            void assign(InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                List<value_type> tmp;
                for (; first != last; first++)
                    tmp.push_back(*first);
                this->clear();
                iterator tmp_first(tmp.begin());
                iterator tmp_last(tmp.end());
                for (; tmp_first != tmp_last; tmp_first++)
                    this->push_back(*tmp_first);
            }

            void push_front(const_reference val)
            {
                list_elem_pointer new_elem = this->_alloc.allocate(1);

                this->_alloc.construct(new_elem, val);
                this->_first = this->_first->add_before(new_elem);
                this->_size++;
            }

            void pop_front()
            {
                list_elem_pointer tmp_ptr = this->_first;

                if (this->_size > 0)
                {
                    this->_first = this->_first->delete_elem(true);
                    this->_alloc.deallocate(tmp_ptr, 1);
                    this->_size--;
                }
                if (this->_size == 0)
                    this->reset_border();
            }

            void push_back(const_reference val)
            {
                list_elem_pointer new_elem = this->_alloc.allocate(1);

                this->_alloc.construct(new_elem, val);
                this->_end->add_before(new_elem);
                if (this->_first == this->_end)
                    this->_first = new_elem;
                this->_size++;
            }

            void pop_back()
            {
                list_elem_pointer tmp_ptr(this->_end->get_prev_elem());

                if (this->_size > 0)
                {
                    this->_end->get_prev_elem()->delete_elem();
                    this->_alloc.deallocate(tmp_ptr, 1);
                    this->_size--;
                }
                if (this->_size == 0)
                    this->reset_border();
            }

            iterator insert(iterator position, const_reference val)
            {
                list_elem_pointer new_elem = this->_alloc.allocate(1);

                this->_alloc.construct(new_elem, val);
                position.get_elem()->add_before(new_elem);
                if (position.get_elem() == this->_first)
                    this->_first = new_elem;
                this->_size++;
                return (iterator(new_elem));
            }

            void insert(iterator position, size_type n, const_reference val)
            {
                if (n > 0)
                {
                    for (size_type count = 0; count < n; count++)
                        this->insert(position, val);
                }
            }

            template < typename InputIterator >
            void insert(iterator position, InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                List<value_type> tmp;
                iterator pos(tmp.begin());
                for (; first != last; first++)
                    tmp.insert(pos, *first);
                iterator test_first(tmp.begin());
                iterator test_last(tmp.end());
                for (; test_first != test_last; test_first++)
                    this->insert(position, *test_first);
            }

            iterator erase(iterator position)
            {
                iterator return_iterator(position);
                
                return_iterator++;
                if (position.get_elem() == this->_first)
                    this->_first = position.get_elem()->delete_elem(true);
                else
                    position.get_elem()->delete_elem(true);
                this->_alloc.destroy(position.get_elem());
                this->_alloc.deallocate(position.get_elem(), 1);
                this->_size--;
                return (return_iterator);
            }

            iterator erase(iterator first, iterator last)
            {
                size_type erase_size(0);

                for (iterator copy(first); copy != last; copy = first)
                {
                    first++;
                    erase(copy);
                }
                return (last);
            }

            void swap(List& other)
            {
                list_elem_pointer tmp_first = this->_first;
                list_elem_pointer tmp_end = this->_end;
                size_type tmp_size = this->_size;
                allocator_type tmp_alloc = this->_alloc;

                this->_first = other._first;
                this->_end = other._end;
                this->_size = other._size;
                this->_alloc = other._alloc;

                other._first = tmp_first;
                other._end = tmp_end;
                other._size = tmp_size;
                other._alloc = tmp_alloc;
            }

            void resize(size_type n, value_type val = value_type())
            {
                size_type save_size(this->_size);

                if (n < this->_size)
                {
                    for (; n < save_size; n++)
                        this->pop_back();
                }
                if (n > this->_size)
                {
                    for (; n > save_size; n--)
                        this->push_back(val);
                }
            }

            void clear(void)
            {
                if (this->_size > 0)
                {
                    iterator first(this->begin());
                    iterator next(first);
                    iterator last(this->end());
                    for (next++; first != last; next++)
                    {
                        //std::cout << "*first = " << *first << std::endl;
                        //std::cout << "*next = " << *next << std::endl;
                        this->_alloc.destroy(first.get_elem());
                        this->_alloc.deallocate(first.get_elem(), 1);
                        first = next;
                    }
                    //std::cout << "this->_end->get_prev_elem()->get_value() = " << this->_end->get_prev_elem()->get_value() << std::endl;
                    //this->_alloc.destroy(this->_end->get_prev_elem());
                    //this->_alloc.deallocate(this->_end->get_prev_elem(), 1);
                    this->reset_border();
                }
            }


            /* Operation member functions */
            void splice(iterator position, List& x)
            {
                iterator first(x.begin());
                iterator next(first);
                iterator last(x.end());
                for (next++; first != last; next++)
                {
                    first.get_elem()->delete_elem();
                    if (position.get_elem() == this->_first)
                        this->_first = position.get_elem()->add_before(first.get_elem());
                    else
                        position.get_elem()->add_before(first.get_elem());
                    first = next;
                    this->_size++;
                }
                x.reset_border();
            }

            void splice(iterator position, List& x, iterator i)
            {
                if (x._size > 0 && position.get_elem() != i.get_elem())
                {
                    i.get_elem()->delete_elem();
                    if (position.get_elem() == this->_first)
                        this->_first = position.get_elem()->add_before(i.get_elem());
                    else
                        position.get_elem()->add_before(i.get_elem());
                    this->_size++;
                    x._size--;
                    if (x._size == 0)
                        x.reset_border();
                }
            }

            void splice(iterator position, List& x, iterator first, iterator last)
            {
                iterator next(first);
                if (x._size > 0)
                {
                    for (next++; first != last; next++)
                    {
                        splice(position, x, first);
                        first = next;
                    }
                }
            }

            void remove(const_reference val)
            {
                iterator first(this->begin());
                iterator last(this->end());

                for (; first != last;)
                {
                    if (*first == val)
                        first = erase(first);
                    else
                        first++;
                }
            }


            template <class Predicate>
            void remove_if (Predicate pred)
            {
                iterator first(this->begin());
                iterator last(this->end());

                for (; first != last;)
                {
                    if (pred(*first))
                        first = erase(first);
                    else
                        first++;
                }
            }

            void unique(void) {
                unique(this->is_equal);
            }

            template <class BinaryPredicate>
            void unique(BinaryPredicate binary_pred)
            {
                iterator first(this->begin());
                iterator next(first);
                iterator last(this->end());

                for (next++; next != last; next++)
                {
                    if (binary_pred(*next, *first))
                    {
                        first = this->erase(next);
                        next = first;
                    }
                    else
                        first++;
                }
            }

            void merge(List& x) {
                merge(x, this->less);
            }

            template <class Compare>
            void merge(List& x, Compare comp)
            {
                if (this != &x)
                {
                    iterator first(this->begin());
                    iterator last(this->end());
                    iterator merge_first(x.begin());
                    iterator merge_next(merge_first);
                    iterator merge_last(x.end());
                    for (merge_next++; merge_first != merge_last; merge_next++)
                    {
                        while (first != last && comp(*first, *merge_first))
                            first++;
                        first.get_elem()->add_before(merge_first.get_elem());
                        if (first.get_elem() == this->_first)
                            this->_first = merge_first.get_elem();
                        merge_first = merge_next;
                        this->_size++;
                    }
                    x.reset_border();
                }
            }


            void sort() {
                sort(this->less);
            }

            template <class Compare>
            void sort(Compare comp)
            {
                iterator first(this->begin());
                iterator next(first);
                iterator last(this->end());

                for (next++; next != last; next++)
                {
                    if (comp(*next, *first))
                    { 
                        next.get_elem()->delete_elem();
                        if (first.get_elem() == this->_first)
                            this->_first = first.get_elem()->add_before(next.get_elem());
                        else
                            first.get_elem()->add_before(next.get_elem());
                        first = this->begin();
                        next = first;
                    }
                    else
                        first++;
                }
            }

            void reverse(void)
            {
                iterator first(this->begin());
                iterator last(this->_end->get_prev_elem()->get_prev_elem());
                iterator next(last.get_elem()->get_prev_elem());
                list_elem_pointer new_first(this->_end->get_prev_elem());

                for (size_type count = 0; count < (this->_size - 1); count++)
                {
                    last.get_elem()->delete_elem();
                    this->_end->add_before(last.get_elem());
                    last = next;
                    if (next.get_elem())
                        next--;
                }
                this->_first = new_first;
            }

    };


    /* Relational operators */
    template <class T, class Alloc>
    bool operator==(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return (false);
        typename List<T>::const_iterator lhs_it(lhs.begin());
        typename List<T>::const_iterator rhs_it(rhs.begin());
        typename List<T>::const_iterator end(lhs.end());
        while (lhs_it != end)
        {
            if (*lhs_it != *rhs_it)
                return (false);
            lhs_it++;
            rhs_it++;
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator!=(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return (lhs.size() < rhs.size());

        typename List<T>::const_iterator lhs_it(lhs.begin());
        typename List<T>::const_iterator rhs_it(rhs.begin());
        typename List<T>::const_iterator end(lhs.end());
        while (lhs_it != end)
        {
            if (*lhs_it != *rhs_it)
                return (*lhs_it < *rhs_it);
            lhs_it++;
            rhs_it++;
        }
        return (false);
    }

    template <class T, class Alloc>
    bool operator>(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        return (!(lhs < rhs || lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<=(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        return (!(lhs > rhs));
    }

    template <class T, class Alloc>
    bool operator>=(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
        return (!(lhs < rhs));
    }


    /* Swap */
    template <class T, class Alloc>
    void swap (List<T,Alloc>& x, List<T,Alloc>& y) {
        x.swap(y);
    }

}

#endif