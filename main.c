#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    printf("[%i]\n", printf("%012.f", 9.4f));
    printf("[%i]\n", ft_printf("%012.f", 9.4f));
    printf("\n");
    printf("[%i]\n", printf("%0-12.f", 9.5f));
    printf("[%i]\n", ft_printf("%0-12.f", 9.5f));
    printf("\n");
    printf("[%i]\n", printf("% 32.f", 9.9f));
    printf("[%i]\n", ft_printf("% 32.f", 9.9f));
    printf("\n");
    // printf("[%i]\n", printf("%0-12.f\n", 9.5f));
    // printf("[%i]\n", ft_printf("%0-12.f\n", 9.5f));
    // printf("\n");
    // printf("[%i]\n", printf("% 32.f\n", 9.9f));
    // printf("[%i]\n", ft_printf("% 32.f\n", 9.9f));
    // printf("\n");

    // printf("[%i]\n", printf("%-+12.11d\n", INT_MIN));
    // printf("[%i]\n", ft_printf("%-+12.11d\n", INT_MIN));
    // printf("\n");
    // printf("[%i]\n", printf("%-+12.12d\n", INT_MIN));
    // printf("[%i]\n", ft_printf("%-+12.12d\n", INT_MIN));
    // printf("\n");
    // printf("[%i]\n", printf("%-+12.13d\n", INT_MIN));
    // printf("[%i]\n", ft_printf("%-+12.13d\n", INT_MIN));
    // printf("\n");
    // printf("[%i]\n", printf("%-030.x\n", 0));
    // printf("[%i]\n", ft_printf("%-030.x\n", 0);
    // printf("\n");

    // printf("%-030.x\n", 0);
    // printf("[%i]\n", printf("%+20.5d", 156));
    // printf("[%i]\n", ft_printf("%+20.5d", 156));
    // printf("\n");
    return (0);
}