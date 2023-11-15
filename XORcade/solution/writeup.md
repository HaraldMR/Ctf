# XORcade writeup

**Objective:** Decrypt the encrypted message by finding the correct XOR key.

## Steps

### Analyzing the Binary:
Use a reverse engineering tool like Ghidra or Binary Ninja.
Focus on the get_key and xor_encrypt_decrypt functions.

### Deciphering the Key:
Follow the operations in get_key to determine how the key is generated.
The key is calculated as: (10 * 20) + (30 - 10) - (20 / 2).

### Decrypting the Message:
Calculate the key from the above operation.
Manually apply the XOR operation with this key to the encrypted message array.
Alternatively, modify the program to print the key and use it to decrypt the message.