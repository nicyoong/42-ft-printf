#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

// Macro to test and compare ft_printf with printf
#define TEST_PRINTF(fmt, ...) \
{ \
    int ret1, ret2; \
    char *buf1 = malloc(1000); \
    char *buf2 = malloc(1000); \
    ret1 = snprintf(buf1, 1000, fmt, __VA_ARGS__); \
    ret2 = ft_printf(fmt, __VA_ARGS__); \
    printf("Expected: \"%s\" | ft_printf returned: %d\n", buf1, ret2); \
    printf("Got     : \"%s\"\n\n", buf2); \
    if (ret1 == ret2 && strcmp(buf1, buf2) == 0) \
        printf("Test passed ✔️\n\n"); \
    else \
        printf("Test failed ❌\n\n"); \
    free(buf1); \
    free(buf2); \
}

int main(void)
{
    printf("=== Testing ft_printf with various flags ===\n\n");

    // Test %d and %i with flags '+', ' ', '-', '0', '.'
    TEST_PRINTF("Test 1: |%+5d|", 42);
    TEST_PRINTF("Test 2: |%-10d|", 42);
    TEST_PRINTF("Test 3: |%05d|", -42);
    TEST_PRINTF("Test 4: |% d|", 42);
    TEST_PRINTF("Test 5: |%.3d|", 7);
    TEST_PRINTF("Test 6: |%10.5d|", -42);
    
    // Test %u with flags '-', '0', width, precision
    TEST_PRINTF("Test 7: |%-10u|", 123);
    TEST_PRINTF("Test 8: |%010u|", 123);
    TEST_PRINTF("Test 9: |%.6u|", 123);
    TEST_PRINTF("Test 10: |%8.4u|", 123);
    
    // Test %x and %X with '#', '0', '-', width, precision
    TEST_PRINTF("Test 11: |%#8x|", 255);
    TEST_PRINTF("Test 12: |%#8X|", 255);
    TEST_PRINTF("Test 13: |%-#10x|", 255);
    TEST_PRINTF("Test 14: |%08x|", 255);
    TEST_PRINTF("Test 15: |%.5x|", 255);
    
    // Test %c with width and '-'
    TEST_PRINTF("Test 16: |%-5c|", 'A');
    TEST_PRINTF("Test 17: |%5c|", 'A');

    // Test %s with '-', width, precision
    TEST_PRINTF("Test 18: |%-10s|", "hello");
    TEST_PRINTF("Test 19: |%10s|", "hello");
    TEST_PRINTF("Test 20: |%.3s|", "hello");
    TEST_PRINTF("Test 21: |%10.3s|", "hello");
    
    // Test %p with '#' and width
    int x = 42;
    TEST_PRINTF("Test 22: |%20p|", &x);
    TEST_PRINTF("Test 23: |%-20p|", &x);

    // Test %%
    TEST_PRINTF("Test 24: |%%|");
    TEST_PRINTF("Test 25: |%-5%|");
    TEST_PRINTF("Test 26: |%5%|");

    return 0;
}
