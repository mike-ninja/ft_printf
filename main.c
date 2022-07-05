#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    // printf("[%i]\n", printf("%.10f\n", 0.0005));
    // printf("[%i]\n", ft_printf("%.10f\n", 0.0005));
    // printf("\n");
    // printf("[%i]\n", printf("%-#30x\n", 0));
    // printf("[%i]\n", ft_printf("%-#30x\n", 0));
    // printf("\n");
    // printf("[%i]\n", printf("/%#8.4o/\t/%#8.4o/\n", 17, 1234));
    // printf("[%i]\n", ft_printf("/%#8.4o/\t/%#8.4o/\n", 17, 1234));
    // printf("\n");

    printf("[%i]\n", printf("%-+12.11d\n", INT_MIN));
    printf("[%i]\n", ft_printf("%-+12.11d\n", INT_MIN));
    printf("\n");
    // printf("[%i]\n", printf("%+20.5d", 156));
    // printf("[%i]\n", ft_printf("%+20.5d", 156));
    // printf("\n");
    return (0);
}