#include <stdio.h>

void splitBinary(int n) {
    int a = 0, b = 0;
    int bit = 0;
    int position = 0;
    int i = 0;

    while (n > 0) {
        bit = n & 1;
        n = n >> 1;
        if (bit == 1) {
            if (i % 2 == 0)
                a |= (1 << position);
            else
                b |= (1 << position);
            i++;
        }
        position++;
    }
    printf("%d %d\n", a, b);
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        printf("%d\n", n);
        if (n == 0)
            break;
        splitBinary(n);
    }

    return 0;
}
