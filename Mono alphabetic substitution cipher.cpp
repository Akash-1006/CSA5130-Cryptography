#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *plaintext, char *key) {
    int i;

    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }

    while (*plaintext) {
        char currentChar = toupper(*plaintext);

        if (isalpha(currentChar)) {
            printf("%c", key[currentChar - 'A']);
        } else {
            printf("%c", *plaintext);
        }

        plaintext++;
    }

    printf("\n");
}

int main() {
    char plaintext[100];
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; 

    printf("Enter the plaintext to be encrypted (up to 100 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Encrypted message: ");
    encrypt(plaintext, key);

    return 0;
}

