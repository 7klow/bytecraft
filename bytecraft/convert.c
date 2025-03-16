#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BINARY ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void str2bin(const char *input, char *output) {
    
    int index = 0;
    while (*input) {
        for (int i = 7; i >= 0; i--) {
            output[index++] = ((*input >> i) & 1) + '0';
        }
        input++;
    }
    output[index] = '\0';
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DECODE BINARY VERSION:

void bin2str(const char *binary, char *output) {
    int len = strlen(binary);
    if (len % 8 != 0) {
        strcpy(output, "Error: Binary string must be a multiple of 8 bits!");
        return;
    }
    int index = 0;
    for (int i = 0; i < len; i += 8) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte = (byte << 1) | (binary[i + j] - '0');
        }
        output[index++] = byte;
    }
    output[index] = '\0';
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ HEXA ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void str2hexa(const char *input, char *output) {
    
    int index = 0;
    while (*input) {

        for (int i = 3; i >= 0; i--) {
            output[index++] = ((*input >> (i * 4)) & 0xF) + ((((*input >> (i * 4)) & 0xF) < 10) ? '0' : 'A' - 10);
        }

        input++;
    }
    output[index] = '\0';
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DECODE HEXA VERSION:

void hexa2str(const char *hexa, char *output) {

    int len = strlen(hexa);
    if (len % 4 != 0) {
        strcpy(output, "Error: Hexadecimal string must be a multiple of 4 bits!");
        return;
    }
    int index = 0;
    for (int i = 0; i < len; i += 4) {
        char byte = 0;
        for (int j = 0; j < 4; j++) {
            byte = (byte << 4) | (hexa[i + j] - (((hexa[i + j] >= 'A') && (hexa[i + j] <= 'F')) ? 'A' - 10 : '0'));
        }
        output[index++] = byte;
    }
    output[index] = '\0';
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BASE64 ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void str2base64(const char *base, char *output) {

    const char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int   binLen = strlen(base) * 8;
    char *binStr = (char *)malloc(binLen + 1);

    if  (!binStr) return;

    str2bin(base, binStr);
    
    int binStrLen    = strlen(binStr);
    int padCount     = (6 - (binStrLen % 6)) % 6;
    int paddedBinLen = binStrLen + padCount;

    int   base64Len  = paddedBinLen / 6;
    char *encoded    = (char *)malloc(base64Len + 1);

    if (!encoded) {
        free(binStr);
        return;
    }

    for (int i = 0; i < paddedBinLen; i += 6) {
        int index = 0;
        for (int j = 0; j < 6; j++) {
            if (i + j < binStrLen)
                index = (index << 1) | (binStr[i + j] - '0');
            else
                index = (index << 1);
        }
        encoded[i / 6] = base64Chars[index];
    }

    int outputLen = base64Len + (padCount ? (padCount / 2) : 0);
    for (int i = base64Len; i < outputLen; i++)
        encoded[i] = '=';

    encoded[outputLen] = '\0';
    strcpy(output, encoded);

    free(binStr);
    free(encoded);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DECODE base64 VERSION: 

 
void base64tostr(const char *base64, char *output) {

    const char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int base64Len = strlen(base64);
    int padCount  = (base64[base64Len - 1] == '=') + (base64[base64Len - 2] == '=');

    int binLen = base64Len * 6;
    char *binStr = (char *)malloc(binLen + 1);
    
    if (!binStr) return;

    int binIndex = 0;
    for (int i = 0; i < base64Len; i++) {
        if (base64[i] == '=') break;

        char *ptr = strchr(base64Chars, base64[i]);
        if (!ptr) continue;

        int index = ptr - base64Chars;

        for (int j = 5; j >= 0; j--) {
            binStr[binIndex++] = ((index >> j) & 1) + '0';
        }
    }

    binStr[binIndex] = '\0';

    int textLen = (binIndex - padCount * 2) / 8;
    char *text = (char *)malloc(textLen + 1);

    if (!text) {
        free(binStr);
        return;
    }

    bin2str(binStr, text);

    strcpy(output, text);

    free(binStr);
    free(text);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ HASH ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

// ...