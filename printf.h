#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *arg_str, ...);

int	ft_string(va_list args);
int	ft_char(va_list args);
int	ft_pointer(va_list args);
int	ft_int(va_list args);
int	ft_unsigned_int(va_list args);
int	ft_unsigned_hex(char c, va_list args);

#endif