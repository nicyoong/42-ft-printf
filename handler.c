#include "ft_printf.h"

int handle_char(va_list args)
{
    char c = (char)va_arg(args, int);  // '%c' takes an int (promoted char)
    ft_putchar_fd(c, 1);  // Assuming putchar_fd is a helper function to print to stdout
    return 1;  // Return the number of characters printed (1 character in this case)
}

int handle_string(va_list args)
{
    char *str = va_arg(args, char *);
    if (str) {
        ft_putstr_fd(str, 1);  // Assuming putstr_fd is a helper function to print strings
        return ft_strlen(str);  // Return the length of the string
    } else {
        ft_putstr_fd("(null)", 1);  // Handle null strings
        return 6;  // Return the length of "(null)"
    }
}

int handle_pointer(va_list args)
{
    void *ptr_val = va_arg(args, void *);
    ft_putptr_fd(ptr_val, 1);  // Assuming putptr_fd is a helper function to print pointers
    return 2 + sizeof(void *) * 2;  // "0x" prefix + length of the address
}

int handle_integer(va_list args)
{
    int num = va_arg(args, int);
    ft_putnbr_fd(num, 1);  // Assuming putnbr_fd is a helper function to print numbers
    return num_len(num);  // Assuming num_len is a helper function to return the length of the number
}

int handle_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    ft_putnbr_unsigned_fd(num, 1);  // Assuming putnbr_unsigned_fd is a helper function to print unsigned numbers
    return num_len_unsigned(num);  // Assuming num_len_unsigned is a helper function to return the length of the unsigned number
}
int handle_hex(va_list args, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    ft_putnbr_hex_fd(num, 1, uppercase);  // Assuming putnbr_hex_fd is a helper function to print hexadecimal numbers
    return num_len_hex(num);  // Assuming num_len_hex is a helper function to return the length of the hexadecimal number
}

int handle_percent()
{
    ft_putchar_fd('%', 1);  // Print the percent sign
    return 1;  // One character printed
}



