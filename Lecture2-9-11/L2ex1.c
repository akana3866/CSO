#include <stdio.h>
 
int main(int argc, char **argv)
{
   
  int a;  
  a=2147483645;  /*ending in 7 is highest */
  int i;
    for (i = 0; i < 10; i++) { 
       a=a+1;
      printf ( "The value of a is: %i   \n", a ) ;
    }

 
  return 0;
}
 
