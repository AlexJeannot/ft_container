#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include "../associative_containers/Tree.hpp"


namespace ft
{
    template < typename Key, typename T>
    class MapIterator
    {
        public:
            /* Alias assignement */
            typedef Key key_type;
            typedef key_type* key_pointer;
            typedef const key_type* const_key_pointer;
            typedef key_type& key_reference;
            typedef const key_type& const_key_reference;
            typedef T mapped_type;
            typedef mapped_type* mapped_pointer;
            typedef const mapped_type* const_mapped_pointer;
            typedef mapped_type& mapped_reference;
            typedef const mapped_type& const_mapped_reference;
            typedef pair<const key_type, mapped_type> value_type;
            typedef value_type* value_pointer;
            typedef const value_type* const_value_pointer;
            typedef value_type& value_reference;
            typedef const value_type& const_value_reference;
            typedef TreeNode<key_type, mapped_type> node;
            typedef node* node_pointer;
            typedef const node* const_node_pointer;
            typedef node& node_reference;
            typedef const node& const_node_reference;
            typedef Tree<Key, T> Tree;
            typedef Tree* tree_pointer;
            typedef const Tree* const_pointer;
            typedef Tree& reference;
            typedef const Tree& const_reference;

        private:
            node_pointer _iter;

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
                    this->_iter = this->_iter->getParent();
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
            value_pointer operator->(void) {
                return (&(this->_iter->getPair()));
            }

            const_value_pointer operator->(void) const {
                return (&(this->_iter->getPair()));
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