#include "ft_printf.h"

int ft_out_char(void *ptr)
{
	char c;

	c = (char)ptr;
	write (1, &c, 1);
	return (1);
}

int ft_out_str(void *ptr)
{
	char	*s;
	int		n;

	s = (char *)ptr;
	if (s)
	{
		ft_utility_putstr(s);
		n = ft_utility_strlen(s);
		return (n);
	}
	write(1, "(null)", 6);
	return (6);
}

//Флаги: -0.
//	#(space)+
// -:2, 0:3, .:5, #:7, (space):11, +:13

int ft_out_int(void *ptr)
{
	int p = (int)ptr;

	ft_putnbr_base(p, 10, 0);
	return (ft_num_size(p, 10));
}

int ft_out_x(void *ptr)
{
	unsigned p = (unsigned)ptr;

	ft_putnbr_base(p, 16, 0);
	return (ft_num_size(p, 16));
}

int ft_out_X(void *ptr)
{
	long long int p = (long long int)ptr;

	ft_putnbr_base(p, 16, 1);
	return (ft_num_size(p, 16));
}