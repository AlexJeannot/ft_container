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


            /* Constructor, Copy assignement and Destructor */
            ReverseIterator(void) : Iter() {}

            ReverseIterator(const ReverseIterator &other) : Iter(other._iter) {}

            ReverseIterator(const Iter &other) : Iter((other)) {
                this->Iter::operator--();
            }
            
            ReverseIterator &operator=(const ReverseIterator &other) {
                if (this != &other)
                    this->_iter = other._iter;
                return (*this);
            }

            virtual ~ReverseIterator(void) {}


            /* Accessors operators */
            reference operator[](int index) {
                return (this->Iter::operator[](-index));
            }

            const_reference operator[](int index) const {
                return (this->Iter::operator[](-index));
            }


            /* Increment/Decrement operators */
            ReverseIterator operator++() {
                this->Iter::operator--();
                return (*this);
            }

            ReverseIterator operator++(int) {
                ReverseIterator copy(*this);
                this->Iter::operator--();
                return (copy);
            }

            ReverseIterator operator--() {
                this->Iter::operator++();
                return (*this);
            }

            ReverseIterator operator--(int) {
                ReverseIterator copy(*this);
                this->Iter::operator++();
                return (copy);
            }


            /* Arithmetic operators */
            ReverseIterator operator+=(int index) {
                this->Iter::operator-=(index);
                return (*this);
            }

            ReverseIterator operator+(int index) {
                ReverseIterator copy(*this);
                copy.Iter::operator-=(index);
                return (copy);
            }

            ReverseIterator operator-=(int index) {
                this->Iter::operator+=(index);
                return (*this);
            }

            ReverseIterator operator-(int index) {
                ReverseIterator copy(*this);
                copy.Iter::operator+=(index);
                return (copy);
            }


            /* Comparison operators */
            bool operator<(const ReverseIterator &other) {
                return (this->Iter::operator>(other));
            }

            bool operator<=(const ReverseIterator &other) {
                return (this->Iter::operator>=(other));
            }

            bool operator>(const ReverseIterator &other) {
                return (this->Iter::operator<(other));
            }

            bool operator>=(const ReverseIterator &other) {
                return (this->Iter::operator<=(other));
            }

    };
}

#endif