#include "ft_printf_bonus.h"

static int	parse_number(const char **format)
{
	int num = 0;
	while (ft_isdigit(**format))
	{
		num = num * 10 + (**format - '0');
		(*format)++;
	}
	return (num);
}

static t_flags parse_flags(const char **format)
{
	t_flags flags = {0, 0, -1, 0, 0, 0, 0, -1};
	while (**format == '-' || **format == '0' || **format == '#' || 
		   **format == '+' || **format == ' ')
	{
		if (**format == '-') flags.minus = 1;
		if (**format == '0') flags.zero = 1;
		if (**format == '#') flags.hash = 1;
		if (**format == '+') flags.plus = 1;
		if (**format == ' ') flags.space = 1;
		(*format)++;
	}

	// Parse width
	if (ft_isdigit(**format))
		flags.width = parse_number(format);
	
	// Parse precision
	if (**format == '.')
	{
		(*format)++;
		flags.dot = 1;
		flags.precision = parse_number(format);
	}

	return flags;
}