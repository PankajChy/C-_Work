// is_pointer example
#include <iostream>
//#include <type_traits>
#include "is_poniter.h"
namespace std1
{
   template <typename T>
      bool is_pointer(const T &);
}
template <typename T>
void foo(const T& val)
{
   if(std::is_pointer (T) )
      std::cout << "foo called for a pointer" << std::endl;
   else
      std::cout << "foo called for a value" << std::endl;
}

class Test
{
};

int main() 
{
   Test t1;
   Test* t2;
   foo(t1);
   foo(t2);
   return 0;
}

