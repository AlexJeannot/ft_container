#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include "../associative_containers/Tree.hpp"


namespace ft
{
    template < typename T, typename N>
    class MapIterator
    {
        public:
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef N node;
            typedef node* node_pointer;
            typedef node& node_reference;

        protected:
            node_pointer _iter;

        private:
            /* private member functions */
            void nextKey(void)
            {
                if (this->_iter->hasRight())
                {
                    this->_iter = this->_iter->getRight();
                    while (this->_iter->hasLeft())
                        this->_iter = this->_iter->getLeft();
                }
                else
                {
                    node_pointer prev_node = this->_iter;
                    this->_iter = this->_iter->getParent();
                    while (this->_iter->getLeft() != prev_node)
                    {
                        prev_node = this->_iter;
                        this->_iter = this->_iter->getParent();

                        
                    }
                }
            }

            void prevKey(void)
            {
                if (this->_iter->hasLeft())
                {
                    this->_iter = this->_iter->getLeft();
                    while (this->_iter->hasRight())
                        this->_iter = this->_iter->getRight();
                }
                else
                {
                    node_pointer tmp(this->_iter);
                    this->_iter = this->_iter->getParent();
                    while (this->_iter->getLeft() == tmp)
                    {
                        tmp = this->_iter;
                        this->_iter = this->_iter->getParent();
                    }
                }
            }

        public:
            /* Constructor, Copy assignement and Destructor */
            MapIterator(void) : _iter(nullptr) {}

            MapIterator(node_pointer node) : _iter(node) {}

            MapIterator(const MapIterator& other) : _iter(other._iter) {}

            MapIterator& operator=(const MapIterator& other)
            {
                if (this != &other)
                    this->_iter = other._iter;
                return (*this);
            }

            virtual ~MapIterator(void) {}


            /* Accessors operators */
            pointer operator->(void) {
                return (&(this->_iter->getPair()));
            }

            const_pointer operator->(void) const {
                return (&(this->_iter->getPair()));
            }

            node_pointer getNode(void) {
                return (this->_iter);
            }


            /* Increment/Decrement operators */
            MapIterator operator++() {
                this->nextKey();
                return (*this);
            }

            MapIterator operator++(int) {
                MapIterator copy(*this);
                this->nextKey();
                return (copy);
            }

            MapIterator operator--() {
                this->prevKey();
                return (*this);
            }

            MapIterator operator--(int) {
                MapIterator copy(*this);
                this->prevKey();
                return (copy);
            }


            /* Comparison operators */
            bool operator==(const MapIterator &other) {
                return (this->_iter == other._iter);
            }

            bool operator!=(const MapIterator &other) {
                return (this->_iter != other._iter);
            }
            
    };

}

#endif