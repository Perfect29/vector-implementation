
#ifndef CSCI152_VECTOR_
#define CSCI152_VECTOR_

#include <iostream>
#include <initializer_list>

namespace csci152
{
   using basetype = double;
      // Must be default constructible, copyable, and assignable.
      // In your implementation, only refer to basetype.

   class vector 
   {
      size_t sz;
      size_t cap;     // Always power of two. We always have sz <= cap.
      basetype* heap; // Different vectors do not share heap memory.

   private: 
   public:    // You can delete this line later.

      static size_t minpow2( size_t x );
         // Return smallest power of 2 >= x,
 
      void reallocate( size_t c );  
         // Reallocate to the smallest power of two <= c. 
         // This function always reallocates, so one must
         // think before one calls it.
         
      static_assert( std::default_initializable< basetype > );
      static_assert( std::copy_constructible< basetype > );
      static_assert( std::assignable_from< basetype&, basetype > );

   public:
      vector( );

      vector( const vector& other );
      vector& operator = ( const vector& other );
      ~vector( );

      vector( std::initializer_list< basetype > values );

      void push_back( const basetype& val );

      basetype& operator[]( size_t index );
      const basetype& operator[]( size_t index ) const;

      basetype& at( size_t index );
      const basetype& at( size_t index ) const;
         // Throw std::range_error if index is out of range.

      size_t size( ) const { return sz; } 
      size_t capacity( ) const { return cap; }
      bool isempty( ) const { return sz == 0; }
      void clear( ) { sz = 0; }

      basetype& front( );
      const basetype& front( ) const;
      basetype& back( );
      const basetype& back( ) const;

      void pop_back( );

      void reserve( size_t c );
         // c must be >= size( ). Make sure that capacity is smallest
         // power of two s.t. p >= c. 

      void shrink( );
         // reduce capacity to the smallest power of two that fits,
         // if needed. 

      void insert( size_t i, const basetype& val );
      void erase( size_t i );

      void print( std::ostream& out ) const;
   };

   // Must be inline because it will be included from multiple
   // compilation units:

   inline 
   std::ostream& operator << ( std::ostream& out, const vector& v ) 
   {
      v. print( out );
      return out;
   }

}

#endif 
