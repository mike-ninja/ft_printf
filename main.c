#include "incs/ft_printf.h"

int     main(void)
{
//     printf("[%i]\n", ft_printf("[%#.x]\n", 0));
//     printf("[%i]\n", printf("[%#.x]\n", 0));
//     printf("\n\n");

    // printf("[%i]\n", ft_printf("[%o]\n", 2500));
    // printf("[%i]\n", printf("[%o]\n", 2500));
    // printf("\n\n");
    char *i;

    i = ft_strdup("Hello\n");
    // printf("[%i]\n", ft_printf("[%21s][%s]\n", "Strings", "Some"));
    // printf("[%i]\n", printf("[%21s][%s]\n", "Strings", "Some"));
    // printf("\n\n");
    printf("[%i]\n", ft_printf("[%#p]\n", i));
    printf("[%i]\n", printf("[%#p]\n", i));
    printf("\n\n");
    free(i);

    // printf("[%i]\n", ft_printf("[%21.8s]\n", "Strings"));
    // printf("[%i]\n", printf("[%21.8s]\n", "Strings"));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%21.25s]\n", "Strings"));
    // printf("[%i]\n", printf("[%21.25s]\n", "Strings"));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%-21.25s]\n", "Strings"));
    // printf("[%i]\n", printf("[%-21.25s]\n", "Strings"));
    // printf("\n\n");
    // printf("[%i]\n", ft_printf("@moulitest: %#.o %#.0o", 0, 0));
    // printf("[%i]\n", printf("@moulitest: %#.o %#.0o", 0, 0));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("% d", 42));
    // printf("[%i]\n", printf("% d", 42));
    // printf("\n\n");


    // printf("[%i]\n", ft_printf("[%20.23s]\n", "Some String"));
    // printf("[%i]\n", printf("[%20.23s]\n", "Some String"));
    // printf("\n\n");

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
