#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

#define BUFFER_SIZE 1024

int ft_vsprintf(char *buffer, const char *format, va_list args) {
    int printed_chars = 0;
    const char *ptr = format;
    while (*ptr) {
        if (*ptr == '%' && *(ptr + 1)) {
            ptr++;
            // Handle the conversion specifiers here (same as in ft_printf)
            // For simplicity, you can copy the logic from ft_printf and write output to buffer
            // Update printed_chars as necessary
        } else {
            *buffer++ = *ptr;
            printed_chars++;
        }
        ptr++;
    }
    *buffer = '\0';  // Null-terminate the string
    return printed_chars;
}

// Function to compare the outputs of ft_printf and printf
int compare_output(const char *format, ...) {
    va_list args;
    char printf_buffer[BUFFER_SIZE];
    char ft_printf_buffer[BUFFER_SIZE];

    va_start(args, format);

    // Redirect the output of printf and ft_printf to buffers
    int printf_len = vsnprintf(printf_buffer, BUFFER_SIZE, format, args);
    
    // Reset the va_list and call ft_printf
    va_end(args);
    va_start(args, format);
    int ft_printf_len = ft_vsprintf(ft_printf_buffer, format, args);
    
    va_end(args);

    if (printf_len != ft_printf_len) {
        printf("Length mismatch: Expected %d, Got %d\n", printf_len, ft_printf_len);
        return 0;  // Return failure
    }

    // Compare the output strings
    if (strncmp(printf_buffer, ft_printf_buffer, printf_len) != 0) {
        printf("Mismatch in output!\nExpected: %s\nGot: %s\n", printf_buffer, ft_printf_buffer);
        return 0;  // Return failure
    }

    return 1;  // Return success
}

void test_basic_specifiers() {
    // %c: Single character
    printf("Testing %%c:\n");
    compare_output("%c", 'A'); // Single character 'A'

    // %s: String
    printf("\nTesting %%s:\n");
    compare_output("%s", "Hello, World!");  // String with multiple characters

    // %%: Percent sign
    printf("\nTesting %%%%:\n");
    compare_output("%%");  // Literal '%'

    // %d: Signed integer
    printf("\nTesting %%d:\n");
    compare_output("%d", 123);  // Positive number
    compare_output("%d", -123); // Negative number
    compare_output("%d", 0);     // Zero

    // %i: Integer
    printf("\nTesting %%i:\n");
    compare_output("%i", 456);  // Positive integer
    compare_output("%i", -456); // Negative integer
    compare_output("%i", 0);    // Zero
}

void test_unsigned_specifiers() {
    // %u: Unsigned integer
    printf("\nTesting %%u:\n");
    compare_output("%u", 12345);  // Unsigned positive number
    compare_output("%u", 0);      // Zero
    compare_output("%u", 4294967295U);  // Large unsigned number

    // %x: Hexadecimal (lowercase)
    printf("\nTesting %%x:\n");
    compare_output("%x", 255);      // Hexadecimal of 255 -> ff
    compare_output("%x", 0xABCDEF); // Hexadecimal of 11259375 -> abcdef

    // %X: Hexadecimal (uppercase)
    printf("\nTesting %%X:\n");
    compare_output("%X", 255);      // Hexadecimal of 255 -> FF
    compare_output("%X", 0xABCDEF); // Hexadecimal of 11259375 -> ABCDEF
}

void test_pointer_specifiers() {
    // %p: Pointer
    printf("\nTesting %%p:\n");
    int x = 42;
    compare_output("%p", &x);  // Pointer to x

    // Handle NULL pointer
    compare_output("%p", NULL); // Null pointer should print (nil)
}

void test_edge_cases() {
    // Edge case with NULL string
    printf("\nTesting %%s (NULL string):\n");
    compare_output("%s", NULL);  // Should print "(null)"

    // Edge case with zero length string
    printf("\nTesting %%s (empty string):\n");
    compare_output("%s", "");    // Should print an empty string

    // Testing with large numbers
    printf("\nTesting large numbers with %%d/%%i:\n");
    compare_output("%d", 2147483647);  // Maximum value for a signed int
    compare_output("%d", -2147483647); // Large negative number
    compare_output("%d", 999999999);   // Large positive number

    // Large hexadecimal numbers
    printf("\nTesting large numbers with %%x/%%X:\n");
    compare_output("%x", 0x7FFFFFFFFFFFFFFF);  // Large 64-bit number
    compare_output("%X", 0x7FFFFFFFFFFFFFFF);  // Large 64-bit number in uppercase
}

void test_multiple_specifiers() {
    // Multiple specifiers in one string
    printf("\nTesting multiple specifiers:\n");
    compare_output("Char: %c, String: %s, Integer: %d, Hex: %x", 'A', "Hello", 123, 255);  // Char, string, integer, and hex

    // Mixing signed and unsigned integers
    printf("\nTesting signed and unsigned integers:\n");
    compare_output("Signed: %d, Unsigned: %u", -123, 123456);  // Signed and unsigned numbers
}

void test_large_numbers() {
    // Large positive and negative numbers
    printf("\nTesting large numbers:\n");
    compare_output("INT_MAX: %d, INT_MIN: %d", 2147483647, -2147483648);  // Testing INT_MAX and INT_MIN

    // Large unsigned number
    compare_output("Large unsigned number: %u", 4294967295U);  // Maximum unsigned int value

    // Testing hexadecimal formatting with large numbers
    compare_output("Hexadecimal of INT_MAX: %x", 2147483647);  // Hexadecimal of INT_MAX
    compare_output("Hexadecimal of INT_MIN: %X", -2147483648);  // Hexadecimal of INT_MIN in uppercase
}

void test_special_characters() {
    // Including newline, tab, and escape sequences in strings
    printf("\nTesting special characters in strings:\n");
    compare_output("Tab: %s, Newline: %s, Backslash: %s", "\tTab", "\nNewline", "\\Backslash");

    // Test with a null character inside the string
    printf("\nTesting null character in string:\n");
    compare_output("String with null: %s", "Hello\0World");

    // Test with an empty string
    compare_output("Empty string: %s", "");
}

void test_pointer_edge_cases() {
    // NULL pointer
    printf("\nTesting NULL pointer:\n");
    compare_output("Null pointer: %p", NULL);  // Should print (nil)

    // Pointer to an integer
    int x = 42;
    printf("\nTesting pointer to integer:\n");
    compare_output("Pointer to integer: %p", &x);  // Should print the pointer value in hexadecimal

    // Function pointer (unusual but valid pointer type)
    void (*func_ptr)() = NULL;
    printf("\nTesting function pointer:\n");
    compare_output("Function pointer: %p", func_ptr);  // Should print (nil) for NULL function pointer
}

void test_stress_format() {
    printf("\nStress testing format specifiers:\n");
    compare_output("Char: %c, String: %s, Hex: %x, Pointer: %p, Unsigned: %u, Signed: %d", 
                   'B', "Test", 1234, &test_stress_format, 1000, -500);  // Multiple specifiers in one line
}
int main() {
    // Running the tests
    test_basic_specifiers();
    test_unsigned_specifiers();
    test_pointer_specifiers();
    test_edge_cases();
    test_multiple_specifiers();
    test_large_numbers();
    test_special_characters();
    test_pointer_edge_cases();
    test_stress_format();

    return 0;
}

