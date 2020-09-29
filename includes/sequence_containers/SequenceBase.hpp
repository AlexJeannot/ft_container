/**
 * This class purpose is to set up sequence containers structures 
**/

#ifndef SEQUENCEBASE_HPP
# define SEQUENCEBASE_HPP

namespace ft 
{

    template < class T, class Alloc = allocator<T> >
    class SequenceBase
    {
        /*Alias definitions
        using value_type = T;
        using allocator_type = Allocator;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = size_t;
        using difference_type = std::ptrdiff_t;
        //using iterator = 
        */

        public:
            SequenceBase() {};
            virtual ~SequenceBase() {};






    };

}

#endif