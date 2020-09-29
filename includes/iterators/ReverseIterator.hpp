#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{
    template < typename Iter >
    class ReverseIterator : public Iter
    {
        public:
            /* Alias assignment */
            typedef typename Iter::value_type value_type;
            typedef typename Iter::pointer pointer;
            typedef typename Iter::const_pointer const_pointer;
            typedef typename Iter::reference reference;
            typedef typename Iter::const_reference const_reference;
            typedef typename Iter::difference_type difference_type;


            /* Constructor, Copy assignement and Destructor */
            ReverseIterator(void) : Iter() {}
            ReverseIterator(pointer elem) : Iter(elem) {}
            ReverseIterator(const ReverseIterator &other) : Iter(other._iter) {}
            //ReverseIterator(const Iter &other) : Iter(other._iter - 1) {}
            ReverseIterator &operator=(const ReverseIterator &other) {
                if (this != &other)
                    this->_iter = other._iter;
                return (*this);
            }
            ~ReverseIterator(void) {}


            /* Increment/Decrement operators */
            ReverseIterator operator++() {
                this->_iter--;
                return (*this);
            }

            ReverseIterator operator++(int) {
                ReverseIterator copy(*this);
                this->_iter--;
                return (copy);
            }

            ReverseIterator operator--() {
                this->_iter++;
                return (*this);
            }

            ReverseIterator operator--(int) {
                ReverseIterator copy(*this);
                this->_iter++;
                return (copy);
            }


            /* Arithmetic operators */
            ReverseIterator operator+=(int index) {
                this->_iter -= index;
                return (*this);
            }

            ReverseIterator operator+(int index) {
                ReverseIterator copy(*this);
                copy -= index;
                return (copy);
            }

            ReverseIterator operator-=(int index) {
                this->_iter += index;
                return (*this);
            }

            ReverseIterator operator-(int index) {
                ReverseIterator copy(*this);
                copy += index;
                return (copy);
            }
    };
}

#endif