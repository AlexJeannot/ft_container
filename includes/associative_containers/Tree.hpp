#ifndef TREE_HPP
# define TREE_HPP

# include "../iterators/MapIterator.hpp"
# include "../iterators/ReverseIterator.hpp"

namespace ft
{
    template < typename T1, typename T2 >
    struct pair
    {
        /* Alias assignement */
        typedef T1 first_type;
        typedef T2 second_type;

        /* Member variables */
        first_type first;
        second_type second;

        /* Constructors and Copy assignement */
        pair() : first(first_type()), second(second_type()) {}

        pair(const first_type& first, const second_type& second)
        : first(first), second(second)
        {

        }

        template < typename V1, typename V2 >
        pair(const pair<V1, V2>& other)
        : first(other.first), second(other.second)
        {

        }
        
        template < typename V1, typename V2 >
        pair& operator=(const pair<V1, V2>& other)
        {
            if (this != &other)
            {
                this->first = other.first;
                this->second = other.second;
            }
            return (*this);
        }

    };

    template < typename T1, typename T2 >
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return(pair<T1, T2>(x, y));
    }

    template < typename T >
    struct less : public std::binary_function<T, T, bool>
    {
        bool operator()(const T& x, const T& y) const {
            return (x < y);
        }
    };

    template < typename Key, typename T>
    class TreeNode
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
            typedef TreeNode* node_pointer;
            typedef const TreeNode* const_node_pointer;
            typedef TreeNode& node_reference;
            typedef const TreeNode& const_node_reference;
            typedef pair< const Key, T> value_type;
            typedef value_type* value_pointer;
            typedef const value_type* const_value_pointer;
            typedef value_type& value_reference;
            typedef const value_type& const_value_reference;

        private:
            value_type _pair;
            node_pointer _parent;
            node_pointer _right;
            node_pointer _left;

        public:
            /* Constructors, Copy assignement and Destructor */
            TreeNode(void)
            : _pair(value_type()), _parent(nullptr), _right(nullptr), _left(nullptr)
            {

            }

            TreeNode(const_value_reference pair)
            : _pair(pair), _parent(nullptr), _right(nullptr), _left(nullptr)
            {

            }

            TreeNode(const_node_reference other)
            : _pair(other._pair), _parent(other._parent),
            _right(other._right), _left(other._left)
            {

            }

            ~TreeNode() {}

            node_reference operator=(const_node_reference other)
            {
                if (this != &other)
                {
                    this->_pair = other._pair;
                    this->_parent = other._parent;
                    this->_right = other._right;
                    this->_left = other._left;
                }
                return (*this);
            }


            /* Getter member functions */
            value_reference getPair(void) {
                return (this->_pair);
            }

            const_value_reference getPair(void) const {
                return (this->_pair);
            }

            const_key_reference getKey(void) const {
                return (this->_pair.first);
            }

            mapped_reference getValue(void) {
                return (this->_pair.second);
            }

            const_mapped_reference getValue(void) const {
                return (this->_pair.second);
            }

            node_pointer getLeft(void) {
                return(this->_left);
            }

            node_pointer getRight(void) {
                return(this->_right);
            }

            const_node_pointer getLeft(void) const {
                return(this->_left);
            }

            const_node_pointer getRight(void) const {
                return(this->_right);
            }

            node_pointer getParent(void) {
                return(this->_parent);
            }

            const_node_pointer getParent(void) const {
                return(this->_parent);
            }


            /* Verification member function */
            bool hasParent(void) const {
                return(this->_parent);
            }

            bool hasLeft(node_pointer begin = nullptr) const {
                return(this->_left && this->_left != begin);
            }

            bool hasRight(node_pointer end = nullptr) const {
                return(this->_right && this->_right != end);
            }

            bool hasNoChildNode(node_pointer begin, node_pointer end) const {
                return (!(this->hasLeft(begin)) && !(this->hasRight(end)));
            }

            bool hasOneChildNode(node_pointer begin, node_pointer end) const {
                return ((this->hasLeft(begin) && !(this->hasRight(end)))
                || (!(this->hasLeft(begin)) && this->hasRight(end)));
            }


            /* Setter member functions */
            void setLeft(node_pointer node) {
                this->_left = node;
            }

            void setRight(node_pointer node) {
                this->_right = node;
            }

            void setParent(node_pointer node) {
                this->_parent = node;
            }

            node_reference operator=(const_mapped_reference value)
            {
                this->_pair.second = value;
                return(*this);
            }

    };

    template <  typename Key, typename T,
                typename Compare = less<Key>, typename Alloc = std::allocator< TreeNode<Key, T> > >
    class Tree
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
            typedef TreeNode<key_type, mapped_type> node;
            typedef node* node_pointer;
            typedef const node* const_node_pointer;
            typedef node& node_reference;
            typedef const node& const_node_reference;
            typedef Tree* pointer;
            typedef const Tree* const_pointer;
            typedef Tree& reference;
            typedef const Tree& const_reference;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef Compare key_compare;
            typedef pair< const Key, T> value_type;
            typedef value_type* value_pointer;
            typedef const value_type* const_value_pointer;
            typedef value_type& value_reference;
            typedef const value_type& const_value_reference;
            typedef MapIterator<value_type, node> iterator;
            typedef MapIterator<const value_type, const node> const_iterator;
            typedef ReverseIterator<iterator> reverse_iterator;
            typedef ReverseIterator<const_iterator> const_reverse_iterator;

        private:
            node_pointer _begin;
            node_pointer _root;
            node_pointer _end;
            key_compare _cmp;
            allocator_type _alloc;


        public:
            /* Constructors, Copy assignement and Destructor */
            Tree(const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
            : _begin(nullptr), _root(nullptr),
            _end(nullptr), _cmp(cmp), _alloc(alloc)
            {
                setupBorder();
            }

            Tree(const Tree& other)
            : _begin(nullptr), _root(nullptr),
            _end(nullptr), _cmp(other._cmp), _alloc(other._alloc)
            {
                setupBorder();
                iterator first(other.begin());
                iterator end(other.end());
                for (; first != end; first++)
                    createNode(first.getNode()->getPair());
            }

            ~Tree() {}

            Tree& operator=(const_reference other)
            {
                if (this != &other)
                {
                    this->_begin = other._begin;
                    this->_root = other._root;
                    this->_end = other._end;
                    this->_cmp = other._cmp;
                    this->_alloc = other._alloc;
                }
                return (*this);
            }


            /* member functions */

            /* Get begin and end for iterator */
            node_pointer begin(void) const
            {
                if (this->_root)
                    return (this->_begin->getParent());
                else
                    return (this->_begin);
            }

            node_pointer end(void) const {
                return (this->_end);
            }


            /* Borders management */
            void setupBorder(void)
            {
                this->_begin = this->_alloc.allocate(1);
                this->_alloc.construct(this->_begin, value_type());
                this->_end = this->_alloc.allocate(1);
                this->_alloc.construct(this->_end, value_type());
            }

            void removeBorders(void)
            {
                if (this->_begin->hasParent())
                    this->_begin->getParent()->setLeft(nullptr);
                this->_begin->setParent(nullptr);
                if (this->_end->hasParent())
                    this->_end->getParent()->setRight(nullptr);
                this->_end->setParent(nullptr);
            }

            void addBorders(void)
            {
                if (this->_root)
                {
                    this->_begin->setParent(this->getBranchMin(this->_root));
                    this->getBranchMin(this->_root)->setLeft(this->_begin);
                    this->_end->setParent(this->getBranchMax(this->_root));
                    this->getBranchMax(this->_root)->setRight(this->_end);
                }
            }

            void clearBorders(void)
            {
                this->_alloc.destroy(this->_begin);
                this->_alloc.deallocate(this->_begin, 1);
                this->_alloc.destroy(this->_end);
                this->_alloc.deallocate(this->_end, 1);
            }


            /* Node creation */
            node_pointer createNode(const_value_reference pair)
            {
                node_pointer new_node(nullptr);

                if (!(this->keySearch(pair.first)))
                {
                    removeBorders();
                    new_node = this->_alloc.allocate(1);
                    this->_alloc.construct(new_node, pair);
                    if (this->_root == nullptr)
                        this->_root = new_node;
                    else
                        addNode(new_node, this->_root);
                    addBorders();
                    return (new_node);
                }
                return (this->keySearch(pair.first));
            }

            void addNode(node_pointer new_node, node_pointer node)
            {
                if (this->_cmp(new_node->getKey(), node->getKey()))
                {
                    if (node->hasLeft(this->_begin))
                        return(addNode(new_node, node->getLeft()));
                    else
                        node->setLeft(new_node);
                }
                else
                {
                    if (node->hasRight(this->_end))
                        return(addNode(new_node, node->getRight()));
                    else
                        node->setRight(new_node);
                }
                new_node->setParent(node);
            }


            /* Node deletion */
            void deleteNode(node_pointer node)
            {
                if (!node)
                    return ;
                removeBorders();
                if (node == this->_root)
                    this->deleteRootNode();
                else
                {
                    if (node->hasNoChildNode(this->_begin, this->_end))
                        this->setParentNode(node);
                    else if (node->hasOneChildNode(this->_begin, this->_end))
                    {
                        if (node->hasLeft(this->_begin))
                            this->setParentNode(node, node->getLeft());
                        else
                            this->setParentNode(node, node->getRight());
                    }
                    else
                    {
                        setParentNode(node, node->getRight());
                        this->getBranchMin(node->getRight())->setLeft(node->getLeft());
                        node->getLeft()->setParent(getBranchMin(node->getRight()));
                    }
                }
                addBorders();
                this->_alloc.destroy(node);
                this->_alloc.deallocate(node, 1);
            }

            void setParentNode(node_pointer node, node_pointer new_child = nullptr)
            {
                if (node->getParent()->getLeft() == node)
                    node->getParent()->setLeft(new_child);
                else if (node->getParent()->getRight() == node)
                    node->getParent()->setRight(new_child);
                if (new_child)
                    new_child->setParent(node->getParent());
            }

            void deleteRootNode(void)
            {
                if (this->_root->hasNoChildNode(this->_begin, this->_end)) // If there is only root node in tree
                    this->_root = nullptr;
                else if (this->_root->hasOneChildNode(this->_begin, this->_end)) // If root node has only one child
                {
                    if (this->_root->hasLeft(this->_begin)) // Set root child as root
                        this->_root = this->_root->getLeft();
                    else
                        this->_root = this->_root->getRight();
                    this->_root->setParent(nullptr); // Set new root parent as null
                }
                else
                {
                    node_pointer new_root = this->getBranchMax(this->_root->getLeft()); // Capture max key of tree left side as new root
                    new_root->setRight(this->_root->getRight()); // Set root right child as new root right child
                    this->_root->getRight()->setParent(new_root); // Set new root as parent for root right child

                    if (new_root->getParent()->getRight() == new_root)
                        new_root->getParent()->setRight(nullptr);
                    new_root->setParent(nullptr);

                    if (!(this->isOnLeftBranch(new_root, this->getBranchMin(this->_root)))) // If new_root was not on principal left branch
                    {
                        node_pointer min_new_root = this->getBranchMin(new_root); // Capture min node on new root tree
                        min_new_root->setLeft(this->_root->getLeft()); // Set root left branch on new root min left branch
                        this->_root->getLeft()->setParent(min_new_root);
                    }
                    this->_root = new_root;
                }
            }


            /* Node seeking */
            node_pointer keySearch(const_key_reference key) const {
                return(keySearch(key, this->_root));
            }

            node_pointer keySearch(const_key_reference key, node_pointer node) const
            {
                node_pointer ret(nullptr);

                if (!node)
                    return (nullptr);
                if (node->getKey() == key)
                    return (node);
                if (node->hasLeft(this->_begin))
                    if ((ret = keySearch(key, node->getLeft())))
                        return (ret);
                if (node->hasRight(this->_end))
                    if ((ret = keySearch(key, node->getRight())))
                        return (ret);
                return (ret);
            }

            node_pointer searchNextKey(const_key_reference key) const {
                return (searchNextKey(key, this->_root));
            }

            node_pointer searchNextKey(const_key_reference key, node_pointer node) const
            {
                if (this->_cmp(key, node->getKey()))
                {
                    if (node->hasLeft(this->_begin))
                        return (searchNextKey(key, node->getLeft()));
                    else
                        return (node);
                }
                else
                {
                    if (node->hasRight(this->_end))
                        return (searchNextKey(key, node->getRight()));
                    else if (node->getRight() == this->_end)
                        return (this->_end);
                    else
                        return (node->getParent());
                }
            }


            /* Helper functions */
            node_pointer getBranchMin(node_pointer node)
            {
                if (node->hasLeft(this->_begin))
                    return (getBranchMin(node->getLeft()));
                return (node);
            }

            node_pointer getBranchMax(node_pointer node)
            {
                if (node->hasRight(this->_end))
                    return (getBranchMax(node->getRight()));
                return (node);
            }

            bool isOnLeftBranch(node_pointer node, node_pointer search_node)
            {
                if (node == search_node)
                    return (true);
                if (node->hasLeft(this->_begin))
                    return (isOnLeftBranch(node->getLeft(), search_node));
                return (false);
            }

    };

}

#endif