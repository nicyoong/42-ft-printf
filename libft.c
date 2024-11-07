#include <unistd.h>

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

void ft_putnbr_hex_fd(unsigned int n, int fd, int uppercase) {
    const char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16) {
        ft_putnbr_hex_fd(n / 16, fd, uppercase);
    }
    ft_putchar_fd(hex_digits[n % 16], fd);
}

void ft_putptr_fd(void *ptr, int fd) {
    unsigned long long ptr_val = (unsigned long long)ptr;
    ft_putstr_fd("0x", fd);  // "0x" prefix for pointers
    ft_putnbr_hex_fd(ptr_val, fd, 0);  // Print the pointer in lowercase hex
}
