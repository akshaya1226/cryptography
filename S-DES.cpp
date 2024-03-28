#include <stdio.h>

void generateKey(int key[], int subkey1[], int subkey2[]) {
    
}


void encrypt(int plaintext[], int key[], int ciphertext[]) {
    
}


void decrypt(int ciphertext[], int key[], int plaintext[]) {

}

int main() {
    int plaintext[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0};
    int key[] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1};
    int iv[] = {1, 0, 1, 0, 1, 0, 1, 0}; 

    int subkey1[8];
    int subkey2[8];
    generateKey(key, subkey1, subkey2);

    int ciphertext[16];
    int decryptedPlaintext[16];


    for (int i = 0; i < 16; i += 8) {
        
        for (int j = 0; j < 8; j++) {
            plaintext[i + j] ^= iv[j];
        }

        encrypt(plaintext + i, subkey1, ciphertext + i);

        
        for (int j = 0; j < 8; j++) {
            iv[j] = ciphertext[i + j];
        }
    }

    for (int i = 0; i < 16; i += 8) {
        decrypt(ciphertext + i, subkey1, decryptedPlaintext + i);

       
        for (int j = 0; j < 8; j++) {
            decryptedPlaintext[i + j] ^= iv[j];
        }

       
        for (int j = 0; j < 8; j++) {
            iv[j] = ciphertext[i + j];
        }
    }

    printf("Original Plaintext:\n");
    for (int i = 0; i < 16; i++) {
        printf("%d ", plaintext[i]);
    }
    printf("\n");

    printf("Encrypted Ciphertext:\n");
    for (int i = 0; i < 16; i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    printf("Decrypted Plaintext:\n");
    for (int i = 0; i < 16; i++) {
        printf("%d ", decryptedPlaintext[i]);
    }
    printf("\n");

    return 0;
}
