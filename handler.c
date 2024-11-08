#include "ft_printf.h"

int	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
}

int	handle_pointer(va_list args)
{
	void *ptr_val;

	ptr_val = va_arg(args, void *);
	ft_putptr_fd(ptr_val, 1);
	return (2 + sizeof(void *) * 2);
}

int handle_percent()
{
	ft_putchar_fd('%', 1);
	return (1);
}
