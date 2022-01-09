#include "ft_printf.h"

void	ft_utility_putstr(const char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_putnbr_base(long long int n, int base, int big)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
	}
	ft_putnbr_base_plus(n, base, big);
}

void	ft_putnbr_base_plus(unsigned long long n, unsigned long long base, int big)
{
	char	c;

	if (n >= base)
		ft_putnbr_base_plus(n / base, base, big);
    n = n % base;
    if (n < 10)
		c = (char)(n + '0');
	else if (big)
		c = (char)(n - 10 + 'A');
	else
		c = (char)(n - 10 + 'a');
	write(1, &c, 1);
}

int	ft_num_size(long long int n, int base)
{
	int i;

	i = 0;
    if (n == 0)
        return (1);
	if (n < 0)
	{
		i++;
		n = (-1) * n;
	}
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}