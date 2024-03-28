
#include <stdio.h>
#include <string.h>

void aes_encrypt(char *plaintext, char *key, char *ciphertext) {

    strcpy(ciphertext, "AES_ENCRYPTED");
}

void aes_decrypt(char *ciphertext, char *key, char *plaintext) {
   
    strcpy(plaintext, "AES_DECRYPTED");
}

void simulate_bit_error(char *block, int block_size, int bit_position) {
    block[bit_position / 8] ^= (1 << (bit_position % 8));
}

int main() {
    char key[] = "SECRET_KEY123456"; 
    char plaintext[] = "HELLO_WORLD123456"; 
    char ciphertext_ecb[17]; 
    char ciphertext_cbc[17]; 
    char decrypted_ecb[17]; 
    char decrypted_cbc[17]; 

    aes_encrypt(plaintext, key, ciphertext_ecb);

    char iv[] = "INITIAL_VECTOR1234"; 
    char previous_ciphertext[17]; 
    strcpy(previous_ciphertext, iv); 
    int bit_error_position = 7; 

    simulate_bit_error(plaintext, 16, bit_error_position);

    aes_encrypt(plaintext, key, ciphertext_cbc);
    simulate_bit_error(ciphertext_cbc, 16, bit_error_position);

    aes_decrypt(ciphertext_ecb, key, decrypted_ecb);

    aes_decrypt(ciphertext_cbc, key, decrypted_cbc);

    printf("Original Plaintext: %s\n", plaintext);
    printf("ECB Ciphertext: %s\n", ciphertext_ecb);
    printf("CBC Ciphertext: %s\n", ciphertext_cbc);
    printf("Decrypted ECB: %s\n", decrypted_ecb);
    printf("Decrypted CBC: %s\n", decrypted_cbc);

    return 0;
}
