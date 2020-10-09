#ifndef MAP_HPP
# define MAP_HPP

# include "Tree.hpp"
# include "../iterators/MapIterator.hpp"
# include "../iterators/ReverseIterator.hpp"
# include <memory>

namespace ft
{
    template <  typename Key, typename T,
                typename Compare = less<Key>, typename Alloc = std::allocator< pair< const Key, T> > >
    class Map
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
            typedef Tree<Key, T, Compare > Tree;
            typedef Tree* tree_pointer;
            typedef const Tree* const_pointer;
            typedef Tree& reference;
            typedef const Tree& const_reference;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef Compare key_compare;
            typedef MapIterator<Key, T> iterator;
            typedef MapIterator<const Key, const T> const_iterator;
            typedef ReverseIterator<iterator> reverse_iterator;
            typedef ReverseIterator<const_iterator> const_reverse_iterator;

        private:
            Tree _tree;
            key_compare _cmp;
            size_type _size;
            allocator_type _alloc;

        public:
            /* Constructors, Copy assignement and Destructor */
            Map(const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
            : _tree(), _cmp(cmp), _alloc(alloc)
            {

            }

            Map(const Map& other)
            : _tree(other._tree), _cmp(other._cmp), _alloc(other._alloc) 
            {

            }

            ~Map() {}

            Map& operator=(const Map& other)
            {
                if (this != &other)
                {
                    this->_tree = other._tree;
                    this->_cmp = other._cmp;
                    this->_alloc = other._alloc;
                }
                return (*this);
            }


            /* Iterator member functions */
            iterator begin(void) {
                return (iterator(this->_tree.begin()));
            }

            const_iterator begin(void) const {
                return (const_iterator(this->_tree.begin()));
            }

            iterator end(void) {
                return (iterator(this->_tree.end()));
            }

            const_iterator end(void) const {
                return (const_iterator(this->_tree.end()));
            }

            const_iterator cbegin(void) const {
                return (const_iterator(this->_tree.begin()));
            }

            const_iterator cend(void) const {
                return (const_iterator(this->_tree.end()));
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
            bool empty(void) {
                return (this->_size == 0);
            }

            size_type size(void) const {
                return (this->_size);
            }
            
            //size_type max_size(void) const
            //{
            //    return (std::numeric_limits<size_type>::max() / sizeof(list_elem));
            //}


            /* Element access member functions */

            /* Modifiers member functions */
            /*pair<iterator, bool> insert(const_value_reference val)
            {

            }*/
            

    };
}

#endif