#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

namespace ft
{
    template < typename T >
    class VectorIterator
    {
        public:
            /* Alias assignment */
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef std::ptrdiff_t difference_type;

        protected:
            pointer _iter;

        public:
            /* Constructor, Copy assignement and Destructor */
            VectorIterator(void) : _iter(nullptr) {}
            VectorIterator(pointer elem) : _iter(elem) {}
            VectorIterator(const VectorIterator &other) : _iter(other._iter) {}
            VectorIterator &operator=(const VectorIterator &other) {
                if (this != &other)
                    this->_iter = other._iter;
                return (*this);
            }
            virtual ~VectorIterator(void) {}


            /* Accessors operators */
            reference operator*(void) {
                return (*this->_iter);
            }

            const_reference operator*(void) const {
                return (*this->_iter);
            }

            pointer operator->(void) {
                return (this->_iter);
            }

            const_pointer operator->(void) const {
                return (this->_iter);
            }

            reference operator[](int index) {
                return (*(this->_iter + index));
            }

            const_reference operator[](int index) const {
                return (*(this->_iter + index));
            }


            /* Increment/Decrement operators */
            VectorIterator operator++() {
                this->_iter++;
                return (*this);
            }

            VectorIterator operator++(int) {
                VectorIterator<value_type> copy(*this);
                this->_iter++;
                return (copy);
            }

            VectorIterator operator--() {
                this->_iter--;
                return (*this);
            }

            VectorIterator operator--(int) {
                VectorIterator<value_type> copy(*this);
                this->_iter--;
                return (copy);
            }


            /* Arithmetic operators */
            VectorIterator operator+=(int index) {
                this->_iter += index;
                return (*this);
            }

            VectorIterator operator+(int index) {
                VectorIterator<value_type> copy(*this);
                copy._iter += index;
                return (copy);
            }

            VectorIterator operator-=(int index) {
                this->_iter -= index;
                return (*this);
            }

            VectorIterator operator-(int index) {
                VectorIterator<value_type> copy(*this);
                copy._iter -= index;
                return (copy);
            }

            difference_type operator-(const VectorIterator &other) {
                return (this->_iter - other._iter);
            }


            /* Comparison operators */
            bool operator==(const VectorIterator &other) {
                return (this->_iter == other._iter);
            }

            bool operator!=(const VectorIterator &other) {
                return (this->_iter != other._iter);
            }

            bool operator<(const VectorIterator &other) {
                return (this->_iter < other._iter);
            }

            bool operator<=(const VectorIterator &other) {
                return (this->_iter <= other._iter);
            }

            bool operator>(const VectorIterator &other) {
                return (this->_iter > other._iter);
            }

            bool operator>=(const VectorIterator &other) {
                return (this->_iter >= other._iter);
            }
    };
}
#endif