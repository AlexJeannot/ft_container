#ifndef LISTELEM_HPP
# define LISTELEM_HPP

namespace ft
{
    template <typename T, typename Alloc = std::allocator<T> >
    class ListElem
    {
        public:
            /* Alias assignement */
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef size_t size_type;
            typedef Alloc allocator_type;

        private:
            /* private member variables */
            value_type _value;
            allocator_type _alloc;
            ListElem<value_type>* _prev_elem;
            ListElem<value_type>* _next_elem;

        public:
            /* Constructors, Copy assignement and Destructor */
            ListElem(const allocator_type& alloc = allocator_type())
            : _value(value_type()), _alloc(alloc), _prev_elem(nullptr), _next_elem(nullptr)
            {

            }

            ListElem(const_reference val, const allocator_type& alloc = allocator_type())
            : _value(val), _alloc(alloc), _prev_elem(nullptr), _next_elem(nullptr)
            {

            }

            ListElem(const ListElem &other)
            : _value(other._value), _alloc(other._alloc),
            _prev_elem(other._prev_elem), _next_elem(other._next_elem)
            {

            }


            ~ListElem()
            {

            }


            ListElem &operator=(const ListElem &other)
            {
                if (this != &other)
                {
                    this->_value = other._value;
                    this->_alloc = other._alloc;
                    this->_prev_elem = other._prev_elem;
                    this->_next_elem = other._next_elem;
                }
                return (*this);
            }


            /* Other member functions */
            ListElem* add_before(ListElem* new_elem)
            {
                if (this->_prev_elem)
                    this->_prev_elem->_next_elem = new_elem;
                new_elem->_prev_elem = this->_prev_elem;
                new_elem->_next_elem = this;
                this->_prev_elem = new_elem;
                return (new_elem);
            }

            ListElem* add_after(ListElem* new_elem)
            {
                if (this->_next_elem)
                    this->_next_elem->_prev_elem = new_elem;
                new_elem->_prev_elem = this;
                new_elem->_next_elem = this->_prev_elem;
                this->_next_elem = new_elem;
                return (new_elem);
            }

            ListElem* delete_elem(bool front = false)
            {
                ListElem* return_elem(nullptr);
                (front) ? return_elem = this->_next_elem : return_elem = this->_prev_elem;
                if (this->_prev_elem)
                {
                   // std::cout << "PASSE PREV DELETE\n";
                    this->_prev_elem->_next_elem = this->_next_elem;
                }
                this->_next_elem->_prev_elem = this->_prev_elem;
                return (return_elem);
            }

            ListElem* get_next_elem(void) {
                return (this->_next_elem);
            }

            const ListElem* get_next_elem(void) const {
                return (this->_next_elem);
            }

            ListElem* get_prev_elem(void) {
                return (this->_prev_elem);
            }

            const ListElem* get_prev_elem(void) const {
                return (this->_prev_elem);
            }

            void set_prev_elem(ListElem* elem) {
                this->_prev_elem = elem;
            }

            void set_next_elem(ListElem* elem) {
                this->_next_elem = elem;
            }

            bool is_equal(const_reference val) {
                return (this->_value == val);
            }

            reference get_value(void) {
                return (this->_value);
            }

            const_reference get_value(void) const {
                return (this->_value);
            } 

            reference operator*(void) {
                return (this->_value);
            }

            const_reference operator*(void) const {
                return (this->_value);
            } 




    };


}

#endif