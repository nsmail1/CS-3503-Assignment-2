#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_LINE_LEN 256
#define MAX_TESTS 1000

typedef struct {
    char function_name[50];
    char input[100];
    char expected[100];
} TestCase;

void oct_to_bin(const char* input, char* output);
void oct_to_hex(const char* input, char* output);
void hex_to_bin(const char* input, char* output);
void to_sign_magnitude(int32_t n, char* output);
void to_ones_complement(int32_t n, char* output);
void to_twos_complement(int32_t n, char* output);

int main() {
    FILE* file = fopen("a2_test.txt", "r");
    if (!file) {
        perror("Failed to open test file");
        return 1;
    }

    TestCase tests[MAX_TESTS];
    int test_count = 0;
    char line[MAX_LINE_LEN];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || strlen(line) <= 1)
            continue;
        TestCase test;
        char* token = strtok(line, " \t\n");
        if (!token) continue;
        strcpy(test.function_name, token);
        token = strtok(NULL, " \t\n");
        if (!token) continue;
        strcpy(test.input, token);
        token = strtok(NULL, " \t\n");
        if (!token) continue;
        strcpy(test.expected, token);
        tests[test_count++] = test;
    }
    fclose(file);
    int passed = 0;
    for (int i = 0; i < test_count; i++) {
        TestCase test = tests[i];
        char actual_output[200] = {0};
        if (strcmp(test.function_name, "oct_to_bin") == 0) {
            oct_to_bin(test.input, actual_output);
        } else if (strcmp(test.function_name, "oct_to_hex") == 0) {
            oct_to_hex(test.input, actual_output);
        } else if (strcmp(test.function_name, "hex_to_bin") == 0) {
            hex_to_bin(test.input, actual_output);
        } else if (strcmp(test.function_name, "to_sign_magnitude") == 0) {
            int32_t n = atoi(test.input);
            to_sign_magnitude(n, actual_output);
        } else if (strcmp(test.function_name, "to_ones_complement") == 0) {
            int32_t n = atoi(test.input);
            to_ones_complement(n, actual_output);
        } else if (strcmp(test.function_name, "to_twos_complement") == 0) {
            int32_t n = atoi(test.input);
            to_twos_complement(n, actual_output);
        } else {
            printf("Unknown function: %s\n", test.function_name);
            continue;
        }
        int test_num = i + 1;
        int is_pass = strcmp(actual_output, test.expected) == 0;
        printf("Test %d: %s (\"%s\") -> Expected: \"%s\", Got: \"%s\" [%s]\n",
               test_num, test.function_name, test.input,
               test.expected, actual_output, is_pass ? "PASS" : "FAIL");
        if (is_pass) passed++;
    }
    printf("\nSummary: %d/%d tests passed\n", passed, test_count);
    return 0;
}