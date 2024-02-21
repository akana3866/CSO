/*pass by value*/
#include <stdio.h>
void swap(int x, int y);
int main()
{
int x = 1;
int y = 2;
printf("x=%d, y=%d\n", x, y);
swap(x,y);
printf("x=%d, y=%d\n", x, y);
return 0;
}
// s w a p s v a l u e s of x and y
void swap(int x, int y)
{
int tmp;
tmp = x;
x = y;
y = tmp;
}

/*pass by reference*/
void swapRef(int *x, int *y);

int main()
 {
int x = 1;
int y = 2;
printf("x=%d, y=%d\n", x, y);
swapRef(&x, &y);
printf("x=%d, y=%d\n", x, y);
return 0;
}

 // s w a p s v a l u e s of x and y 17 void swap(int *x, int *y)
void swapRef(int *x, int *y)
{
int tmp;
tmp = *x;
*x = *y;
*y = tmp;
 }
 /*arrays*/
 void arrays(){
    // instansiate array
    const int size = 10;
    int a[size];

    //populate and print array
    int i = 0;
    for(i = 0; i< size; i++){
        a[i] = i;
        printf("%d", a[i]);
    }

    //using a pointer
    int *pa = &a[0];
    /*
    pa = pa + 1; ----> it really adds 4 bytes because you want next integer (6008)
    */
    for(i = 0; i< size; i++){
        printf("%d", pa[i]);
    }

    //using a pointer pt.2
    int *pa1 = a;
    for(i = 0; i< size; i++){
        printf("%d", pa1[i]);
    }

    //traverse in an array backwards
    int *pa3 = a + size-1;
    for(i = 0; i < size; i++){
        printf("%d", *pa3);
        pa3 = pa3-1;
    } 

    
 }