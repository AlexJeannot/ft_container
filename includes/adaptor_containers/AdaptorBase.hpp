#ifndef ADAPTORBASE_HPP
# define ADAPTORBASE_HPP

# include "../sequence_containers/Deque.hpp"

namespace ft
{
    template <class T, class Container >
    class AdaptorBase
    {
        public:
            /* Alias assignement */
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

        protected:
            container_type _container;
        
        public:
            /* Constructor and Destructor */
            AdaptorBase(const container_type& container = container_type())
            : _container(container)
            {

            }

            virtual ~AdaptorBase() {}


            /* Virtual functions */
            bool empty() const {
                return(this->_container.empty());
            }

            size_type size() const {
                return (this->_container.size());
            }

            void push(const value_type& val) {
                this->_container.push_back(val);
            }

            
            /* pure virtual function */
            virtual void pop() = 0;


            /* Relational operators */
            template <class T1, class C1>
            friend bool operator==(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);

            template <class T1, class C1>
            friend bool operator!=(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);
    
            template <class T1, class C1>
            friend bool operator<(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);

            template <class T1, class C1>
            friend bool operator<=(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);

            template <class T1, class C1>
            friend bool operator>(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);

            template <class T1, class C1>
            friend bool operator>=(const AdaptorBase<T1, C1>& lhs, const AdaptorBase<T1, C1>& rhs);

    };

    template <typename T, typename Container>
    bool operator==(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container == rhs._container);
    }

    template <typename T, typename Container>
    bool operator!=(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container != rhs._container);
    }

    template <typename T, typename Container>
    bool operator<(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container < rhs._container);
    }

    template <typename T, typename Container>
    bool operator<=(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container <= rhs._container);
    }

    template <typename T, typename Container>
    bool operator>(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container > rhs._container);
    }

    template <typename T, typename Container>
    bool operator>=(const AdaptorBase<T, Container>& lhs, const AdaptorBase<T, Container>& rhs) {
        return (lhs._container >= rhs._container);
    }
}

#endif