#include <stdio.h>
#include <string.h>

const int MAX = 50;

char custom_xor(char str[], int key)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] ^ key;
    }
    return *str;
}

void checkpassword(char *pas)
{
    char password[MAX] = "kattenminersafin";
    if (strcmp(pas, password) == 0)
    {
        printf("Correct password!\n");
        char flag[MAX] = "siktCTF{xor_is_a_really_bad_encryption_method}";
        printf("Flag: %s\n", flag);
    }
    else
    {
        printf("Wrong password!\n");
    }
}

int main()
{
    char passwordin[MAX] = "";

    printf("Enter password: ");
    scanf("%s", passwordin);

    char pas[MAX];
    strncpy(pas, passwordin, MAX);
    custom_xor(pas, 44);
    checkpassword(pas);

    return 0;
}