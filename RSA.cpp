#include <stdio.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int modExp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    int e = 31;
    int n = 3599;
    int p, q;
    for (p = 2; p < n; p++) {
        if (n % p == 0) {
            q = n / p;
            break;
        }
    }
    int phi = (p - 1) * (q - 1);
    int d = modInverse(e, phi);
    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d): %d\n", d);
    int plaintext = 123;
    int ciphertext = modExp(plaintext, e, n);
    printf("Encrypted ciphertext: %d\n", ciphertext);
    int decrypted_text = modExp(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decrypted_text);

    return 0;
}

