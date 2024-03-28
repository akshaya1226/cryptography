#include <stdio.h>
#include <stdint.h>

#define ROWS 2
#define COLS 2

void display_state(uint64_t state[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%016lx ", state[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    uint64_t state[ROWS][COLS] = {{0}};

    printf("Initial Internal State:\n");
    display_state(state);

    state[0][0] ^= 0x123456789abcdef1;
    state[1][1] ^= 0xfedcba9876543210;

    printf("After Round 1:\n");
    display_state(state);

    state[1][0] ^= 0xdeadbeefdeadbeef;
    state[0][1] ^= 0xabcdefabcdef1234;

    printf("After Round 2:\n");
    display_state(state);

    state[0][0] ^= 0x5555555555555555;
    state[1][1] ^= 0xaaaaaaaaaaaaaaaa;

    printf("After Round 3:\n");
    display_state(state);

    state[1][0] ^= 0x1111111111111111;
    state[0][1] ^= 0x9999999999999999;

    printf("After Round 4:\n");
    display_state(state);

    return 0;
}
