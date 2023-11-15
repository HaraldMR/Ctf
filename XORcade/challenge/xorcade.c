#include <stdio.h>
#include <string.h>

// Function to obfuscate the key
int get_key() {
    int a = 10, b = 20, c = 30;
    return (a * b) + (c - a) - (b / 2);
}

// XOR Encryption/Decryption
void xor_encrypt_decrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
    output[len] = '\0';
}

int main() {
    char encrypted_msg[] = {NeeeeeiKaIAlgeDage};
    int key = get_key();
    
    char decrypted_msg[sizeof(encrypted_msg)];
    xor_encrypt_decrypt(encrypted_msg, decrypted_msg, key);

    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}
