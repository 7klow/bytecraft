#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encodelib.h"

int detectByteSize(unsigned int num) {

    if (num <= 0xFF) return 1;      // 1 octet (8 bits)
    if (num <= 0xFFFF) return 2;    // 2 octets (16 bits)
    if (num <= 0xFFFFFF) return 3;  // 3 octets (24 bits)
    return 4;                       // 4 octets (32 bits)
}

void convertBinary(const void *input, int size, char *output) {

    int index = 0;
    
    if (size == sizeof(char *)) {  
        
        // IF STRING
        const char *str = *(const char **)input;
        while (*str) {

            for (int i = 7; i >= 0; i--) {

                output[index++] = ((*str >> i) & 1) + '0';
            }
            str++;
        }
        output[index] = '\0'; // END OF STRING
    } else {
        
        // IF INTEGER OR CHAR
        unsigned int num = *(const unsigned int *)input;
        int bytes = detectByteSize(num);
        int bits = bytes * 8;

        for (int i = bits - 1; i >= 0; i--) {

            output[index++] = ((num >> i) & 1) + '0';
        }
        output[index] = '\0'; // END OF STRING
    }
}


void decodeBinary(const char *binary, char *output) {

    int len = strlen(binary);
    
    // MULTIPLE OF 8 BITS
    if (len % 8 != 0) {

        strcpy(output, "Error: Binary string must be a multiple of 8 bits !");
        return;
    }

    int index = 0;
    for (int i = 0; i < len; i += 8) {

        char byte = 0;
        
        // CONVERT 8 BITS TO CHAR
        for (int j = 0; j < 8; j++) {

            byte = (byte << 1) | (binary[i + j] - '0');
        }
        output[index++] = byte;
    }
    output[index] = '\0'; // END OF STRING
}
