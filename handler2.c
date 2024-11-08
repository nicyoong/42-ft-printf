#include "ft_printf.h"

int	handle_integer(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	return (num_len(num));
}

int handle_unsigned(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_putnbr_unsigned_fd(num, 1);
	return (num_len_unsigned(num));
}
int handle_hex(va_list args, int uppercase)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_putnbr_hex_fd(num, 1, uppercase);
	return (num_len_hex(num));
}