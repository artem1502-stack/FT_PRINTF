#include "ft_printf.h"

int ft_utility_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

int is_in(char c, const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}

size_t	ft_utility_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while ((i != dstsize - 1) && (src[i]))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_utility_strlen(src));
}

size_t	ft_utility_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return ((size_t)i);
}

void	print_nc(int n, char c)
{
	while (--n >= 0)
		write(1, &c, 1);
}