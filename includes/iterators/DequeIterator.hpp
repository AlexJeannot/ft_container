#ifndef DEQUEITERATOR_HPP
# define DEQUEITERATOR_HPP

namespace ft
{
    template < typename T >
    class DequeIterator
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
            DequeIterator(void) : _iter(nullptr) {}
            DequeIterator(pointer elem) : _iter(elem) {}
            DequeIterator(const DequeIterator &other) : _iter(other._iter) {}
            DequeIterator &operator=(const DequeIterator &other)
            {
                if (this != &other)
                    this->_iter = other._iter;
                return (*this);
            }
            virtual ~DequeIterator(void) {}


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
            DequeIterator operator++() {
                this->_iter++;
                return (*this);
            }

            DequeIterator operator++(int) {
                DequeIterator<value_type> copy(*this);
                this->_iter++;
                return (copy);
            }

            DequeIterator operator--() {
                this->_iter--;
                return (*this);
            }

            DequeIterator operator--(int) {
                DequeIterator<value_type> copy(*this);
                this->_iter--;
                return (copy);
            }


            /* Arithmetic operators */
            DequeIterator operator+=(int index) {
                this->_iter += index;
                return (*this);
            }

            DequeIterator operator+(int index) {
                DequeIterator<value_type> copy(*this);
                copy._iter += index;
                return (copy);
            }

            DequeIterator operator-=(int index) {
                this->_iter -= index;
                return (*this);
            }

            DequeIterator operator-(int index) {
                DequeIterator<value_type> copy(*this);
                copy._iter -= index;
                return (copy);
            }

            difference_type operator-(const DequeIterator &other) {
                return (this->_iter - other._iter);
            }


            /* Comparison operators */
            bool operator==(const DequeIterator &other) {
                return (this->_iter == other._iter);
            }

            bool operator!=(const DequeIterator &other) {
                return (this->_iter != other._iter);
            }

            bool operator<(const DequeIterator &other) {
                return (this->_iter < other._iter);
            }

            bool operator<=(const DequeIterator &other) {
                return (this->_iter <= other._iter);
            }

            bool operator>(const DequeIterator &other) {
                return (this->_iter > other._iter);
            }

            bool operator>=(const DequeIterator &other) {
                return (this->_iter >= other._iter);
            }
    };
}
#endif