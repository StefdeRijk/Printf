#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *arg_str, ...);

int	ft_string(int written, va_list args);
int	ft_char(int written, va_list args);
int	ft_pointer(int written, va_list args);
int	ft_int(int written, va_list args);
int	ft_unsigned_int(int written, va_list args);
int	ft_unsigned_hex(int written, char c, va_list args);

#endif