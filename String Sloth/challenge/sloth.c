#include <stdio.h>
#include <string.h>

int main() {
    char secret_code[50];
    system("clear");
    printf("Enter the secret code: ");
    scanf("%49s", secret_code);

    if (strcmp(secret_code, "DontLetASlothTypeThisItWouldTakeAYear") == 0) {
        FILE *file = fopen("flag.txt", "r");
        if (file != NULL) {
            char flag[100];
            if (fgets(flag, sizeof(flag), file)) {
                printf("Flag: %s\n", flag);
            }
            fclose(file);
        } else {
            printf("Flag file not found.\n");
        }
    } else {
        printf("Wrong secret code!\n");
    }

    return 0;
}
