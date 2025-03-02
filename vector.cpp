
#include "vector.h"

namespace csci152
{

   size_t vector::minpow2( size_t x )
   { 
      size_t power = 1;
      while (power < x) {
         power *= 2;
      }
      return power;
   }

   void vector::reallocate( size_t c )
   {
      if (c <= cap) return;

      size_t new_cap = minpow2(c);
      basetype* new_heap = new basetype[new_cap];

      for (size_t i = 0; i < sz; ++i) {
         new_heap[i] = heap[i];
      }

      delete[] heap;
      heap = new_heap;
      cap = new_cap;
   }

   vector::vector() : sz(0), cap(1), heap(new basetype[1])
   { 

   }

   vector::vector( const vector& other ) : sz(other.size()),
   cap(minpow2(other.size())), 
   heap(new basetype[minpow2(other.size())])
   { 
      for (size_t i = 0; i < other.size(); i++) {
         heap[i] = other.heap[i];
      }
   }

   vector& vector::operator = ( const vector& other )
   { 
      if (this == &other) {
         return *this;
      }
      delete[] heap;
      sz = other.sz;
      cap = other.cap;
      heap = new basetype[cap];
      for (size_t i = 0; i < sz; i++) {
         heap[i] = other.heap[i];
      }
      return *this;
   }

   vector:: ~vector( )
   { 
      delete[] heap;
   }

   vector::vector( std::initializer_list< basetype > values ) : 
   sz(values.size()), 
   cap(minpow2(values.size())), 
   heap(new basetype[minpow2(values.size())])
   { 
      size_t i = 0;
      for (auto &val : values) {
         heap[i] = val;
         i++;
      }
   }

   void vector::push_back( const basetype& val )
   { 
      if (sz == cap) {
         reallocate(sz + 1);
      }
      heap[sz] = val;
      sz++;
   }

   basetype& vector::operator[] ( size_t i )
   {
      return heap[i];   
   }

   const basetype& vector::operator[]( size_t i ) const
   { 
      return heap[i];
   }

   basetype& vector::at( size_t i ) 
   {
      if (i >= sz)
        throw std::out_of_range("at");
      return heap[i];
   }

   const basetype& vector::at( size_t i ) const
   { 
      if (i >= sz)
        throw std::out_of_range("at");
      return heap[i];
   }

   basetype& vector::front( ) 
   { 
      if (sz > 0) {
         return heap[0];
      }
      throw std::out_of_range("front");
   }

   const basetype& vector::front( ) const 
   {
      if (sz > 0) {
         return heap[0];
      }
      throw std::out_of_range("front");
   }

   basetype& vector::back( )
   { 
      if (sz > 0) {
         return heap[sz - 1];
      }
      throw std::out_of_range("back");
   }

   const basetype& vector::back( ) const
   { 
      if (sz > 0) {
         return heap[sz - 1];
      }
      throw std::out_of_range("back");
   }

   void vector::pop_back( )
   {
      sz--;
   }

   void vector::reserve( size_t c )
   { 
      if (cap < c) {
         reallocate(c);
      }
   }

   void vector::shrink( )
   {
      size_t new_cap = minpow2(sz);
      if (new_cap < cap) {
      reallocate(new_cap);
   }
   }

   void vector::insert( size_t i, const basetype& val )
   { 
      if (sz == cap) {
         reallocate(sz + 1);
      }
      sz++;
      for (size_t j = sz - 1; j > i; j--) {
         heap[j] = heap[j - 1];
      }
      heap[i] = val;
   }

   void vector::erase( size_t i )
   { 
      if (i >= sz) {
      throw std::out_of_range("index is out of range");
      }
      for (size_t j = i; j < sz - 1; j++) {
         heap[j] = heap[j + 1];
      }
      sz--;
   }

   void vector::print( std::ostream& out ) const
   { 
      out << "[ ";
      for (size_t i = 0; i < sz; i++) {
         out << heap[i];
         if (i != sz - 1) out << ", ";
         else out << " ";
      }
      out << "]";
   }
}

