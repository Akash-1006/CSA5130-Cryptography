#include <stdio.h>
#include <string.h>

void encryptECB(char *plaintext, char *key, int block_size) {
    int i, j;

    int num_blocks = strlen(plaintext) / block_size;

    for (i = 0; i < num_blocks; i++) {
        for (j = 0; j < block_size; j++) {
            plaintext[i * block_size + j] ^= key[j];
        }
    }
}

void decryptECB(char *ciphertext, char *key, int block_size) {
    encryptECB(ciphertext, key, block_size);
}

int main() {
    char plaintext[] = "This is a simple ECB mode example";
    char key[] = "secretKey";
    int block_size = 8; 
    printf("Original plaintext: %s\n", plaintext);
    encryptECB(plaintext, key, block_size);
    printf("Encrypted ciphertext: %s\n", plaintext);
    decryptECB(plaintext, key, block_size);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

