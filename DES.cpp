#include <stdio.h>
#include <stdint.h>
// DES S-boxes
const uint8_t SBOX[8][32] = {
    
};

const uint8_t IP[] = {
    
};

const uint8_t IP_INV[] = {
    
};

void initial_permutation(uint8_t data[8]) {
    
}

void inverse_initial_permutation(uint8_t data[8]) {
   
}

void des_round(uint8_t data[8], uint8_t round_key[8]) {
    
}

void generate_round_keys(const uint8_t key[8], uint8_t round_keys[16][8]) {
  
}
void des_encrypt(uint8_t data[8], const uint8_t key[8]) {
    uint8_t round_keys[16][8];
    generate_round_keys(key, round_keys);
    initial_permutation(data);
    int i;
    for ( i = 0; i < 16; i++) {
        des_round(data, round_keys[i+1]);
    }
    inverse_initial_permutation(data);
}
int main() {
    uint8_t plaintext[8];
    uint8_t key[8];
    int i;
    printf("Enter plaintext (8 bytes in hexadecimal format): ");
    for ( i = 0; i < 8; i++) {
        scanf("%2hhx", &plaintext[i]);
    }
    printf("Enter key (8 bytes in hexadecimal format): ");
    for ( i = 0; i < 8; i++) {
        scanf("%2hhx", &key[i]);
    }
    printf("\nPlaintext: ");
    for ( i = 0; i < 8; i++) {
        printf("%01X ", plaintext[i]);
    }

    des_encrypt(plaintext, key);

    printf("\nCiphertext: ");
    for ( i = 0; i < 8; i++) {
        printf("%01X ", plaintext[i]+key[i]);
    }
    printf("\n");
    return 0;
}
