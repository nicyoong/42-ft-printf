#include "ft_printf_bonus.h"

int handle_char(va_list args, t_flags flags)
{
    char c = (char)va_arg(args, int);
    int padding = flags.width - 1;

    // Handle right-aligned padding (if `-` flag is not set)
    if (!flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    // Print the character
    ft_putchar_fd(c, 1);

    // Handle left-aligned padding (if `-` flag is set)
    if (flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    return (flags.width > 1) ? flags.width : 1;
}

int handle_string(va_list args, t_flags flags)
{
    char *str = va_arg(args, char *);
    int str_len;
    
    if (!str)
        str = "(null)";
    
    str_len = ft_strlen(str);
    
    // Handle precision: Limit the length if precision is set
    if (flags.dot && flags.precision < str_len)
        str_len = flags.precision;
    
    int padding = flags.width - str_len;

    // Handle right-aligned padding (if `-` flag is not set)
    if (!flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    // Print the string (with precision limit)
    ft_putnstr_fd(str, str_len, 1);

    // Handle left-aligned padding (if `-` flag is set)
    if (flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    return (flags.width > str_len) ? flags.width : str_len;
}

int handle_pointer(va_list args, t_flags flags)
{
    void *ptr_val = va_arg(args, void *);
    int len = 0;

    if (ptr_val == NULL)
    {
        ft_putstr_fd("(nil)", 1);
        return (5);
    }

    // Calculate the length of "0x" + the hexadecimal representation
    len = 2 + num_len_hex((uintptr_t)ptr_val);
    int padding = flags.width - len;

    // Handle right-aligned padding (if `-` flag is not set)
    if (!flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    // Print "0x" prefix and the pointer value
    ft_putstr_fd("0x", 1);
    ft_putnbr_hex_fd((uintptr_t)ptr_val, 1, 0);

    // Handle left-aligned padding (if `-` flag is set)
    if (flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    return (flags.width > len) ? flags.width : len;
}int handle_percent(t_flags flags)
{
    int padding = flags.width - 1;

    // Handle zero-padding if the `0` flag is set and `-` flag is not set
    if (flags.zero && !flags.minus)
        while (padding-- > 0)
            ft_putchar_fd('0', 1);
    else if (!flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    // Print the '%' character
    ft_putchar_fd('%', 1);

    // Handle left-aligned padding (if `-` flag is set)
    if (flags.minus)
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);

    return (flags.width > 1) ? flags.width : 1;
}

