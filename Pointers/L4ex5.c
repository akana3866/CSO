//casting.c:
//-------------------------

#include <stdio.h>
#include <stdlib.h>
const int y = 5;

int main () {
int x = 17;
char h1[] = "hello";
char *h2 = "hello";
int * pint = (int *) malloc(sizeof(int));
printf("h1 is at %p\n", h1); 
printf("\n");
printf("h2 is at %p\n", h2); 
printf("\n");
printf(" x is at %p\n", &x);
printf(" y is at %p\n", &y);
printf(" pint is at %p\n",  pint);

return 0;
}