

#include "vector.h"

int main( int argc, char* argv[] ) 
{

#if 1
   csci152::vector vect = { 1,2,3,4,5,6,7 };
   for( double d = 10; d < 50; ++ d )
      vect. insert( 4, d );

   std::cout << vect << "\n";

   while( vect. size( ) > 5 )
      vect. erase(3);
   std::cout << vect << "\n";
   return 0;

#else
   csci152::vector vect = { "fremd", "bin", "ich", "eingezogen" };
   vect. push_back( "fremd" );
   vect. push_back( "ich" );
   vect. push_back( "wieder" );
  
   std::cout << vect << "\n";
   std::cout << vect. capacity( ) << "\n";

   vect. insert( 5, "zieh" );
   vect. push_back( "aus" );

   std::cout << vect << "\n";
#endif
 
   return 0;
}
