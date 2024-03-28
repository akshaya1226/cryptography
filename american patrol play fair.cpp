#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to prepare the Playfair matrix
void prepareMatrix(char key[], char matrix[5][5]) {
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Note: I/J are treated as one letter
    int keylen = strlen(key);
    int index = 0;

    // Fill the matrix with unique characters from the key
    for (int i = 0; i < keylen; i++) {
        if (key[i] == 'J') key[i] = 'I'; // Replace J with I
        if (strchr(alphabet, key[i]) != NULL) {
            matrix[index / 5][index % 5] = key[i];
            alphabet[key[i] - 'A'] = ' ';
            index++;
        }
    }

    // Fill the remaining matrix with the remaining alphabet
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != ' ') {
            matrix[index / 5][index % 5] = alphabet[i];
            index++;
        }
    }
}

// Function to find the position of a character in the Playfair matrix
void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Replace J with I
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decrypt a digraph using the Playfair cipher
void decryptDigraph(char matrix[5][5], char digraph[2], char result[2]) {
    int row1, col1, row2, col2;
    findPosition(matrix, digraph[0], &row1, &col1);
    findPosition(matrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + 4) % 5]; // Decryption logic
        result[1] = matrix[row2][(col2 + 4) % 5]; // Decryption logic
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + 4) % 5][col1]; // Decryption logic
        result[1] = matrix[(row2 + 4) % 5][col2]; // Decryption logic
    } else {
        result[0] = matrix[row1][col2]; // Decryption logic
        result[1] = matrix[row2][col1]; // Decryption logic
    }
}

int main() {
    char key[] = "MFHIJKUNOPQZVWXYELARGDSTBC";
    char matrix[5][5];
    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char decrypted[100] = "";
    int len = strlen(message);

    // Prepare the Playfair matrix
    prepareMatrix(key, matrix);

    // Decrypt the message
    for (int i = 0; i < len; i += 2) {
        char digraph[2] = {message[i], message[i + 1]};
        char result[2];
        decryptDigraph(matrix, digraph, result);
        strcat(decrypted, result);
    }

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}

