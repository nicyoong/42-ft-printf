#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_hex_fd(unsigned int n, int fd, int uppercase);
void	ft_putptr_fd(void *ptr, int fd);
size_t	ft_strlen(const char *str);
int		num_len(int num);
int		num_len_unsigned(unsigned int num);
int		num_len_hex(unsigned int num);
int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_pointer(va_list args);
int		handle_integer(va_list args);
int		handle_unsigned(va_list args);
int		handle_hex(va_list args, int uppercase);
int		handle_percent();

int		ft_printf(const char *format, ...);

#endif