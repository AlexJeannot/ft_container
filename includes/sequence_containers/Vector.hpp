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
            void verify_available_size(size_type val)
            {
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

            void front_shift(iterator position, size_type diff)
            {
                for (iterator it(position + diff); it != this->end(); it++)
                {
                    this->_alloc.destroy(&(*position));
                    this->_alloc.construct(&(*position), *(it));
                    position++;
                }
                for (; diff > 0; diff--)
                {
                    this->_alloc.destroy(&(*position));
                    position++;
                }
            }

            void back_shift(iterator position, size_type diff)
            {
                if (this->_size > 0)
                {
                    size_type count(this->_size - 1);
                    for (; &(this->_container[count]) != &(*position) - 1; count--)
                    {
                        this->_alloc.construct(&this->_container[count] + diff, this->_container[count]);
                        this->_alloc.destroy(&(this->_container[count]));
                        if (&(this->_container[count]) == &(*this->begin()))
                            break;
                    }
                }
            }

        public:
            /* Constructors, Copy assignement and Destructor */
            Vector(const allocator_type& alloc = allocator_type())
            : _container(nullptr), _size(0), _capacity(0), _alloc(alloc)
            {

            }

            Vector(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type())
            : _container(nullptr), _size(0), _capacity(0), _alloc(alloc)
            {
                if (n > 0)
                    this->assign(n, val);
            }

            Vector(const Vector &other)
            : _container(nullptr), _size(0), _capacity(0), _alloc(other._alloc)
            {
                if (other._size > 0)
                    this->assign(other.begin(), other.end());
            }

            ~Vector()
            {
                this->clear();
                this->_alloc.deallocate(this->_container, this->_capacity);
            }

            Vector &operator=(const Vector &other)
            {
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

            const_iterator cbegin(void) const {
                return (const_iterator(this->_container));
            }

            const_iterator cend(void) const {
                return (const_iterator(this->_container + this->_size));
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
                return (std::min((size_type) std::numeric_limits<difference_type>::max(),
                        std::numeric_limits<size_type>::max() / sizeof(value_type)));
            }

            void resize(size_type n, value_type val = value_type())
            {
                size_type save_size(this->_size);
                if (n < this->_size)
                {
                    for (; n < save_size; n++)
                        this->pop_back();
                }
                else if (n > this->_size)
                {
                    verify_available_size(n);
                    for (; n > save_size; n--)
                        push_back(val);
                }
            }

            size_type capacity(void) const {
                return (this->_capacity);
            }

            bool empty() const {
                return (this->_size == 0);
            }

            void reserve(size_type n)
            {
                if ((this->_capacity + n) > this->max_size())
                    throw (std::length_error("Allocation inquiry exceeds maximum supported size"));
                else if (n > this->_capacity)
                {
                    if (this->_capacity > 0)
                    {
                        pointer tmp_ptr = _alloc.allocate(n);
                        for (size_type count = 0; count < this->_size; count++)
                            this->_alloc.construct(&(tmp_ptr[count]), this->_container[count]);
                        this->_alloc.deallocate(this->_container, this->_capacity);
                        this->_container = tmp_ptr;
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

            reference at(size_type n)
            {
                if (n >= this->_size)
                    throw (std::out_of_range("vector"));
                return (this->_container[n]);
            }

            const_reference at(size_type n) const
            {
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
            void assign(size_type n, const_reference val)
            {
                this->clear();
                if (n > this->_capacity)
                    this->reserve(n);
                for (size_type count = 0; count < n; count++)
                    this->_alloc.construct(&(this->_container[count]), val);
                this->_size = n;
            }

            template <typename InputIterator>
            void assign(InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                size_type assign_size(0);

                for (InputIterator copy(first); copy != last; copy++)
                    assign_size++;

                pointer tmp_ptr = this->_alloc.allocate(assign_size);
                for (size_type count = 0; count < assign_size; count++)
                    this->_alloc.construct(&(tmp_ptr[count]), *first++);
                this->clear();
                if (assign_size > this->_capacity)
                    this->reserve(assign_size);
                for (size_type count = 0; count < assign_size; count++)
                    this->_alloc.construct(&(this->_container[count]), tmp_ptr[count]);
                this->_alloc.deallocate(tmp_ptr, assign_size);
                this->_size = assign_size;
            }

            void push_back(const_reference val)
            {
                verify_available_size(1);
                this->_alloc.construct(this->_container + this->_size, val);
                this->_size++;
            }

            void pop_back(void) {
                this->_alloc.destroy(this->_container + (this->_size - 1));
                this->_size--;
            }

            iterator insert(iterator position, const_reference val)
            {
                verify_available_size(1);
                if (position != this->end())
                    back_shift(position, 1);
                this->_alloc.construct(&(*position), val);
                this->_size++;
                return (position);
            }

            void insert(iterator position, size_type n, const_reference val)
            {
                if (n > 0)
                {
                    verify_available_size(n);
                    if (position != this->end())
                        back_shift(position, n);
                    for (size_type count = 0; count < n; count++)
                    {
                        this->_alloc.construct(&(*position), val);
                        position++;
                    }
                    this->_size += n;
                }
            }

            template < typename InputIterator >
            void insert(iterator position, InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                size_type insert_size(0);

                for (InputIterator copy(first); copy != last; copy++)
                    insert_size++;
                if (insert_size > 0)
                {
                    pointer tmp_ptr = this->_alloc.allocate(insert_size);
                    for (size_type count = 0; count < insert_size; count++)
                        this->_alloc.construct(&(tmp_ptr[count]), *first++);
                    verify_available_size(insert_size);
                    if (position != this->end())
                        back_shift(position, insert_size);
                    for (size_type count = 0; count < insert_size; count++)
                    {
                        this->_alloc.construct(&(*position), tmp_ptr[count]);
                        position++;
                    }
                    this->_alloc.deallocate(tmp_ptr, insert_size);
                    this->_size += insert_size;
                }
            }

            iterator erase(iterator position)
            {
                if (position == (this->end() - 1))
                    this->_alloc.destroy(&(*position));
                else
                    front_shift(position, 1);
                this->_size--;
                return (position);
            }

            iterator erase(iterator first, iterator last)
            {
                size_type erase_size(0);

                for (iterator copy(first); copy != last; copy++)
                    erase_size++;
                front_shift(first, erase_size);
                this->_size -= erase_size;
                return (last);
            }

            void clear(void)
            {
                for (iterator it(this->begin()); it != this->end(); it++)
                    this->_alloc.destroy(&(*it));
                this->_size = 0;
            }


            /* Swap */
            void swap(Vector& other)
            {
                pointer tmp_container = this->_container;
                size_type tmp_size = this->_size;
                size_type tmp_capacity = this->_capacity;
                allocator_type tmp_alloc = this->_alloc;

                this->_container = other._container;
                this->_size = other._size;
                this->_capacity = other._capacity;
                this->_alloc = other._alloc;

                other._container = tmp_container;
                other._size = tmp_size;
                other._capacity = tmp_capacity;
                other._alloc = tmp_alloc;
            }

    };


    /* Relational operators */
    template <class T, class Alloc>
    bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t count = 0; count < lhs.size(); count++)
        {
            if (lhs[count] != rhs[count])
                return (false);
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return (lhs.size() < rhs.size());
        
        for (size_t count = 0; count < lhs.size(); count++)
        {
            if (lhs[count] != rhs[count])
                return (lhs[count] < rhs[count]);
        }
        return (false);
    }

    template <class T, class Alloc>
    bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        return (!(lhs < rhs || lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        return (!(lhs > rhs));
    }

    template <class T, class Alloc>
    bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
        return (!(lhs < rhs));
    }


    /* Swap */
    template <class T, class Alloc>
    void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y) {
        x.swap(y);
    }

}

#endif