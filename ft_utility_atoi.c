#include "ft_printf.h"

int	static	pr_scip(const char *str, int p)
{
	int	i;

	i = 0;
	if (p == 1)
		while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
			i++;
	else
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
			i++;
	}
	return (i);
}

int	static	ppow(int a, int b)
{
	int	p;

	p = 1;
	while (b--)
		p *= a;
	return (p);
}

int	static	a_body(int i, const char *str) {
	int p;
	int n;

	p = 0;
	n = pr_scip(str + i, 0);
	while ((str[i] >= '0') && (str[i] <= '9')) {
		p += (str[i] - '0') * ppow(10, --n);
		if (p < 0)
			return (-1);
		i++;
	}
	return (p);
}

int	ft_utility_atoi(const char *str)
{
	int	i;
	int	p;
	int	z;

	i = pr_scip(str, 1);
	if (!ft_utility_strncmp(str + i, "-2147483648", 11))
		return (-2147483648);
	z = 1;
	if (str[i] == '-')
	{
		i++;
		z = -1;
	}
	else
	if (str[i] == '+')
		i++;
	p = a_body(i, str);
	if ((p < 0) && (z < 0))
		return (0);
	if ((p < 0) && (z > 0))
		return (-1);
	return (p * z);
}