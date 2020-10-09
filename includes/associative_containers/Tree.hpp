#ifndef TREE_HPP
# define TREE_HPP

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

        /* Constructors, Copy assignement and Destructor */
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
            //key_type _key;
            //value_type _value;
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
                    //this->_key = other._key;
                    //this->_value = other._value;
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

            //key_reference getKey(void) {
            //    return (this->_pair.first);
            //}

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

            node_pointer getParent(void) {
                return(this->_parent);
            }

            bool hasParent(void) const {
                return(this->_parent);
            }

            bool hasLeft(node_pointer begin) const {
                return(this->_left && this->_left != begin);
            }

            bool hasRight(node_pointer end) const {
                return(this->_right && this->_right != end);
            }



            bool hasLeftDisplay() const {
                return(this->_left);
            }

            bool hasRightDisplay(void) const {
                return(this->_right);
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

            Tree(const_node_reference other)
            : _begin(other._begin), _root(other._root),
            _end(other._end), _cmp(other._cmp), _alloc(other._alloc)
            {

            }

            ~Tree() {}

            node_reference operator=(const_reference other)
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



            node_pointer begin(void) {
                return (this->_root);
            }

            const_node_pointer begin(void) const {
                return (this->_root);
            }

            node_pointer end(void) {
                return (this->_end);
            }

            const_node_pointer end(void) const {
                return (this->_end);
            }



            void setupBorder(void)
            {
                this->_begin = this->_alloc.allocate(1);
                this->_alloc.construct(this->_begin, value_type());
                this->_end = this->_alloc.allocate(1);
                this->_alloc.construct(this->_end, value_type());
                std::cout << "BEGIN = " << this->_begin << std::endl;
                std::cout << "END = " << this->_end << std::endl;
                //this->_root = this->_begin;
            }

            node_pointer createNode(const_value_reference pair)
            {
                node_pointer new_node(nullptr);

                if (!(this->keySearch(pair.first)))
                {
                    new_node = this->_alloc.allocate(1);
                    this->_alloc.construct(new_node, pair);
                }
                else
                    return (nullptr);

                if (this->_root == nullptr)
                {
                    this->_root = new_node;
                    this->_root->setLeft(this->_begin);
                    this->_root->setRight(this->_end);
                    this->_begin->setParent(this->_root);
                    this->_end->setParent(this->_root);
                }
                else
                    addNode(new_node);
                return (new_node);
            }


            void addNode(node_pointer new_node) {
                addNode(new_node, this->_root);
            }

            void addNode(node_pointer new_node, node_pointer node)
            {
               // std::cout << "ENTREE ADD NODE\n";
                //std::cout << "new_node->getKey() = " << new_node->getKey() << std::endl;
                //std::cout << "node->getKey() = " << node->getKey() << std::endl;
                if (_cmp(new_node->getKey(), node->getKey()))
                {
                    //std::cout << "ENTREE LEFT\n";
                    if (node->hasLeft(this->_begin) && node->getLeft() != this->_begin)
                        return(addNode(new_node, node->getLeft()));
                    else
                    {
                        if (node->getLeft() == this->_begin)
                        {
                            node->setLeft(new_node);
                            new_node->setLeft(this->_begin);
                            this->_begin->setParent(new_node);
                        }
                        else
                            node->setLeft(new_node);
                    }

                }
                else
                {
                    //std::cout << "ENTREE RIGHT\n";
                    if (node->hasRight(this->_end) && node->getRight() != this->_end)
                        return(addNode(new_node, node->getRight()));
                    else
                    {
                        //std::cout << "ENTREE SET RIGHT\n";
                        if (node->getRight() == this->_end)
                        {
                            node->setRight(new_node);
                            new_node->setRight(this->_end);
                            this->_end->setParent(new_node);
                        }
                        else
                        {
                            node->setRight(new_node);
                        }
                    }
                }
                new_node->setParent(node);
            }

            node_pointer getBranchMin(node_pointer node)
            {
                if (node->hasLeft(this->_begin))
                    return (getBranchMin(node->getLeft()));
                return (node);
            }

            node_pointer getBranchMax(node_pointer node)
            {
                std::cout << "--------------\n[" << node->getKey() << "] getBMAX\n";
                if (node->hasRight(this->_end))
                {
                std::cout << "[" << node->getKey() << "] getBMAX hasRight\n";
                    return (getBranchMax(node->getRight()));
                }
                std::cout << "[" << node->getKey() << "] getBMAX final\n";
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

            void DeleteNode(node_pointer node)
            {
                if (!node)
                    return ;
                removeBorders();
                if (node == this->_root)
                    this->DeleteRootNode();
                else
                {
                    if (node->hasNoChildNode(this->_begin, this->_end))
                    {
                        std::cout << "DELETE NO CHILD NODE\n";
                        this->setParentNode(node);
                    }
                    else if (node->hasOneChildNode(this->_begin, this->_end))
                    {
                        std::cout << "DELETE ONE CHILD NODE\n";
                        if (node->hasLeft(this->_begin))
                            this->setParentNode(node, node->getLeft());
                        else
                            this->setParentNode(node, node->getRight());
                    }
                    else
                    {
                        std::cout << "DELETE TWO CHILD NODE\n";
                        setParentNode(node, node->getRight());
                        this->getBranchMin(node->getRight())->setLeft(node->getLeft());
                        node->getLeft()->setParent(getBranchMin(node->getRight()));
                    }
                }
                addBorders();
                // Destroy & Deallocate
            }

            void setParentNode(node_pointer node, node_pointer new_child = nullptr)
            {
                if (new_child)
                    std::cout << "new_child->getKey() = " << new_child->getKey() << std::endl;
                if (node->getParent()->getLeft() == node)
                    node->getParent()->setLeft(new_child);
                else if (node->getParent()->getRight() == node)
                    node->getParent()->setRight(new_child);

                if (new_child)
                    new_child->setParent(node->getParent());

                if (this->isBorder(node->getLeft()))
                {
                    std::cout << "this->getBranchMin(new_child->getParent())->getKey() = " << this->getBranchMin(new_child->getParent())->getKey() << std::endl;
                    this->getBranchMin(node->getParent())->setLeft(this->_begin);
                    if (new_child)
                        this->_begin->setParent(new_child);
                    else
                        this->_begin->setParent(node->getParent());
                    
                }
                if (this->isBorder(node->getRight()))
                {
                    this->getBranchMax(node->getParent())->setRight(this->_end);
                    if (new_child)
                        this->_end->setParent(new_child);
                    else
                        this->_end->setParent(node->getParent());
                }
            }

            void DeleteRootNode(void)
            {
                if (this->_root->hasNoChildNode(this->_begin, this->_end))
                    this->_root = nullptr;
                else if (this->_root->hasOneChildNode(this->_begin, this->_end))
                {
                    if (this->_root->hasLeft(this->_begin))
                    {
                        this->_end->setParent()
                        this->getBranchMax(this->_root->getLeft())->setRight(this->_end);
                        this->_root = this->_root->getLeft();
                        this->_root->setParent(nullptr);
                    }
                    else
                    {
                        this->_root = this->_root->getRight();
                        this->_root->setRight(nullptr);
                    }
                }
                else
                {
                    //std::cout << "============ ENTREE ROOT 2 child ============ \n";
                    node_pointer new_root = this->getBranchMax(this->_root->getLeft());
                    //std::cout << "new_root->getKey() = " << new_root->getKey() << std::endl;

                    //std::cout << "\n---------- ETAPE 1 -----------\n";
                    new_root->setRight(this->_root->getRight());
                    this->_root->getRight()->setParent(new_root);
                    //std::cout << "new_root->getRight()->getKey() = " << new_root->getRight()->getKey() << std::endl;
                    //std::cout << "this->_root->getRight()->getParent()->getKey() = " << this->_root->getRight()->getParent()->getKey() << std::endl;
                    
                        
                    //std::cout << "\n---------- ETAPE 2 -----------\n";
                    //std::cout << "new_root->getParent()->getKey() = " << new_root->getParent()->getKey() << std::endl;
                    if (new_root->getParent()->getRight() == new_root)
                        new_root->getParent()->setRight(nullptr);
                    new_root->setParent(nullptr);
                   // std::cout << "new_root->getParent() = " << new_root->getParent() << std::endl;



                    //std::cout << "\n---------- ETAPE 3 -----------\n";
                    if (!(this->isOnLeftBranch(new_root, this->getBranchMin(this->_root))))
                    {
                        node_pointer min_new_root = this->getBranchMin(new_root);
                        //std::cout << "ENTREE IS NOT ON LEFT BRANCH\n";
                        //std::cout << "min_new_root->getKey() = " << min_new_root->getKey() << std::endl;
                        //std::cout << "this->_root->getLeft() = " << this->_root->getLeft()->getKey() << std::endl;
                        min_new_root->setLeft(this->_root->getLeft());
                        //std::cout << "this->_root->getLeft() = " << this->_root->getLeft()->getKey() << std::endl;
                        //std::cout << "min_new_root->getKey() = " << min_new_root->getKey() << std::endl;
                        this->_root->getLeft()->setParent(min_new_root);
                    }
                    this->_root = new_root;
                }

            }

            node_pointer keySearch(const_key_reference key) {
                return(keySearch(key, this->_root));
            }

            node_pointer keySearch(const_key_reference key, node_pointer node)
            {
                //std::cout << "-----------\n";
                //std::cout << "[" << node->getKey() << "] ENTREE KEYSEARCH"  << std::endl;
                if (!node)
                    return (nullptr);
                node_pointer ret = nullptr;
                if (node->getKey() == key && !(this->isBorder(node)))
                    return (node);
                if (node->hasLeft(this->_begin))
                {
                    //std::cout << "[" << node->getKey() << "] ENTREE LEFT"  << std::endl;
                    ret = keySearch(key, node->getLeft());
                    //std::cout << "[" << node->getKey() << "] RET LEFT = " << ret << std::endl;
                    if (ret)
                        return (ret);
                }
                if (node->hasRight(this->_end))
                {
                    //std::cout << "[" << node->getKey() << "] ENTREE RIGHT"  << std::endl;
                    ret = keySearch(key, node->getRight());
                    //std::cout << "[" << node->getKey() << "] RET RIGHT = " << ret << std::endl;
                    if (ret)
                        return (ret);
                }
                //std::cout << "[" << node->getKey() << "] RET FINAL = " << ret << std::endl;
                return (ret);
            }

            void displayTree(void) {
                displayTree(this->_root);
            }

            void displayTree(node_pointer node)
            {
                if (!node)
                    return ;
                //std::cout << "[" << node->getKey() << "] ENTREE DISPLAY"  << std::endl;
                if (node->hasLeftDisplay())
                {
                  //  std::cout << "[" << node->getKey() << "] ENTREE DISPLAY LEFT"  << std::endl;
                    displayTree(node->getLeft());
                }
                std::cout << "----------------\n";
                std::cout << "Key = " << node->getKey() << std::endl;
                std::cout << "Value = " << node->getValue() << std::endl;
                if (node->hasRightDisplay())
                {
                  //  std::cout << "[" << node->getKey() << "] ENTREE DISPLAY RIGHT"  << std::endl;
                    displayTree(node->getRight());
                }
            }

            bool isBorder(node_pointer node) const {
                return (node == this->_begin || node == this->_end);
            }

            bool areChildBorder(node_pointer node) const {
                return ((node->getLeft() == this->_begin)
                || node->getRight() == this->_end);
            }

    };


}

#endif