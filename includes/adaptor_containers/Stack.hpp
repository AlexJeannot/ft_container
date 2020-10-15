#ifndef STACK_HPP
# define STACK_HPP

# include "../adaptor_containers/AdaptorBase.hpp"

namespace ft
{
    template <class T, class Container = Deque<T> >
    class Stack : public AdaptorBase<T, Container>
    {
        public:
            /* Alias assignment */
            typedef AdaptorBase<T, Container> AdaptorBase;
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;


            /* Constructors, Copy assignement and Destructor */
            Stack(const container_type& container = container_type())
            : AdaptorBase(container)
            {

            }

            Stack(const Stack& other)
            : AdaptorBase(other._container)
            {

            }

            virtual ~Stack() {}

            Stack& operator=(const Stack& other)
            {
                if (this != &other)
                    this->_container = other._container;
                return (*this);
            }


            /* pure virtual function */
            void pop() {
                this->_container.pop_back();
            }


            /* Specific stack member functions */
            value_type& top() {
                return(this->_container.back());
            }

            const value_type& top() const {
                return(this->_container.back());
            }
    };
}

#endif