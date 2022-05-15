#include "ft_printf.h"

int     main(void)
{
    ft_printf("Some string\n");
    printf("Some string\n");
    ft_printf("\n\n");

    ft_printf("%s\n", "Some String");
    printf("%s\n","Some string");
    ft_printf("\n\n");

    ft_printf("%s %s\n" ,"Some", "string");
    printf("%s %s\n" ,"Some", "string");
    ft_printf("\n\n");

    ft_printf("%c\n", 'v');
    printf("%c\n", 'v');
    ft_printf("\n\n");

    ft_printf("%23c\n", 'v');
    printf("%23c\n", 'v');
    ft_printf("\n\n");

    ft_printf("[%23.16s]\n", "Some string");
    printf("[%23.16s]\n", "Some string");
    ft_printf("\n\n");

    ft_printf("%-23s\n", "Some string");
    printf("%-23s\n", "Some string");
    ft_printf("\n\n");

    ft_printf("[%i]\n", 54236);
    printf("[%i]\n", 54236);
    ft_printf("\n\n");
    

    ft_printf("[%+15d]\n", 54236);
    printf("[%+15d]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%-15i]\n", 54236); // fix here
    printf("[%-15i]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%015i]\n", 54236);
    printf("[%015i]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%-15i]\n", 54236);
    printf("[%-15i]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%15.8i]\n", 54236);
    printf("[%15.8i]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%#23o]\n", 54236);
    printf("[%#23o]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%-15o]\n", 54236);
    printf("[%-15o]\n", 54236);
    ft_printf("\n\n");

    ft_printf("[%015o]\n", 54236);
    printf("[%015o]\n", 54236);
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%20.3s]\n", "home"));
    printf("[%i]\n", printf("[%20.3s]\n", "home"));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%15lo]\n", 1400000000000000000));
    printf("[%i]\n", printf("[%15lo]\n", 1400000000000000000));
    ft_printf("\n\n");

    ft_printf("[%%]\n");
    printf("[%%]\n");
    printf("\n\n");

    ft_printf("[%#X]\n", 5463); // fix here
    printf("[%#X]\n\n", 5463);
    printf("\n\n");

    ft_printf("[%20.12d]\n", 1676341);
    printf("[%20.12d]\n\n", 1676341);
    printf("\n\n");

    long long nbr;

    nbr = 2764182763812;

    printf("[%i]\n", ft_printf("[%lld]\n", nbr));
    printf("[%i]\n", printf("[%lld]\n", nbr));
    ft_printf("\n\n");

    float i;

    i = 4.26523141;
    ft_printf("[%f]\n", i);
    printf("[%f]\n", i);
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%.1f]\n", i));
    printf("[%i]\n", printf("[%.1f]\n", i));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%.0f]\n", i));
    printf("[%i]\n", printf("[%.0f]\n", i));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%f]\n", i));
    printf("[%i]\n", printf("[%f]\n", i));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%020.2f]\n", i));
    printf("[%i]\n", printf("[%020.2f]\n", i));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%020i]\n", 35)); 
    printf("[%i]\n", printf("[%020i]\n", 35));
    ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%+i]\n", 35)); 
    printf("[%i]\n", printf("[%+i]\n", 35));
    ft_printf("\n\n");

    return (0);
}
