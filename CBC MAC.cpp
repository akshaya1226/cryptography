#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16 

void xor_blocks(const uint8_t* a, const uint8_t* b, uint8_t* result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = a[i] ^ b[i];
    }
}

void cbc_mac_one_block(const uint8_t* key, const uint8_t* message, uint8_t* mac) {
    xor_blocks(key, message, mac);
}

int main() {
    uint8_t key[BLOCK_SIZE] = {
        0x2b, 0x7e, 0x15, 0x16,
        0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x15, 0x88,
        0x09, 0xcf, 0x4f, 0x3c
    };

    uint8_t message1[BLOCK_SIZE] = {
        0x6b, 0xc1, 0xbe, 0xe2,
        0x2e, 0x40, 0x9f, 0x96,
        0xe9, 0x3d, 0x7e, 0x11,
        0x73, 0x93, 0x17, 0x2a
    };

    uint8_t message2[BLOCK_SIZE * 2];
    uint8_t mac[BLOCK_SIZE];

    printf("Original Message 1: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", message1[i]);
    }
    printf("\n");

    cbc_mac_one_block(key, message1, mac);

    printf("MAC for Message 1: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");

    printf("Original Message 2: ");
    memcpy(message2, message1, BLOCK_SIZE);
    xor_blocks(message1, mac, message2 + BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE * 2; i++) {
        printf("%02x ", message2[i]);
    }
    printf("\n");

    cbc_mac_one_block(key, message2, mac);

    printf("MAC for Message 2: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");

    return 0;
}
