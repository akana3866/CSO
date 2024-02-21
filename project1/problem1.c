#include <stdio.h>

int bitConverter(char *date) {
    int month, day, hour, minute, second;

    sscanf(date, "%d/%d %d:%d:%d", &month, &day, &hour, &minute, &second);

    // convert each digit to the specified bits and then shift the elements to 
    int bit = 0;

    bit = bit | (month % 10) << 26;  
    bit = bit | (((month / 10) % 10) << 30);  

    bit = bit | ((day % 10) << 20);  
    bit = bit | (((day / 10) % 10) << 24);  

    bit = bit | ((hour % 10) << 14);  
    bit = bit | (((hour / 10) % 10) << 18);  

    bit = bit | ((minute % 10) << 7);  
    bit = bit | (((minute / 10) % 10) << 11);  

    bit = bit | (second % 10);  
    bit = bit | ((second / 10) << 4);  

    return bit;
}

int isDate(char *date) {
    int month, day, hour, minute, second;

    if (sscanf(date, "%d/%d %d:%d:%d", &month, &day, &hour, &minute, &second) != 5)
        return 0;  // Invalid format

    // checks correct ranges
    if (month < 1 || month > 12 || day < 1 || day > 31 ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59 ||
        second < 0 || second > 59)
        return 0; 

    return 1; 
}

int main() {
    int num;

    //scanner gets desired num of dates and saves it
    scanf("%d", &num); 
    getchar(); 

    //runs through dates and converts if it can
    for (int i = 0; i < num; i++) {

        //reads line and adds dates to char array
        char date[20];
        scanf("%19[^\n]", date); 

        if (isDate(date)) {
            int result = bitConverter(date);
            printf("%d\n", result)
            ;
        } else {
            printf("INVALID\n");
        }

        getchar();  // Consume the newline character
    }

    return 0;
}
