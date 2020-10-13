#ifndef MAP_HPP
# define MAP_HPP

# include "Tree.hpp"
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
            typedef MapIterator<value_type, node> iterator;
            typedef MapIterator<const value_type, const node> const_iterator;
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
            : _tree(), _cmp(cmp), _size(0), _alloc(alloc)
            {

            }

            Map(const Map& other)
            : _tree(other._tree), _cmp(other._cmp), _size(other._size), _alloc(other._alloc) 
            {

            }

            ~Map()
            {
                if (this->_size > 0)
                    this->clear();
                this->_tree.clearBorders();
            }

            Map& operator=(const Map& other)
            {
                if (this != &other)
                {
                    this->_tree = other._tree;
                    this->_cmp = other._cmp;
                    this->_size = other._size;
                    this->_alloc = other._alloc;
                }
                return (*this);
            }


            /* value_compare class */
            class value_compare
            {
                friend class map;

                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}

                public:
                    bool operator() (const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };


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
            
            size_type max_size(void) const {
                return (std::numeric_limits<size_type>::max() / (sizeof(node) + sizeof(value_pointer)));
            }


            /* Element access member functions */
            mapped_reference operator[] (const_key_reference k)
            {
                if (this->_tree.keySearch(k))
                    return (this->_tree.keySearch(k)->getValue());
                else
                {
                    this->insert(make_pair(k, mapped_type()));
                    return (this->_tree.keySearch(k)->getValue());
                }
            }


            /* Modifiers member functions */
            pair<iterator, bool> insert(const_value_reference val)
            {
                node_pointer node(nullptr);
                if ((node = this->_tree.keySearch(val.first)))
                    return (make_pair<iterator, bool>(iterator(node), false));
                node = this->_tree.createNode(val);
                this->_size++;
                return (make_pair<iterator, bool>(iterator(node), true));
            }

            iterator insert(iterator position, const_value_reference val)
            {
                node_pointer node(nullptr);
                if ((node = this->_tree.keySearch(val.first, position.getNode())))
                    return (iterator(node));
                node = this->_tree.createNode(val);
                this->_size++;
                return (iterator(node));
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last,
            typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                for(; first != last; first++)
                    this->insert(make_pair(first->first, first->second));
            }


            void erase(iterator position)
            {
                if (this->_size > 0)
                {
                    this->_tree.deleteNode(position.getNode());
                    this->_size--;
                }
            }

            size_type erase(const_key_reference k)
            {
                if (this->_size > 0)
                {
                    if (this->_tree.keySearch(k))
                    {
                        this->_tree.deleteNode(this->_tree.keySearch(k));
                        this->_size--;
                        return (1);
                    }
                }
                return (0);
            }
            
            void erase(iterator first, iterator last)
            {
                iterator next(first);

                if (this->_size > 0)
                {
                    for(next++; next != last; next++)
                    {
                        this->erase(first);
                        first = next;
                    }
                    this->erase(first);

                }
            }

            void swap(Map& other)
            {
                Tree tmp_tree;
                tmp_tree.clearBorders();
                tmp_tree = this->_tree;
                key_compare tmp_cmp = this->_cmp;
                size_type tmp_size = this->_size;
                allocator_type tmp_alloc = this->_alloc;

                this->_tree = other._tree;
                this->_cmp = other._cmp;
                this->_size = other._size;
                this->_alloc = other._alloc;

                other._tree = tmp_tree;
                other._cmp = tmp_cmp;
                other._size = tmp_size;
                other._alloc = tmp_alloc;
            }

            void clear() {
                erase(this->begin(), this->end());
            }


            /* Observer member functions */
            key_compare key_comp() const {
                return (this->_cmp);
            }

            value_compare value_comp() const {
                return(value_compare(this->_cmp));
            }


            /* Operation member functions */
            iterator find(const_key_reference k)
            {
                if (this->_tree.keySearch(k))
                    return (iterator(this->_tree.keySearch(k)));
                return (this->end());
            }

            const_iterator find(const_key_reference k) const
            {
                if (this->_tree.keySearch(k))
                    return (const_iterator(this->_tree.keySearch(k)));
                return (this->end());
            }

            size_type count(const_key_reference k) const
            {
                if (this->_tree.keySearch(k))
                    return (1);
                return (0);
            }

            iterator lower_bound(const_key_reference k)
            {
                if (this->_tree.keySearch(k))
                    return (iterator(this->_tree.keySearch(k)));
                else
                    return(iterator(this->_tree.searchNextKey(k)));
            }

            const_iterator lower_bound(const_key_reference k) const
            {
                if (this->_tree.keySearch(k))
                    return (const_iterator(this->_tree.keySearch(k)));
                else
                    return(const_iterator(this->_tree.searchNextKey(k)));
            }

            iterator upper_bound(const_key_reference k)
            {
                if (this->_tree.keySearch(k))
                    return (++iterator(this->_tree.keySearch(k)));
                else
                    return(iterator(this->_tree.searchNextKey(k)));
            }

            const_iterator upper_bound(const_key_reference k) const
            {
                if (this->_tree.keySearch(k))
                    return (++const_iterator(this->_tree.keySearch(k)));
                else
                    return(const_iterator(this->_tree.searchNextKey(k)));
            }

            pair<iterator, iterator> equal_range(const_key_reference k)
            {
                if (this->_tree.keySearch(k))
                    return (make_pair(iterator(this->_tree.keySearch(k)),
                    (++iterator(this->_tree.keySearch(k)))));
                else
                    return (make_pair(iterator(this->_tree.searchNextKey(k)),
                    (iterator(this->_tree.searchNextKey(k)))));
            }

            pair<const iterator, const iterator> equal_range(const_key_reference k) const
            {
                if (this->_tree.keySearch(k))
                    return (make_pair(const_iterator(this->_tree.keySearch(k)),
                    (const_iterator(this->_tree.keySearch(k))->nextKey())));
                else
                    return (make_pair(const_iterator(this->_tree.searchNextKey(k)),
                    (const_iterator(this->_tree.searchNextKey(k))->nextKey())));
            }
    };


    /* Relational operators */
    template <class Key, class V>
    bool operator==(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        if (lhs.size() != rhs.size())
            return (false);
        typename Map<Key, V>::const_iterator lhs_it(lhs.begin());
        typename Map<Key, V>::const_iterator rhs_it(rhs.begin());
        typename Map<Key, V>::const_iterator end(lhs.end());
        while (lhs_it != end)
        {
            if (lhs_it->first != rhs_it->first
            || lhs_it->second != rhs_it->second)
                return (false);
            lhs_it++;
            rhs_it++;
        }
        return (true);
    }

    template <class Key, class V>
    bool operator!=(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        return (!(lhs == rhs));
    }

    template <class Key, class V>
    bool operator<(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        if (lhs.size() != rhs.size())
            return (lhs.size() < rhs.size());

        typename Map<Key, V>::const_iterator lhs_it(lhs.begin());
        typename Map<Key, V>::const_iterator rhs_it(rhs.begin());
        typename Map<Key, V>::const_iterator end(lhs.end());
        while (lhs_it != end)
        {
            if (lhs_it->first != rhs_it->first)
                return (lhs_it->first < rhs_it->first);
            if (lhs_it->second != rhs_it->second)
                return (lhs_it->second < rhs_it->second);
            lhs_it++;
            rhs_it++;
        }
        return (false);
    }

    template <class Key, class V>
    bool operator>(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        return (!(lhs < rhs || lhs == rhs));
    }

    template <class Key, class V>
    bool operator<=(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        return (!(lhs > rhs));
    }

    template <class Key, class V>
    bool operator>=(const Map<Key, V>& lhs, const Map<Key, V>& rhs) {
        return (!(lhs < rhs));
    }


    /* Swap */
    template <class Key, class V>
    void swap(Map<Key, V>& x, Map<Key, V>& y) {
        x.swap(y);
    }
}

#endif