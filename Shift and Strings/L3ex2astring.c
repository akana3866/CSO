#include <stdio.h>
 
int main(int argc, char **argv)
{
  char w[] = "apple ala carte";
  char *x;
  x = &w[0];
  int acount = 0 ;
  while ( *x != '\0') {
     if (*x == 'a') {acount++;}
     x=x+1;
    }

  printf ( "The value of acount is: %i   \n", acount ) ;
  
    
  return 0;
}
 
