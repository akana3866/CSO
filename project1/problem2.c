#include <stdio.h>

int isColor(char *color) {
    int red, green, blue;

    if (sscanf(color, "%d, %d, %d", &red, &green, &blue) != 3)
        return 0;
    if (red < 0 || red > 255 || green < 0 || green > 255 ||
        blue < 0 || blue > 255)
        return 0; 

    return 1;
}

int hexConverter(char *color) {
    int red, green, blue;

    sscanf(color, "%d, %d, %d", &red, &green, &blue);

    // nonvert to hex
    int hexColor = (red << 16) | (green << 8) | blue;

    return hexColor;
}

int main() {
    int num;
    scanf("%d", &num);  
    getchar();  

    for (int i = 0; i < num; i++) {
        char color[13]; //because because 12 char required
        scanf("%12[^\n]", color); 

        //prints color 
        int red, green, blue;
            sscanf(color, "%d, %d, %d", &red, &green, &blue);

            printf("RGB (%d, %d, %d)\n", red, green, blue); 

        // check if it is a color an then convert
        if (isColor(color)) {
            int hexColor = hexConverter(color);
            printf("#%06x\n", hexColor); 
        } else {
            printf("INVALID\n");
        }

        getchar(); 
    }

    return 0;
}
