#include <stdio.h>
 
int main(int argc, char **argv)
{
  int b=5;
  int c=6;
  int d=7;

 /* shows the addresses of b,c,d - what order? */
  printf ( "The address of b is: %p  with a value of: %i \n", &b,b ) ;
  printf ( "The address of c is: %p  with a value of: %i \n", &c,c ) ;
  printf ( "The address of d is: %p  with a value of: %i \n", &d,d ) ;

/* x is declared as a pointer  - set value equal to address of c */
  int *x;
  x= &c;

/* *x is a deference of the address in x meaning the contents of location of the address in x*/
  printf ( "The value of x (pointing to c)  is: %i   \n", *x ) ;

/* when adding to x, we add the value * the length of the data type pointed to by x */
  int inc = 1;
  x=x+inc;
  printf ( "The value of x (pointing to c) + 1  is: %i   \n", *x ) ;
   
  printf ( "The address within x is: %p   \n",  x ) ;

  return 0;
}
 
