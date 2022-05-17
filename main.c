#include "incs/ft_printf.h"

int     main(void)
{
    printf(" [%i]\n", ft_printf("%#.x\n", 0));
    printf(" [%i]\n", printf("%#.x\n", 0));
    printf("\n\n");

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
