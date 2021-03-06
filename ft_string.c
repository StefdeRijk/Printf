#include "printf.h"
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_string(int written, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		written += write(1, "(null)", 6);
	else
		written += write(1, str, ft_strlen(str));
	return (written);
}
