#include "incs/ft_printf.h"

int     main(void)
{
//     printf("[%i]\n", ft_printf("[%#.x]\n", 0));
//     printf("[%i]\n", printf("[%#.x]\n", 0));
//     printf("\n\n");

    printf("[%i]\n", ft_printf("[%#.5x]\n", 123));
    printf("[%i]\n", printf("[%#.5x]\n", 123));
    printf("\n\n");

    printf("[%i]\n", ft_printf("[%20.5i]\n", 123));
    printf("[%i]\n", printf("[%20.5i]\n", 123));
    printf("\n\n");

    // printf("[%i]\n", ft_printf("[%#20.5x]\n", 123));
    // printf("[%i]\n", printf("[%#20.5x]\n", 123));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%i]\n", 123));
    // printf("[%i]\n", printf("[%i]\n", 123));
    // printf("\n\n");

    // printf(" [%i]\n", ft_printf("%#.0x\n", 223));
    // printf(" [%i]\n", printf("%#.0x\n", 223));
    // printf("\n\n");

    // printf(" [%i]\n", ft_printf("[%-5%]"));
    // printf(" [%i]\n", printf("[%-5%]"));
    // printf("\n\n");

    // printf(" [%i]\n", ft_printf("[%x]", 0));
    // printf(" [%i]\n", printf("[%x]", 0));
    // printf("\n\n");
    return (0);
}
