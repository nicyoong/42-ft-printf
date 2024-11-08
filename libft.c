#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (char)((n % 10) + '0');
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

// these are not in libft so code them yourself in real ft printf

void ft_putnbr_unsigned_fd(unsigned int n, int fd) {
    if (n >= 10) {
        ft_putnbr_unsigned_fd(n / 10, fd);
    }
    ft_putchar_fd(n % 10 + '0', fd);
}

int	ft_putnbr_hex_fd(uintptr_t num, int fd, int is_upper)
{
	const char	*hex_digits;
	int			count;

	if (is_upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_putnbr_hex_fd(num / 16, fd, is_upper);
	ft_putchar_fd(hex_digits[num % 16], fd);
	count++;
	return (count);
}

