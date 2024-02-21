#include <stdio.h>
int modulo(int x, int divisor,int rec);	  

int main()
 {
	int x = 10;
	int divisor = 2;
	printf("%d mod %d = %d\n", x, divisor,
	modulo(x,divisor, 0 ));
	divisor = 3;
	printf("%d mod %d = %d\n", x, divisor,
	modulo(x,divisor, 1));
	return 0;
 }

 /* c o m p u t e s the r e m a i n d e r from d i v i d i n g x by d i v i s o r */ 
 int modulo(int x, int divisor, int rec)
{
	if ( !rec ) {
	/* i t e r a t i v e v e r s i o n */
	while (x >= divisor) {
	x -= divisor;
	}
	return x;
	}
	else {
	/* r e c u r s i v e v e r s i o n */
	if (x < divisor)
	return x;
	else
	return modulo(x - divisor, divisor, rec);
	}
 }
