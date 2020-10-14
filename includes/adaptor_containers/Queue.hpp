#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "./AdaptorBase.hpp"

namespace ft
{
    template <class T, class Container = Deque<T> >
    class Queue : public AdaptorBase<T, Container>
    {
        public:
            /* Alias assignment */
            typedef AdaptorBase<T, Container> AdaptorBase;
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

            /* Constructors, Copy assignement and Destructor */
            Queue(const container_type& container = container_type())
            : AdaptorBase(container)
            {

            }

            Queue(const Queue& other)
            : AdaptorBase(other._container)
            {

            }

            virtual ~Queue() {}

            Queue& operator=(const Queue& other)
            {
                if (this != &other)
                    this->_container = other._container;
                return (*this);
            }

            /* pure virtual function */
            void pop() {
                this->_container.pop_front();
            }


            /* Specific stack member functions */
            value_type& front() {
                return(this->_container.front());
            }

            const value_type& front() const {
                return(this->_container.front());
            }

            value_type& back() {
                return(this->_container.back());
            }

            const value_type& back() const {
                return(this->_container.back());
            }
    };
}

#endif