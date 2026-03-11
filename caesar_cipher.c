/*********************************************************************** 
Copyright Buu Information Security Major 
File Name: caesar_cipher.c 
Author：宋明禹                      
ID:  2024240381056 
Version:  0.1.0+alpha.1 
Date:  2026.3.11
Description:   
文件包含主函数，以及所用的凯撒加解密函数的实现。            
************************************************************************/
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