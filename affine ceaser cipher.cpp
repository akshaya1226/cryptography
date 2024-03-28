#include <stdio.h>

char encrypt(char p, int a, int b) {
    if (p >= 'A' && p <= 'Z') {
        return ((a * (p - 'A') + b) % 26) + 'A';
    } else if (p >= 'a' && p <= 'z') {
        return ((a * (p - 'a') + b) % 26) + 'a';
    }
    return p; 
}

char decrypt(char c, int a, int b) {
    int a_inverse = 1;
    while ((a_inverse * a) % 26 != 1) {
        a_inverse++;
    }

    if (c >= 'A' && c <= 'Z') {
        return ((a_inverse * (c - 'A' - b + 26)) % 26) + 'A';
    } else if (c >= 'a' && c <= 'z') {
        return ((a_inverse * (c - 'a' - b + 26)) % 26) + 'a';
    }
    return c;
}

int main() {
    char plaintext[] = "Hello, Affine Caesar Cipher!";
    int a = 3; // Affine parameter a (must be coprime with 26)
    int b = 5; // Affine parameter b

    printf("Original Plaintext: %s\n", plaintext);

    printf("Encrypted Text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char encrypted_char = encrypt(plaintext[i], a, b);
        printf("%c", encrypted_char);
    }
    printf("\n");

    printf("Decrypted Text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char decrypted_char = decrypt(plaintext[i], a, b);
        printf("%c", decrypted_char);
    }
    printf("\n");

    return 0;
}
