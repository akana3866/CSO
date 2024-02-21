//casting.c:
//-------------------------
#include <stdio.h>

int main() {
int x[] = {17152, 66, 67, 68, 69};
char *p = (char * ) x;
int i;
for (i = 0; i < 5; i ++ ) { printf ( "%c   %i  ", *(p+i) ,i);
printf ( "%d	\n", *( (int*)(p) + i));
}
printf("\n");

return 0;
}

