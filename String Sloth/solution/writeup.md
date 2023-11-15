# String Sloth writeup

**Objective:** Find the correct string to print the flag.

## Steps

### Analyze the Binary:
Use a tool like Ghidra or IDA Pro to decompile the binary.
Look for the strcmp function call in the main function.

### Identifying the Correct String:
The strcmp function compares the user input with a hardcoded string.
Locate this string in the binary. It should be "SecretPassword123".

### Getting the Flag:
Run the program and enter "SecretPassword123" as input.
The program should then read the flag from flag.txt and display it.