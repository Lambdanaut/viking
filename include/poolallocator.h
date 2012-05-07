#ifndef VIKPOOLALLOCATOR_H_INCLUDED
#define VIKPOOLALLOCATOR_H_INCLUDED

#include <cstddef>
#include <iostream>
#include <cassert>

namespace vik
{
 
template<class T, size_t N>
class PoolAllocator
{
public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef const T* const_pointer;
        typedef const T& const_reference;
        
        static_assert( sizeof( value_type ) >= sizeof( void* ), "Size of pool value_type must be greater than or equal to the size of a pointer." );
        static_assert( N > 0, "Size of pool must be greater than 0." );
        
private:
        void* head;
        value_type pool[ N ];   
        
public:
        PoolAllocator():
        head(pool)
        {
                for ( size_t i = 0; i < N - 1; ++i )
                {
                        *reinterpret_cast<void**>( pool + i ) = pool + i + 1;
                }
                *reinterpret_cast<void**>( pool + N - 1 ) = NULL;
        }
        
        pointer allocate()
        {
                if ( head == NULL ) return NULL;
                
                void* old_head( head );
                head = *reinterpret_cast<void**>( old_head );
                return static_cast<pointer>( old_head );
        }
        
        void deallocate(pointer p)
        {
                *reinterpret_cast<void**>( p ) = head;
                head = p;
        }
        
        size_t max_size() const
        {
                return N;
        }
        
        void construct(pointer p, const_reference val)
        {
                new(p) value_type(val);
        }
        
        void destroy(pointer p)
        {
                p->~value_type();
        }
        
        void debug()
        {
                std::cout << std::endl;
                std::cout << "Address  : Contains" << std::endl;
                std::cout << "-----------------------" << std::endl;
                std::cout << "Head     : " << head << std::endl;
                for (size_t i = 0; i < N; ++i)
                {
                        std::cout << pool + i << " : " << *reinterpret_cast<void**>( pool + i ) << std::endl;
                }
                std::cout << "-----------------------" << std::endl << std::endl;
        }
};

} // end namespace vik

#endif // VIKPOOLALLOCATOR_H_INCLUDED
