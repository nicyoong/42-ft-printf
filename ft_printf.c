#include "ft_printf.h" 

int handle_format_specifiers(char specifier, va_list args)
{
    int printed_chars = 0;

    if (specifier == 'c') {
        printed_chars += handle_char(args);
    }
    else if (specifier == 's') {
        printed_chars += handle_string(args);
    }
    else if (specifier == 'p') {
        printed_chars += handle_pointer(args);
    }
    else if (specifier == 'd' || specifier == 'i') {
        printed_chars += handle_integer(args);
    }
    else if (specifier == 'u') {
        printed_chars += handle_unsigned(args);
    }
    else if (specifier == 'x') {
        printed_chars += handle_hex(args, 0);  // Lowercase
    }
    else if (specifier == 'X') {
        printed_chars += handle_hex(args, 1);  // Uppercase
    }
    else if (specifier == '%') {
        printed_chars += handle_percent();
    }

    return printed_chars;
}


int ft_printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    const char *ptr = format;

    va_start(args, format);

    while (*ptr) {
        if (*ptr == '%' && *(ptr + 1)) {
            ptr++;  // Move to the format specifier
            printed_chars += handle_format_specifiers(*ptr, args);
        } else {
            ft_putchar_fd(*ptr, 1);  // Handle non-format characters
            printed_chars++;
        }
        ptr++;
    }

    va_end(args);
    return printed_chars;
}
