#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertBinary(const char *input, char *output) {
    int index = 0;
    while (*input) {
        for (int i = 7; i >= 0; i--) {
            output[index++] = ((*input >> i) & 1) + '0';
        }
        input++;
    }
    output[index] = '\0';
}

void decodeBinary(const char *binary, char *output) {
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
