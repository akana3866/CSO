/*
This code was coded solely by Aditi Kanaujia
this file represents the reversed engineered 
code of the bar assembly language
*/

long bar ( long a, long b ){
    long x = x + a;
    long c = 0;
    long d = (a * 4) + a;
    d = (d * 2) + a;
    a = b << 4;
    d = (b * 2) + (d-a) + (d+1);
    d -= a;
    d += 1;
    long e;
    do{
        x++;
        e+=d;

    }while(x <= b);
    return e;
}