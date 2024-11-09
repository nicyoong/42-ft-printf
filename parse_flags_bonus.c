#include "ft_printf_bonus.h"

int	parse_number(const char **format)
{
	int num = 0;
	while (ft_isdigit(**format))
	{
		num = num * 10 + (**format - '0');
		(*format)++;
	}
	return (num);
}

t_flags parse_flags(const char **format, va_list args)
{
    t_flags flags = {0, 0, -1, 0, 0, 0, 0, -1};

    // Step 1: Parse flags ('-', '0', '#', '+', ' ')
    while (**format == '-' || **format == '0' || **format == '#' || 
           **format == '+' || **format == ' ')
    {
        if (**format == '-') flags.minus = 1;
        else if (**format == '0') flags.zero = 1;
        else if (**format == '#') flags.hash = 1;
        else if (**format == '+') flags.plus = 1;
        else if (**format == ' ') flags.space = 1;
        (*format)++;
    }

    // Step 2: Parse width (integer or '*')
    if (ft_isdigit(**format))
        flags.width = parse_number(format);
    else if (**format == '*')
    {
        flags.width = va_arg(args, int);
        (*format)++;
        // If width is negative, treat it as left-aligned
        if (flags.width < 0)
        {
            flags.minus = 1;
            flags.width = -flags.width;
        }
    }

    // Step 3: Parse precision (starts with '.')
    if (**format == '.')
    {
        (*format)++;
        flags.dot = 1;
        // Precision can be specified as a number or '*'
        if (ft_isdigit(**format))
            flags.precision = parse_number(format);
        else if (**format == '*')
        {
            flags.precision = va_arg(args, int);
            (*format)++;
            // Negative precision is treated as if precision was not specified
            if (flags.precision < 0)
                flags.precision = -1;
        }
        else
        {
            flags.precision = 0; // In case of just '.' with no number, precision is 0
        }
    }

    return flags;
}
