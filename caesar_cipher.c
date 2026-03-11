#include <stdio.h>
#define caesar_cipher 3
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Caesar Cipher: ");
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + caesar_cipher) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + caesar_cipher) % 26 + 'A';
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}