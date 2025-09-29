#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

void oct_to_bin(const char* input, char* output) {
    int out_idx = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '0': output[out_idx++] = '0'; output[out_idx++] = '0'; output[out_idx++] = '0'; break;
            case '1': output[out_idx++] = '0'; output[out_idx++] = '0'; output[out_idx++] = '1'; break;
            case '2': output[out_idx++] = '0'; output[out_idx++] = '1'; output[out_idx++] = '0'; break;
            case '3': output[out_idx++] = '0'; output[out_idx++] = '1'; output[out_idx++] = '1'; break;
            case '4': output[out_idx++] = '1'; output[out_idx++] = '0'; output[out_idx++] = '0'; break;
            case '5': output[out_idx++] = '1'; output[out_idx++] = '0'; output[out_idx++] = '1'; break;
            case '6': output[out_idx++] = '1'; output[out_idx++] = '1'; output[out_idx++] = '0'; break;
            case '7': output[out_idx++] = '1'; output[out_idx++] = '1'; output[out_idx++] = '1'; break;
            default: break;
        }
    }
    output[out_idx] = '\0';
}

void oct_to_hex(const char* input, char* output) {
    int decimal = 0;
    sscanf(input, "%o", &decimal);
    sprintf(output, "%X", decimal);
}

void hex_to_bin(const char* input, char* output) {
    int out_idx = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char c = toupper(input[i]);
        switch (c) {
            case '0': strcpy(&output[out_idx], "0000"); break;
            case '1': strcpy(&output[out_idx], "0001"); break;
            case '2': strcpy(&output[out_idx], "0010"); break;
            case '3': strcpy(&output[out_idx], "0011"); break;
            case '4': strcpy(&output[out_idx], "0100"); break;
            case '5': strcpy(&output[out_idx], "0101"); break;
            case '6': strcpy(&output[out_idx], "0110"); break;
            case '7': strcpy(&output[out_idx], "0111"); break;
            case '8': strcpy(&output[out_idx], "1000"); break;
            case '9': strcpy(&output[out_idx], "1001"); break;
            case 'A': strcpy(&output[out_idx], "1010"); break;
            case 'B': strcpy(&output[out_idx], "1011"); break;
            case 'C': strcpy(&output[out_idx], "1100"); break;
            case 'D': strcpy(&output[out_idx], "1101"); break;
            case 'E': strcpy(&output[out_idx], "1110"); break;
            case 'F': strcpy(&output[out_idx], "1111"); break;
            default: strcpy(&output[out_idx], "????"); break;
        }
        out_idx += 4;
    }
    output[out_idx] = '\0';
}

void to_sign_magnitude(int32_t n, char* output) {
    uint32_t result;
    if (n >= 0) {
        result = (uint32_t)n;
    } else {
        result = ((uint32_t)(-n)) | 0x80000000;
    }
    for (int i = 31; i >= 0; i--) {
        output[31 - i] = ((result >> i) & 1) ? '1' : '0';
    }
    output[32] = '\0';
}

void to_ones_complement(int32_t n, char* output) {
    uint32_t result;
    if (n >= 0) {
        result = (uint32_t)n;
    } else {
        result = ~(uint32_t)(-n);
    }
    for (int i = 31; i >= 0; i--) {
        output[31 - i] = ((result >> i) & 1) ? '1' : '0';
    }
    output[32] = '\0';
}

void to_twos_complement(int32_t n, char* output) {
    uint32_t result;
    if (n >= 0) {
        result = (uint32_t)n;
    } else {
        result = (uint32_t)(~(-n) + 1);
    }
    for (int i = 31; i >= 0; i--) {
        output[31 - i] = ((result >> i) & 1) ? '1' : '0';
    }
    output[32] = '\0';
}
