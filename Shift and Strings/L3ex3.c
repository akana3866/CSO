#include <stdio.h>
 
int main(int argc, char **argv)
{
  int a[10];
 int d=5;
  int b=7;
  int c=6;
 
  int *x;
  x= &c;
  x=x+1;
printf ( "The value of x is: %i   \n", *x ) ;
printf ( "The address of a is: %p   \n", &a ) ;
printf ( "The address of b is: %p   \n", &b ) ;
printf ( "The address of c is: %p   \n", &c ) ;
printf ( "The address of d is: %p   \n", &d ) ;

  int i;
    for ( i = 0; i < 10; i++) { 
       a[i]=i;
      printf ( "The value of a is: %i   \n", a[i] ) ;
    }
 
  x= &a[0];
 for (i = 0; i < 10; i++) { 
       b=b+*x;
       x=x+1;
      printf ( "The value of b is: %i   \n", b ) ;
    }
    
  return 0;
}
 
