#include "incs/ft_printf.h"
#include <limits.h>

int     main(void)
{
//     printf("[%i]\n", ft_printf("[%#.x]\n", 0));
//     printf("[%i]\n", printf("[%#.x]\n", 0));
//     printf("\n\n");

    // printf("[%i]\n", ft_printf("[%o]\n", 2500));
    // printf("[%i]\n", printf("[%o]\n", 2500));
    // printf("\n\n");
    // char *i;

    // i = ft_strdup("Hello\n");
    // printf("[%i]\n", ft_printf("[%21s][%s]\n", "Strings", "Some"));
    // printf("[%i]\n", printf("[%21s][%s]\n", "Strings", "Some"));
    // printf("\n\n");
    //printf("[%i]\n", ft_printf("[%-#23X]", 42));
    //printf("[%i]\n", printf("[%-#23X]", 42));
    //printf("\n\n");

    // printf("[%i]\n", ft_printf("%-05d", -42));
    // printf("[%i]\n", printf("%-05d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%10.5d", 4242));
    // printf("[%i]\n", printf("%10.5d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%-10.5d", 4242));
    // printf("[%i]\n", printf("%-10.5d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("% 10.5d", 4242));
    // printf("[%i]\n", printf("% 10.5d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%+10d", 4242));
    // printf("[%i]\n", printf("%+10d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%-+10d", 4242));
    // printf("[%i]\n", printf("%-+10d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%-+10.5d", 4242));
    // printf("[%i]\n", printf("%-+10.5d", 4242));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%0+5d", -42));
    // printf("[%i]\n", printf("%0+5d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%+05d", 42));
    // printf("[%i]\n", printf("%+05d", 42));
    // printf("\n\n");
    
    // printf("[%i]\n", ft_printf("%03.2d", 1));
    // printf("[%i]\n", printf("%03.2d", 1));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%03.2d", -1));
    // printf("[%i]\n", printf("%03.2d", -1));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%04.6d", -1));
    // printf("[%i]\n", printf("%04.6d", -1));
    // printf("\n\n");


    // printf("[%i]\n", ft_printf("%10.5d", -42));
    // printf("[%i]\n", printf("%10.5d", -42));
    // printf("\n\n");


    // printf("[%i]\n", ft_printf("%10.5d", 42));
    // printf("[%i]\n", printf("%10.5d", 42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("% d", -42));
    // printf("[%i]\n", printf("% d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%5d", -42));
    // printf("[%i]\n", printf("%5d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%05d", -42));
    // printf("[%i]\n", printf("%05d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%0+5d", -42));
    // printf("[%i]\n", printf("%0+5d", -42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("@moulitest: %.d %.0d", 1, 1));
    // printf("[%i]\n", printf("@moulitest: %.d %.0d", 1, 1));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%5.d] [%5.0d]", 0, 0));
    // printf("[%i]\n", printf("[%5.d] [%5.0d]", 0, 0));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("norm:%ld\n", 2147483648));
    // printf("[%i]\n", printf("norm:%ld\n", 2147483648));
    // printf("\n\n");

    printf("[%i]\n", ft_printf("%lld", -9223372036854775808));
    printf("[%i]\n", printf("%lld", -9223372036854775808));
    printf("\n\n");

    printf("[%s]\n", ft_llitoa_base(-9223372036854775808, 10));

    // printf("[%i]\n", ft_printf("%5%"));
    // printf("[%i]\n", printf("%5%"));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%u", -1));
    // printf("[%i]\n", printf("%u", -1));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%5u", 4294967295));
    // printf("[%i]\n", printf("%5u", 4294967295));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("%5u", 4294967295));
    // printf("[%i]\n", printf("%5u", 4294967295));
    // printf("\n\n");

    // free(i);

    // printf("[%i]\n", ft_printf("[%21.8s]\n", "Strings"));
    // printf("[%i]\n", printf("[%21.8s]\n", "Strings"));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%21.25s]\n", "Strings"));
    // printf("[%i]\n", printf("[%21.25s]\n", "Strings"));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf("[%-21.25s]\n", "Strings"));
    // printf("[%i]\n", printf("[%-21.25s]\n", "Strings"));
    // printf("\n\n");
    // printf("[%i]\n", ft_printf(% +d", 42));
    // printf("[%i]\n", printf(% +d", 42));
    // printf("\n\n");

    // printf("[%i]\n", ft_printf(% +d", 42));
    // printf("[%i]\n", printf(% +d", 42));
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
