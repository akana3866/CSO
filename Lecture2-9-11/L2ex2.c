#include <stdio.h>
int add2(x) {
 x = x+2;
return x;
}
 
int main(int argc, char **argv) /*(how many arguements there are, and where you can find them)*/
{
   
 // argc is number of arguments
 /* **argv is an array of values provided
           */

 int a=4;
 a = add2(a);
 printf("a is %i\n", a);

  
    
  return 0;
}


