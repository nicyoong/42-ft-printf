#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int hash;
    int plus;
    int space;
    int width;
    int precision;
} t_flags;

int		ft_putnbr_hex_fd(uintptr_t n, int fd, int uppercase);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		num_len(int num);
int		num_len_unsigned(unsigned int num);
int		num_len_hex(unsigned int num);
int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_pointer(va_list args);
int		handle_integer(va_list args);
int		handle_unsigned(va_list args);
int		handle_hex(va_list args, int uppercase);
int		handle_percent(int n);
int		ft_printf(const char *format, ...);

#endif