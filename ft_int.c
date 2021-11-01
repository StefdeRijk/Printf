#include "printf.h"
static int	ft_numlen(long nbr);

static char	*ft_numcpy(long nbr, int len, char *str);

int	ft_int(va_list args)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = (long)va_arg(args, int);
	len = ft_numlen(nbr);
	str = malloc(len + 1);
	if (str == 0)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	ft_numcpy(nbr, len, str);
	nbr = write(1, str, len);
	free(str);
	return (nbr);
}

static int	ft_numlen(long nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_numcpy(long nbr, int len, char *str)
{
	while (nbr > 0)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
