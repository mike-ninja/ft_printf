#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    printf("[%i]\n", printf("%.3f", 0.0005f));
    printf("[%i]\n", ft_printf("%.3f", 0.0005f));
    printf("\n");
    printf("[%i]\n", printf("%.2f", 958.125000));
    printf("[%i]\n", ft_printf("%.2f", 958.125000));
    printf("\n");
    printf("[%i]\n", printf("%.2f", -958.125000));
    printf("[%i]\n", ft_printf("%.2f", -958.125000));
    printf("\n");
    printf("[%i]\n", printf("%0#10.1f", 0.150000));
    printf("[%i]\n", ft_printf("%0#10.1f", 0.150000));
    printf("\n");
    printf("[%i]\n", printf("%10.1f", 0.150000));
    printf("[%i]\n", ft_printf("%10.1f", 0.150000));
    printf("\n");
    printf("[%i]\n", printf("%.1f", 0.150000));
    printf("[%i]\n", ft_printf("%.1f", 0.150000));
    printf("\n");
    printf("[%i]\n", printf("%0#10.1f", 0.250000));
    printf("[%i]\n", ft_printf("%0#10.1f", 0.250000));
    printf("\n");
    printf("[%i]\n", printf("%10.1f", 0.250000));
    printf("[%i]\n", ft_printf("%10.1f", 0.250000));
    printf("\n");
    // printf("[%i]\n", printf("%0#.2f\n", 0.350000));
    // printf("[%i]\n", ft_printf("%0#.2f\n", 0.350000));
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
    // printf("[%i]\n", printf("%p, %p", 1, 1));
    // printf("[%i]\n", ft_printf("%p, %p", 1, ));
    // printf("\n");
    // printf("[%i]\n", printf("{%05.*d}", -15, 42));
    // printf("[%i]\n", ft_printf("{%05.*d}", -15, 42));
    // printf("\n");
    // printf("[%i]\n", printf("%.p, %.0p", 0, 0));
    // printf("[%i]\n", ft_printf("%.p, %.0p", 0, 0));
    // printf("\n");
    return (0);
}