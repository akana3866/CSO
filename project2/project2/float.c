/*
The author of this file is Aditi Kanaujia. All the coding is done by me, Aditi. 
This file contains methods that calculate the IEEE 754 representation of a float point.
The first methods checks if the number inputed is a valid floating point. The second
method extracts the normalized fractional part of the floating point. The last method
calculates the bias middle number. Finally, the third method extracts the sign of the number.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {

    if(isinf(f) || isnan(f)){ //if f is infinity number or not a number
        return 1; // it returns 1
    }
    else{
        return 0;
    }

}
float get_M  ( float f ) {
    //if statements check if real float number returns zero if infinity and 1 is nan
    if (isinf(f)) {
        return 0.0;
    } else if (isnan(f)) {
        
        return 1.0;  
    } else {
        // Extract the mantissa (fractional part) of the float
        unsigned int bits = *(unsigned int *)&f;
        unsigned int fraction = bits & 0x7FFFFF; //extracts bits
        fraction |= 0x800000; //adds one to normalize
        float mantissa = fraction / 8388608.0f; //properly formats to decimal float number
        return mantissa;
    }
}

int get_s ( float f ) {
    if(f < 0){ //if less than 0 it's negative
        return -1;
    }
    else{ //else positive
        return 1;
    }	
	return 0;
}

int get_E ( float f ) {

    unsigned int bits = *(unsigned int *)&f;  // treat f as bits

    // extract the exponent bits (bits 30-23)
    int exponent_bits = (bits >> 23) & 0xFF;

    // the actual exponent is stored as a biased value
    int exponent = exponent_bits - 127;  // Subtract the bias (127)

    return exponent;
}













      



    
    
