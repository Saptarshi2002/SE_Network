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

int bitwiseXOR(int a, int b) {
    return a ^ b;
}

void performR2(int r[]) {
    r[0] = !r[0];
}

void performR1(int r[]) {
    r[1] = !r[1];
}

void performR0(int r[]) {
    r[2] = !r[2];
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int bin[3], num[3];
    
    int xor = bitwiseXOR(num1, num2);
    printf("Bitwise XOR of %d and %d is: %d\n", num1, num2, xor);

    toBinary(xor, bin);
    toBinary(num1, num);

   // printf("%d%d%d",bin[0],bin[1],bin[2]);
   int k=1;
    
    for (int i = 2; i >=0 ;i--) {
        if (bin[i] == 1) {
           // printf("In if");
            switch (i) {
                case 0:
                    performR2(num);
                    // printf("Performed R2 operation. Decimal: %d\n", binaryToDecimal(num, 3));
                    break;
                case 1:
                    performR1(num);
                    // printf("Performed R1 operation. Decimal: %d\n", binaryToDecimal(num, 3));
                    break;
                case 2:
                    performR0(num);
                    // printf("Performed R0 operation. Decimal: %d\n", binaryToDecimal(num, 3));
                    break;
            }
        }
        printf("Stage%d : %d\n",k++, binaryToDecimal(num, 3));

    }
    
    return 0;
}