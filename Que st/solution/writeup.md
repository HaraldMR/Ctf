# Que st writeup

**Objective:** Discover the correct numeric key to decrypt the flag.

## Steps

### Binary Analysis:
Decompile the binary using a tool like IDA Pro or radare2.
Examine the check_key function.

### Understanding the Key Check:
Notice the arithmetic operation in check_key: key * 3 + 7 == 2023.
Solve for key to find the correct value.

### Retrieving the Flag:
Calculate the key: key=(2023−7)/3key=(2023−7)/3.
Enter this key when running the program to get the flag from flag.txt.