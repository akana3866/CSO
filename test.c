#include <stdio.h>
#include <assert.h>
#include "util.h"

int main(){
    int num = 16922216;

    int result =  (4 << 7) + (4 << 5) + (4 << 3) + (4<<1) - (4);
    printf("the result is %i\n", result);
}