//casting.c:
//-------------------------
#include <stdio.h>

int main() {
int x= 65;
 x=16961 ; // 256 * 66 (B) + 65 (A)
printf ( "x in hex:  %X     \n ", x);
char *p =  &x;
int i;
for (i = 0; i < 4; i ++ ) { 
printf ( "%c   %i \n ", *(p+i) ,i);

}
printf("\n");

return 0;
}

