#include <stdio.h>
#include <string.h>

void encrypt_cbc(const char *plaintext, const char *key, const char *iv, char *ciphertext) {
    int len = strlen(plaintext);
    int key_len = strlen(key);

    for (int i = 0; i < len; ++i) {
        ciphertext[i] = plaintext[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
        ciphertext[i] = ciphertext[i] ^ key[i % key_len];
    }

    ciphertext[len] = '\0'; 
}

void decrypt_cbc(const char *ciphertext, const char *key, const char *iv, char *decrypted_text) {
    int len = strlen(ciphertext);
    int key_len = strlen(key);

    for (int i = 0; i < len; ++i) {
        decrypted_text[i] = ciphertext[i] ^ key[i % key_len];
        decrypted_text[i] = decrypted_text[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
    }

    decrypted_text[len] = '\0';
}

int main() {
    const char *plaintext = "Hello, CBC Mode!";
    const char *key = "encryptionkey";
    const char *iv = "initialvector";
    char ciphertext[256];
    char decrypted_text[256];
    encrypt_cbc(plaintext, key, iv, ciphertext);
    printf("Original Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);
    decrypt_cbc(ciphertext, key, iv, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

