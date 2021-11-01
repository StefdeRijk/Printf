#include "printf.h"
static int	ft_read_str(const char *arg_str, va_list args);

static int	ft_check_type(const char *arg_str, va_list args, int written);

int	ft_printf(const char *arg_str, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, arg_str);
	written = ft_read_str(arg_str, args);
	va_end(args);
	return (written);
}

static int	ft_read_str(const char *arg_str, va_list args)
{
	int	i;
	int	written;

	i = 0;
	written = 0;
	while (arg_str[i] != '\0')
	{
		if (arg_str[i] == '%')
		{
			i++;
			written = ft_check_type((arg_str + i), args, written);
		}
		else
			written += write(1, &arg_str[i], 1);
		i++;
	}
	return (written);
}

static int	ft_check_type(const char *arg_str, va_list args, int written)
{
	if (*arg_str == 's')
		written += ft_string(args);
	if (*arg_str == 'c')
		written += ft_char(args);
	if (*arg_str == 'p')
		written += ft_pointer(args);
	if (*arg_str == 'd' || *arg_str == 'i')
		written += ft_int(args);
	if (*arg_str == 'u')
		written += ft_unsigned_int(args);
	if (*arg_str == 'x' || *arg_str == 'X')
		written += ft_unsigned_hex(*arg_str, args);
	if (*arg_str == '%')
		written += write(1, "%%", 1);
	return (written);
}
