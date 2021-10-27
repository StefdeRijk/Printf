#include "printf.h"
static int	ft_read_str(const char *format, va_list args);

static int	ft_check_type(const char *format, va_list args, int written);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, format);
	written = ft_read_str(format, args);
	va_end(args);
	return (written);
}

static int	ft_read_str(const char *format, va_list args)
{
	int	i;
	int	written;

	i = 0;
	written = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			written = ft_check_type(format + i, args, written);
			i++;
		}
		else
		{
			write(1, format + i, 1);
			i++;
			written++;
		}
	}
	return (written);
}

static int	ft_check_type(const char *format, va_list args, int written)
{
	char			*str;
	int				ints;
	unsigned long	adress;

	if (*format == 's')
		written = ft_string(written, args);
	if (*format == 'c')
		written = ft_char(written, args);
	if (*format == 'p')
		written = ft_pointer(written, args);
	if (*format == 'd' || *format == 'i')
		written = ft_int(written, args);
	if (*format == 'u')
		written = ft_unsigned_int(written, args);
	if (*format == 'x' || *format == 'X')
		written = ft_unsigned_hex(written, *format, args);
	if (*format == '%')
		written += write(1, "%%", 1);
	return (written);
}
