#include "ft_printf.h"

int	ft_out_pointer(void *ptr)
{
	unsigned long long	p;
	int 				i;

	i = 0;
	p = (unsigned long long)ptr;
	write(1, "0x01", 4);
	ft_putnbr_base_plus(p, 16, 0);
	while (p > 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

int	ft_out_uns(void *ptr)
{
	unsigned p;

	p = (unsigned)ptr;
	ft_putnbr_base_plus(p, 10, 0);
	return (ft_num_size(p, 10));
}