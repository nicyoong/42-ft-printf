#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

// Include your `ft_printf` header file here
#include "ft_printf.h"

// Function prototypes
void test_char();
void test_string();
void test_pointer();
void test_integer();
void test_unsigned();
void test_hex();
void test_hex_upper();
void test_percent();

// Utility function to test and compare outputs of `ft_printf` and `printf`
void run_test(const char *format, ...) {
    va_list args1, args2;
    va_start(args1, format);
    va_start(args2, format);

    // Capture output and return value of `ft_printf`
    printf("\n--- Testing: \"%s\" ---\n", format);
    printf("ft_printf output:\n");
    int ft_ret = ft_printf(format, args1);
    printf("\n(ft_printf return: %d)\n", ft_ret);

    // Capture output and return value of `printf`
    printf("printf output:\n");
    int std_ret = printf(format, args2);
    printf("\n(printf return: %d)\n", std_ret);

    va_end(args1);
    va_end(args2);

    // Check if return values match
    if (ft_ret == std_ret)
        printf("✅ Test passed.\n");
    else
        printf("❌ Test failed (return value mismatch).\n");
}

// Test case for character specifier
void test_char() {
    run_test("Char: %c", 'A');
    run_test("Char: %c", '\0');
}

// Test case for string specifier
void test_string() {
    run_test("String: %s", "Hello, World!");
    run_test("Empty string: %s", "");
    run_test("Null string: %s", NULL);
}

// Test case for pointer specifier
void test_pointer() {
    int x = 42;
    run_test("Pointer: %p", &x);
    run_test("Null pointer: %p", NULL);
}

// Test case for integer specifiers
void test_integer() {
    run_test("Integer: %d", 123);
    run_test("Negative integer: %i", -456);
    run_test("Zero: %d", 0);
    run_test("INT_MAX: %d", INT_MAX);
    run_test("INT_MIN: %i", INT_MIN);
}

// Test case for unsigned integer specifier
void test_unsigned() {
    run_test("Unsigned: %u", 123);
    run_test("Max unsigned: %u", UINT_MAX);
    run_test("Zero: %u", 0);
}

// Test case for hexadecimal (lowercase) specifier
void test_hex() {
    run_test("Hex (lower): %x", 255);
    run_test("Zero: %x", 0);
    run_test("Max unsigned: %x", UINT_MAX);
}

// Test case for hexadecimal (uppercase) specifier
void test_hex_upper() {
    run_test("Hex (upper): %X", 255);
    run_test("Zero: %X", 0);
    run_test("Max unsigned: %X", UINT_MAX);
}

// Test case for percent specifier
void test_percent() {
    run_test("Percent sign: %%");
    run_test("Double percent: %%%%");
}

// Main function to run all tests
int main() {
    printf("Running tests for ft_printf:\n");

    test_char();
    test_string();
    test_pointer();
    test_integer();
    test_unsigned();
    test_hex();
    test_hex_upper();
    test_percent();

    return 0;
}
