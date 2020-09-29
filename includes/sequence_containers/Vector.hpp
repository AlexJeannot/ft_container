#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cmath>
# include <iostream>
# include <exception>

# include "../iterators/VectorIterator.hpp"
# include "../iterators/ReverseIterator.hpp"

namespace ft
{
    template < typename T, typename Alloc = std::allocator<T> >
    class Vector
    {
        public:
            /* Alias assignement */
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef Alloc allocator_type;
            typedef VectorIterator<value_type> iterator;
            typedef VectorIterator<const value_type> const_iterator;
            typedef ReverseIterator<iterator> reverse_iterator;
            typedef ReverseIterator<const_iterator> const_reverse_iterator;

        private:
            /* private member variables */
            pointer _container;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;

            /* private member function */
            void verify_available_size(size_type val) {
                if (this->_capacity < (this->_size + val))
                {
                    if (this->_size == 0 && val == 1)
                        this->reserve(1);
                    else if ((this->_size * 2) > val)
                        this->reserve((this->_size * 2));
                    else
                        this->reserve(val);
                }
            }

            void front_shift(iterator position, size_type diff) {
                for (iterator it(position + diff); it != this->end(); it++)
                {
                    _alloc.destroy(&(*position));
                    _alloc.construct(&(*position), *(it));
                    position++;
                }
                for (; diff > 0; diff--)
                {
                    _alloc.destroy(&(*position));
                    position++;
                }
            }

            void back_shift(iterator position, size_type diff) {
                if (this->_size > 0)
                {
                    int count(this->_size - 1);
                    for (; &(this->_container[count]) != &(*position) - 1; count--)
                    {
                        _alloc.construct(&this->_container[count] + diff, this->_container[count]);
                        _alloc.destroy(&(this->_container[count]));
                        if (&(this->_container[count]) == &(*this->begin()))
                            break;
                    }
                }
            }

        public:
            /* Constructor, Copy assignement and Destructor */
            Vector(const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _container(nullptr), _size(0), _capacity(0) {

            }

            Vector(value_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type())
            : _alloc(allocator_type()), _container(nullptr), _size(0), _capacity(0) {
                if (n > 0)
                    this->assign(n, val);
            }

            Vector(const Vector &other)
            : _alloc(other._alloc), _container(nullptr), _size(0), _capacity(0) {
                if (other._size > 0)
                    this->assign(other.begin(), other.end());
            }

            ~Vector() {
                this->clear();
                _alloc.deallocate(this->_container, this->_capacity);
            }

            Vector &operator=(const Vector &other) {
                if (this != &other)
                    this->assign(other.begin(), other.end());
                return (*this);
            }


            /* Iterator member functions */
            iterator begin(void) {
                return (iterator(this->_container));
            }

            const_iterator begin(void) const {
                return (const_iterator(this->_container));
            }

            iterator end(void) {
                return (iterator(this->_container + this->_size));
            }

            const_iterator end(void) const {
                return (const_iterator(this->_container + this->_size));
            }

            reverse_iterator rbegin(void) {
                return (reverse_iterator(this->_container + (this->_size - 1)));
            }

            const_reverse_iterator rbegin(void) const {
                return (const_reverse_iterator(this->_container + (this->_size - 1)));
            }

            reverse_iterator rend(void) {
                return (reverse_iterator(this->_container - 1));
            }

            const_reverse_iterator rend(void) const {
                return (const_reverse_iterator(this->_container - 1));
            }

            const_iterator cbegin(void) const {
                return (const_iterator(this->_container));
            }

            const_iterator cend(void) const {
                return (const_iterator(this->_container + this->_size));
            }

            const_reverse_iterator crbegin(void) const {
                return (const_reverse_iterator(this->_container + (this->_size - 1)));
            }

            const_reverse_iterator crend(void) const {
                return (const_reverse_iterator(this->_container - 1));
            }


            /* Capacity member functions */
            size_type size(void) const {
                return this->_size;
            }

            size_type max_size(void) const {
                size_type result = (std::pow(2, (sizeof(size_type) * 8)) / sizeof(value_type));
                return ((PTRDIFF_MAX < (result - 1)) ? PTRDIFF_MAX : (result - 1));
            }

            void resize(size_type n, value_type val = value_type()) {
                
                if (n < this->_size)
                {
                    size_type save_size(this->_size);
                    for (; n < save_size; n++)
                        this->pop_back();
                }
                else if (n > this->_size)
                    this->insert(this->end(), n, val);
            }

            size_type capacity(void) const {
                return (this->_capacity);
            }

            bool empty() const {
                return (this->_size == 0);
            }

            void reserve(size_type n) {
                if ((this->_capacity + n) > this->max_size())
                    throw (std::length_error("Allocation inquiry exceeds maximum supported size"));
                else if (n > this->_capacity)
                {
                    if (this->_size > 0 && this->_capacity > 0)
                    {
                        pointer tmp_ptr = _alloc.allocate(n);
                        for (size_type count = 0; count < this->_size; count++)
                            tmp_ptr[count] = this->_container[count];
                        _alloc.deallocate(this->_container, this->_capacity);
                        this->_container = _alloc.allocate(n);
                        for (size_type count = 0; count < this->_size; count++)
                            this->_container[count] = tmp_ptr[count];
                        _alloc.deallocate(tmp_ptr, n);
                    }
                    else
                        this->_container =_alloc.allocate(n);
                    this->_capacity = n;
                }
            }

            /* Element access member functions */
            reference operator[](size_type n) {
                return (this->_container[n]);
            }

            const_reference operator[](size_type n) const {
                return (this->_container[n]);
            }

            reference at(size_type n) {
                if (n >= this->_size)
                    throw (std::out_of_range("vector"));
                return (this->_container[n]);
            }

            const_reference at(size_type n) const {
                if (n >= this->_size)
                    throw (std::out_of_range("vector"));
                return (this->_container[n]);
            }

            reference front(void) {
                return (this->_container[0]);
            }

            const_reference front(void) const {
                return (this->_container[0]);
            }

            reference back(void) {
                return (this->_container[(this->_size - 1)]);
            }

            const_reference back(void) const {
                return (this->_container[(this->_size - 1)]);
            }


            /* Modifier member functions */

            void assign(size_type n, const_reference val) {
                this->clear();
                if (n > this->_capacity)
                    this->reserve(n);
                for (size_type count = 0; count < n; count++)
                    _alloc.construct(&(this->_container[count]), val);
                this->_size = n;
            }

            template <typename InputIterator>
            void assign(InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) {
                size_type assign_size(0);

                for (InputIterator copy(first); copy != last; copy++)
                    assign_size++;
                Vector<value_type> tmp_vec;
                for (InputIterator copy(first); copy != last; copy++)
                    tmp_vec.push_back(*copy);
                this->clear();
                if (assign_size > this->_capacity)
                    this->reserve(assign_size);
                for (size_type count = 0; count < assign_size; count++)
                    _alloc.construct(&(this->_container[count]), tmp_vec._container[count]);
                this->_size = assign_size;
            }

            void push_back(const_reference val) {
                verify_available_size(1);
                _alloc.construct(this->_container + this->_size, val);
                this->_size++;
            }

            void pop_back(void) {
                _alloc.destroy(this->_container + (this->_size - 1));
                this->_size--;
            }

            iterator insert(iterator position, const_reference val) {
                verify_available_size(1);
                back_shift(position, 1);
                _alloc.construct(&(*position), val);
                this->_size++;
                return (position);
            }

            void insert(iterator position, size_type n, const_reference val) {
                verify_available_size(n);
                back_shift(position, n);
                for (size_type count = 0; count < n; count++)
                {
                    _alloc.construct(&(*position), val);
                    position++;
                }
                this->_size += n;
            }

            template < typename InputIterator >
            void insert(iterator position, InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) {
                size_type insert_size(0);

                for (InputIterator copy(first); copy != last; copy++)
                    insert_size++;
                verify_available_size(insert_size);
                Vector<value_type> tmp(insert_size);
                for (InputIterator copy(first); copy != last; copy++)
                    tmp.push_back(*copy);
                back_shift(position, insert_size);
                for (iterator start = tmp.begin(); start != tmp.end(); start++)
                {
                    _alloc.construct(&(*position), *start);
                    position++;
                }
                this->_size += insert_size;
            }

            iterator erase(iterator position) {
                if (position == (this->end() - 1))
                    _alloc.destroy(&(*position));
                else
                    front_shift(position, 1);
                this->_size--;
                return (position);
            }

            iterator erase(iterator first, iterator last) {
                size_type erase_size(0);

                for (iterator copy(first); copy != last; copy++)
                    erase_size++;
                front_shift(first, erase_size);
                this->_size -= erase_size;
                return (last);
            }

            void clear(void) {
                for (iterator it(this->begin()); it != this->end(); it++)
                    _alloc.destroy(&(*it));
                this->_size = 0;
            }

    };

}

#endif