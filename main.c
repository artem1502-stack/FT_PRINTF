#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int b = 123;
    int *a = &b;
    int n = ft_printf("%s\n%% _ b = %x, bx = %x", "Vova tochno gay", 0, b);
    printf("\nOUT:%d\n", n);
    n = printf("%s\n%% _ b = %x, bx = %x", "Vova tochno gay", 0, b);
    printf("\nOUT_NORM:%d\n", n);
    return (0);
}
