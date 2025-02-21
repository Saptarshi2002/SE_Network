#include<stdio.h>

int toBinary(int num, int binary[]) {
    if (num == 0) {
        binary[0] = 0;
        return 1;
    }
    
    int index = 0;
    
    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }
    
    return index; // Return the number of binary digits
}


int binaryToDecimal(int binary[], int size) {
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        decimal += binary[i] * (1 << i);
    }
    return decimal;
}


