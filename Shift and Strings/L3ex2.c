#include <stdio.h>
 
int main(int argc, char **argv)
{
  int a[10];
    for (int i = 0; i < 10; i++) { 
       a[i]=i;
      printf ( "The value of a[i] is: %i   \n", a[i] ) ;
    }

  int *x;
  x= &a[0];
  for (int i = 0; i <= 10; i++) {       
      printf ( "The value of a[i] is: %i   \n", *x ) ;
      x=x+1;
    }
    
  return 0;
}
 
