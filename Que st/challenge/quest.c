#include <stdio.h>

int check_key(int key) {
    return key * 3 + 7 == 2023;
}

int main() {
    int user_key;
    printf("Enter the key: ");
    fflush(stdout);
    scanf("%d", &user_key);

    if (check_key(user_key)) {
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
        printf("Wrong key!\n");
    }

    return 0;
}
