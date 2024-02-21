#include <stdio.h>
 
int main(int argc, char **argv)
{
  int b=5;
  int c=6;
  int d=7;
 
  int *x;
  x= &c;
  int inc = 1;
  printf ( "The value of x (pointing to c)  is: %i   \n", *x ) ;
  x=x+inc;
  printf ( "The value of x (pointing to c) + 1  is: %i   \n", *x ) ;
   
  printf ( "The address within x is: %p   \n",  x ) ;
  printf ( "The address of b is: %p  with a value of: %i \n", &b,b ) ;
  printf ( "The address of c is: %p  with a value of: %i \n", &c,c ) ;
  printf ( "The address of d is: %p  with a value of: %i \n", &d,d ) ;
  return 0;
}
 
