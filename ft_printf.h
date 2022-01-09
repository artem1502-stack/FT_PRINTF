#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SPEC_LIST "cspdiuxX"
# define MAX(a,b) (a)*((a)>=(b))+(b)*((a)<(b))

// ft_printf.c
int		ft_printf(const char *s, ...);
int		print_plz(void *ptr, char type);
// ft_utility_atoi.c
int		ft_utility_atoi(const char *str);
// ft_utility_1.c
int		is_in(char c, const char *str);
int		ft_utility_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_utility_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_utility_strlen(const char *s);
void	print_nc(int n, char c);
// ft_utility_2.c
void	ft_utility_putstr(const char *s);
void	ft_putnbr_base(long long int n, int base, int big);
void	ft_putnbr_base_plus(unsigned long long n, unsigned long long base, int big);
int		ft_num_size(long long int n, int base);
// ft_out_1.c
int		ft_out_char(void *ptr);
int		ft_out_str(void *ptr);
int		ft_out_int(void *ptr);
int		ft_out_x(void *ptr);
int		ft_out_X(void *ptr);
// ft_out_2.c
int		ft_out_pointer(void *ptr);
int		ft_out_uns(void *ptr);

#endif
