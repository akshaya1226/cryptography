#include <stdio.h>
#include <stdint.h>

// Block size in bytes
#define BLOCK_SIZE 8 // For 64-bit block size
// #define BLOCK_SIZE 16 // For 128-bit block size

// Function to perform left shift on a byte array
void leftShift(uint8_t *input, int len) {
    uint8_t carry = 0;
    for (int i = 0; i < len; i++) {
        uint8_t nextCarry = input[i] >> 7;
        input[i] = (input[i] << 1) | carry;
        carry = nextCarry;
    }
}

int main() {
    uint8_t zeroBlock[BLOCK_SIZE] = {0}; 
    printf("Block cipher operation on zeroBlock\n");


    uint8_t constRb = 0x87;
  
    leftShift(zeroBlock, BLOCK_SIZE);


    if (zeroBlock[0] & 0x80) {
        zeroBlock[BLOCK_SIZE - 1] ^= constRb;
    }

 
    printf("First Subkey: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", zeroBlock[i]);
    }
    printf("\n");

    // Second subkey generation
    leftShift(zeroBlock, BLOCK_SIZE);
    if (zeroBlock[0] & 0x80) {
        zeroBlock[BLOCK_SIZE - 1] ^= constRb;
    }

    // Print the second subkey
    printf("Second Subkey: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", zeroBlock[i]);
    }
    printf("\n");

    return 0;
}
