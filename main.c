#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    printf("[%i]\n", printf("%#.5x", 21));
    printf("[%i]\n", ft_printf("%#.5x", 21));
    printf("\n");
    // printf("[%i]\n", printf("/%#8.6o/\t/%#8.5o/\n", 17, 1234));
    // printf("[%i]\n", ft_printf("/%#8.6o/\t/%#8.5o/\n", 17, 1234));
    // printf("\n");
    printf("[%i]\n", printf("\t/%#8.2o/\t/%#8.2o/\t/%#8.2o/\n", 0, 17, 1234));
    printf("[%i]\n", ft_printf("\t/%#8.2o/\t/%#8.2o/\t/%#8.2o/\n", 0, 17, 1234));
    printf("\n");
    printf("[%i]\n", printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234));
    printf("[%i]\n", ft_printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234));
    printf("\n");
    printf("[%i]\n", printf("\t/%#8.5o/\t/%#8.5o/\t/%#8.5o/\n", 0, 17, 1234));
    printf("[%i]\n", ft_printf("\t/%#8.5o/\t/%#8.5o/\t/%#8.5o/\n", 0, 17, 1234));
    printf("\n");
    
    // printf("[%i]\n", printf("%.6f\n", -0.0 / 0.0));
    // printf("[%i]\n", ft_printf("%.6f\n", -0.0 / 0.0));
    // printf("\n");
    return (0);
}