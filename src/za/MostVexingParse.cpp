
#include "MostVexingParse.h"

/*
 *
 * The line

  TimeKeeper time_keeper(Timer());
is seemingly ambiguous, since it could be interpreted either as

a variable definition for variable time_keeper of class TimeKeeper,
initialized with an anonymous instance of class Timer or
a function declaration for a function time_keeper that returns
an object of type TimeKeeper and has a single (unnamed) parameter that is
 a pointer to function returning type Timer (and taking no input).
  (See Function object#In C and C++)
Most programmers expect the first, but the C++ standard requires it to be interpreted as the second.

For example, g++ gives the following error message:

$ g++ -c time_keeper.cc
time_keeper.cc: In function ¡®int main()¡¯:
time_keeper.cc:15: error: request for member ¡®get_time¡¯ in ¡®time_keeper¡¯, which is
  of non-class type ¡®TimeKeeper(Timer (*)())¡¯
Notice that the compiler gives the error message about the
 return statement of main(): since it interpreted the declaration
 of time_keeper as a function declaration we won't be able to call
 the member function get_time() on this.


 One way to force the compiler to consider this as a variable definition is to add an extra pair of parentheses:

  TimeKeeper time_keeper( (Timer()) );
 * */
int mainMV() {

//    TimeKeeper time_keeper(Timer());  //erro :this is a functhion ,return a TimeKeeper and

  TimeKeeper time_keeper( (Timer()) );//ok

  return time_keeper.get_time();
}
