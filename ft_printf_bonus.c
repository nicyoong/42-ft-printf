#include "ft_printf_bonus.h" 

static int	handle_format_specifiers(const char **format, va_list args)
{
	int     printed_chars;
    t_flags flags;
    char    specifier;

    flags = parse_flags(format);
    specifier = **format;
	printed_chars = 0;
	if (specifier == 'c')
		printed_chars += handle_char(args, flags);
	else if (specifier == 's')
		printed_chars += handle_string(args, flags);
	else if (specifier == 'p')
		printed_chars += handle_pointer(args, flags);
	else if (specifier == 'd' || specifier == 'i')
		printed_chars += handle_integer(args, flags);
	else if (specifier == 'u')
		printed_chars += handle_unsigned(args, flags);
	else if (specifier == 'x' || specifier == 'X')
		printed_chars += handle_hex(args, flags, specifier == 'X');
	else if (specifier == '%')
		printed_chars += handle_percent(flags);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed_chars;
	const char	*ptr;

	printed_chars = 0;
	ptr = format;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1))
		{
			ptr++;
			printed_chars += handle_format_specifiers(*ptr, args);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			printed_chars++;
		}
		ptr++;
	}
	va_end(args);
	return (printed_chars);
}