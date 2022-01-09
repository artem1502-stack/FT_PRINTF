#include "ft_printf.h"
//cspdiuxX
int print_plz(void *ptr, char type)
{
	int (*outf[8]) (void *);
	int i;

	i = -1;
	outf[0] = &ft_out_char;
 	outf[1] = &ft_out_str;
	outf[2] = &ft_out_pointer;
	outf[3] = &ft_out_int;
	outf[4] = &ft_out_int;
	outf[5] = &ft_out_uns;
	outf[6] = &ft_out_x;
	outf[7] = &ft_out_X;
	while (SPEC_LIST[++i])
		if (SPEC_LIST[i] == type)
			break;
	if (!SPEC_LIST[i])
		return (-1);
	return (outf[i](ptr));
}

int	ft_printf(const char *s, ...)
{
	char	*c;
	void	*p;
	int 	i[2];
	va_list	list;

	i[0] = 0;
	va_start(list, s);
	c = (char *)s;
	while (*c)
	{
		if ((*c == '%') && (*(c + 1) != '%'))
		{
			c++;
			p = va_arg(list, void *);
			i[1] = print_plz(p, *c);
			if (i[1] == -1)
				return (-1);
			i[0] += i[1];
		}
		else
		{
			write(1, c, 1);
			i[0]++;
			if ((*c == '%') && (*(c + 1) == '%'))
				c++;
		}
		c++;
	}
	va_end(list);
	return (i[0]);
}
