#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    // printf("[%i]\n", printf("%#.0f", 0.0));
    // printf("[%i]\n", ft_printf("%#.0f", 0.0));
    // printf("\n");
    // printf("[%i]\n", printf("%+012.0d\n", 0));
    // printf("[%i]\n", ft_printf("%+012.0d\n", 0));
    // printf("\n");
    // printf("[%i]\n", printf("%#.0f", 0.0));
    // printf("[%i]\n", ft_printf("%#.0f", 0.0));
    // printf("\n");
    // printf("[%i]\n", printf("%.5o", 21));
    // printf("[%i]\n", ft_printf("%.5o", 21));
    // printf("\n");
    // printf("[%i]\n", printf("%-5.o", 0));
    // printf("[%i]\n", ft_printf("%-5.o", 0));
    // printf("\n");
    // // printf("[%i]\n", printf("%#5.7o", 12));
    // printf("[%i]\n", ft_printf("%#5.7o", 12));
    // printf("\n");
    // printf("[%i]\n", printf("%#.1o", 0));
    // printf("[%i]\n", ft_printf("%#.1o", 0));
    // printf("\n");
    // // printf("[%i]\n", printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234));
    // // printf("[%i]\n", ft_printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234));
    // // printf("\n");
    // printf("[%i]\n", printf("%-5.o", 0));
    // printf("[%i]\n", ft_printf("%-5.o", 0));
    // printf("\n");
    // printf("[%i]\n", printf("%-5.0o", 0));
    // printf("[%i]\n", ft_printf("%-5.0o", 0));
    // printf("\n");
    printf("[%i]\n", printf("%.5p, %.5p", 0, 0));
    printf("[%i]\n", ft_printf("%.5p, %.5p", 0, 0));
    printf("\n");
    printf("[%i]\n", printf("{%05.*d}", -15, 42));
    printf("[%i]\n", ft_printf("{%05.*d}", -15, 42));
    printf("\n");
    printf("[%i]\n", printf("%.p, %.0p", 0, 0));
    printf("[%i]\n", ft_printf("%.p, %.0p", 0, 0));
    printf("\n");
    return (0);
}