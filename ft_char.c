#include "printf.h"
int	ft_char(int written, va_list args)
{
	int		ints;
	char	c;

	ints = va_arg(args, int);
	c = ints;
	written += write(1, &c, 1);
	return (written);
}
