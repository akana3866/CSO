//casting.c:
//-------------------------
#include <stdio.h>

int main() {
int x= 65;
 x=16961 ; // 256 * 66 (B) + 65 (A)
printf ( "x in hex:  %X     \n ", x); // x in hex: 4241
char *p = (char *) &x;
int i;
for (i = 0; i < 4; i ++ ) { 
printf ( "%c   %i \n ", *(p+i) ,i); //a 0, b 1, 2, 3

}
printf("\n");

return 0;
}

