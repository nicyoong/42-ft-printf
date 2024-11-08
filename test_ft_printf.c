#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"  // Include the header for ft_printf

void run_test(const char *format, ...) {
    va_list args;
    int ft_result, printf_result;
    char ft_output[1024], printf_output[1024];  // Buffers to capture outputs

    // Start variadic argument processing for ft_printf
    va_start(args, format);
    ft_result = ft_printf(ft_output, format, args);  // Capture ft_printf result
    va_end(args);

    // Reset variadic argument list for printf
    va_start(args, format);
    printf_result = vsprintf(printf_output, format, args);  // Capture printf result
    va_end(args);

    // Output the results of both functions
    printf("Testing: Format: \"%s\"\n", format);
    printf("ft_printf result: %d\n", ft_result);
    printf("ft_printf output: %s\n", ft_output);
    printf("printf result: %d\n", printf_result);
    printf("printf output: %s\n", printf_output);

    // Compare the printed outputs
    if (strcmp(ft_output, printf_output) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    printf("\n");
}

int main(void) {
    // Test cases for each of the specified format specifiers

    // %c: Print a single character
    run_test("%c", 'A');

    // %s: Print a string
    run_test("%s", "Hello, World!");

    // %p: Print a pointer (address in hexadecimal)
    run_test("%p", (void *)0xdeadbeef);

    // %d: Print a signed decimal (int) number
    run_test("%d", -1234);

    // %i: Print an integer in base 10
    run_test("%i", 5678);

    // %u: Print an unsigned decimal number
    run_test("%u", 12345);

    // %x: Print a number in hexadecimal (lowercase)
    run_test("%x", 255);

    // %X: Print a number in hexadecimal (uppercase)
    run_test("%X", 255);

    // %%: Print a percent sign
    run_test("%%");

    // Edge case: Empty string
    run_test("%s", "");

    // Edge case: Zero value
    run_test("%d", 0);

    // Edge case: Negative zero
    run_test("%d", -0);

    // Edge case: Pointer with NULL (NULL pointer)
    run_test("%p", NULL);

    // Edge case: Large hexadecimal value
    run_test("%x", 4294967296);  // Large number in hexadecimal (higher than 32-bit range)

    // Edge case: Large unsigned decimal value
    run_test("%u", 4294967295);  // Maximum value for unsigned integer (32-bit)

    return 0;
}
