#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"  // Include your ft_printf header file

int main()
{
    // Test case for %c: single character
    int i, j;
    printf("Test %%c:\n");
    printf("printf result: ");
    i = printf("%c", 'A');
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%c", 'A');
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %s: string
    printf("Test %%s:\n");
    printf("printf result: ");
    i = printf("%s", "Hello, World!");
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%s", "Hello, World!");
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %p: pointer
    printf("Test %%p:\n");
    printf("printf result: ");
    i = printf("%p", (void *)0xdeadbeef);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%p", (void *)0xdeadbeef);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %d: signed decimal integer
    printf("Test %%d:\n");
    printf("printf result: ");
    i = printf("%d", 42);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%d", 42);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %i: signed integer
    printf("Test %%i:\n");
    printf("printf result: ");
    i = printf("%i", 42);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%i", 42);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %u: unsigned decimal
    printf("Test %%u:\n");
    printf("printf result: ");
    i = printf("%u", 42);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%u", 42);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %x: hexadecimal (lowercase)
    printf("Test %%x:\n");
    printf("printf result: ");
    i = printf("%x", 255);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%x", 255);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %X: hexadecimal (uppercase)
    printf("Test %%X:\n");
    printf("printf result: ");
    i = printf("%X", 255);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%X", 255);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Test case for %%: percent sign
    printf("Test %%%%:\n");
    printf("printf result: ");
    i = printf("%%");
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%%");
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for an empty string
    printf("Test empty string:\n");
    printf("printf result: ");
    i = printf("%s", "");
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%s", "");
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for 0 value (signed)
    printf("Test 0 value (signed):\n");
    printf("printf result: ");
    i = printf("%d", 0);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%d", 0);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for a negative number
    printf("Test negative value (signed):\n");
    printf("printf result: ");
    i = printf("%d", -42);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%d", -42);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for NULL pointer
    printf("Test NULL pointer:\n");
    printf("printf result: ");
    i = printf("%p", NULL);
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%p", NULL);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for large hexadecimal value
    printf("Test large hexadecimal value:\n");
    printf("printf result: ");
    i = printf("%x", (unsigned int)4294967296);  // Larger than a 32-bit integer
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%x", (unsigned int)4294967296);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    // Edge case for large unsigned integer value
    printf("Test large unsigned value:\n");
    printf("printf result: ");
    i = printf("%u", (unsigned int)4294967295);  // Maximum unsigned value for 32-bit
    printf("\n");
    printf("\n");
    printf("printf result: %d\n", i);
    printf("ft_printf result: ");
    j = ft_printf("%u", (unsigned int)4294967295);
    printf("\n");
    printf("ft_printf result: %d\n", j);
    printf("\n");

    return 0;
}
