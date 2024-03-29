#include <stdio.h>
#define XOR_CONSTANT_64 0x1B
#define XOR_CONSTANT_128 0x87

unsigned char leftShiftOneBit(unsigned char value) {
    int carry = (value & 0x80) ? 1 : 0;
    value <<= 1;
    if (carry) {
        value ^= XOR_CONSTANT_64; 
    }
    return value;
}


void generateCMACSubkeys() {
    unsigned char subkey1 = 0;
    unsigned char subkey2;
    subkey1 = leftShiftOneBit(subkey1);
    printf("Subkey 1: 0x%02X\n", subkey1);
    subkey2 = leftShiftOneBit(subkey1);
    printf("Subkey 2: 0x%02X\n", subkey2);
}

int main() {
    printf("Subkey Generation for CMAC:\n");
    generateCMACSubkeys();

    return 0;
}

