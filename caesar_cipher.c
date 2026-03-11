/***********************************************************************
Copyright Buu Information Security Major
File Name: caesar_cipher.c
Author：宋明禹
ID:  2024240381056
Version:  1.0
Date:  2026.3.11
Description:
文件包含主函数，以及所用的凯撒加解密函数的实现。
************************************************************************/

#include <stdio.h>

/* 凯撒密码字母偏移量，取值范围 [1, 25] */
#define CAESAR_SHIFT 3

/* 输入字符串缓冲区最大长度 */
#define MAX_LEN 100


/***********************************************************************
Function Name: CaesarEncrypt
Parameters:
    const char *plaintext:  【in】 待加密的明文字符串
    char       *ciphertext: 【out】加密后密文的存储地址
    int         shift:      【in】 凯撒密码字母偏移量
Return:
    Type: void
Description:
    对明文字符串执行凯撒加密。
    将每个字母按偏移量向后移位，非字母字符保持不变。
    大写字母和小写字母分别在各自范围内循环移位。
************************************************************************/
void CaesarEncrypt(const char *plaintext, char *ciphertext, int shift)
{
    int i;
    char c;

    /* 逐字符遍历明文，执行加密 */
    for (i = 0; plaintext[i] != '\0'; i++) {
        c = plaintext[i];

        if (c >= 'a' && c <= 'z') {
            /* 小写字母：在 a-z 范围内循环移位 */
            ciphertext[i] = (c - 'a' + shift) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            /* 大写字母：在 A-Z 范围内循环移位 */
            ciphertext[i] = (c - 'A' + shift) % 26 + 'A';
        }
        else {
            /* 非字母字符不做处理，直接复制 */
            ciphertext[i] = c;
        }
    }

    ciphertext[i] = '\0';
}


/***********************************************************************
Function Name: CaesarDecrypt
Parameters:
    const char *ciphertext: 【in】 待解密的密文字符串
    char       *plaintext:  【out】解密后明文的存储地址
    int         shift:      【in】 凯撒密码字母偏移量
Return:
    Type: void
Description:
    对密文字符串执行凯撒解密。
    将每个字母按偏移量向前移位，非字母字符保持不变。
    加 26 后再取模，保证结果为正数，防止负数索引。
************************************************************************/
void CaesarDecrypt(const char *ciphertext, char *plaintext, int shift)
{
    int i;
    char c;

    /* 逐字符遍历密文，执行解密 */
    for (i = 0; ciphertext[i] != '\0'; i++) {
        c = ciphertext[i];

        if (c >= 'a' && c <= 'z') {
            /* 小写字母：向前移位，+26 保证取模结果非负 */
            plaintext[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            /* 大写字母：向前移位，+26 保证取模结果非负 */
            plaintext[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        else {
            /* 非字母字符不做处理，直接复制 */
            plaintext[i] = c;
        }
    }

    plaintext[i] = '\0';
}


/***********************************************************************
Function Name: main
Parameters:
    void
Return:
    Type: int
    0：程序正常退出
Description:
    程序主函数。读取用户输入的明文字符串，分别调用凯撒加密和
    解密函数，并将加密结果与解密还原结果输出到标准输出。
************************************************************************/
int main(void)
{
    char input[MAX_LEN];      /* 存储用户输入的明文字符串 */
    char encrypted[MAX_LEN];  /* 存储凯撒加密后的密文字符串 */
    char decrypted[MAX_LEN];  /* 存储解密还原后的明文字符串 */

    /* 提示并读取用户输入的明文 */
    printf("请输入明文字符串: ");
    fgets(input, sizeof(input), stdin);

    /* 执行凯撒加密 */
    CaesarEncrypt(input, encrypted, CAESAR_SHIFT);

    /* 执行凯撒解密 */
    CaesarDecrypt(encrypted, decrypted, CAESAR_SHIFT);

    /* 输出加密和解密结果 */
    printf("加密结果: %s", encrypted);
    printf("解密结果: %s", decrypted);

    return 0;
}