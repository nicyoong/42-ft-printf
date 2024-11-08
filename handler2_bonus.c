#include "ft_printf_bonus.h"

int handle_integer(va_list args, t_flags flags)
{
	int num = va_arg(args, int);
	int len = num_len(num);
	int padding = flags.width - len;

	// Handling sign flag
	if (flags.plus && num >= 0)
		ft_putchar_fd('+', 1);
	else if (flags.space && num >= 0)
		ft_putchar_fd(' ', 1);
	else if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}

	// Handle zero-padding
	if (flags.zero && !flags.minus && flags.precision < 0)
		while (padding-- > 0)
			ft_putchar_fd('0', 1);
	
	// Handle precision
	if (flags.dot && flags.precision > len)
	{
		while (flags.precision-- > len)
			ft_putchar_fd('0', 1);
	}

	ft_putnbr_fd(num, 1);

	// Handle left-aligned padding
	if (flags.minus)
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);

	return num_len(num);
}

int	handle_unsigned(va_list args, t_flags flags)
{
	unsigned int	num = va_arg(args, unsigned int);
	int len = num_len_unsigned(num);
	int padding = flags.width - ((flags.precision > len) ? flags.precision : len);

	// Handle precision: Print extra zeroes if precision is specified
	if (flags.dot && flags.precision > len)
		while (flags.precision-- > len)
			ft_putchar_fd('0', 1);

	// Handle zero padding if no precision is specified
	if (flags.zero && !flags.minus && flags.precision < 0)
		while (padding-- > 0)
			ft_putchar_fd('0', 1);

	ft_putnbr_unsigned_fd(num, 1);

	// Handle left-aligned padding
	if (flags.minus)
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);

	// Handle right-aligned padding (if necessary)
	if (!flags.minus)
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);

	return num_len_unsigned(num);
}

int handle_hex(va_list args, t_flags flags, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = num_len_hex(num);
	int prefix_len = (flags.hash && num != 0) ? 2 : 0; // 0x or 0X
	int total_len = len + prefix_len;
	int padding = flags.width - ((flags.precision > len) ? flags.precision : len) - prefix_len;

	// Print the "0x" or "0X" prefix if needed
	if (flags.hash && num != 0)
	{
		if (uppercase)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
	}

	// Handle zero padding if no precision is specified
	if (flags.zero && !flags.minus && flags.precision < 0)
		while (padding-- > 0)
			ft_putchar_fd('0', 1);

	// Handle precision: Print extra zeroes if precision is specified
	if (flags.dot && flags.precision > len)
		while (flags.precision-- > len)
			ft_putchar_fd('0', 1);

	// Print the hexadecimal number
	ft_putnbr_hex_fd(num, 1, uppercase);

	// Handle left-aligned padding
	if (flags.minus)
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);

	// Handle right-aligned padding
	if (!flags.minus)
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);

	return total_len;
}
