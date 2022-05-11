#include "ft_printf.h"

int     main(void)
{
    char    i;

    // ft_printf("Some string\n");
    // printf("Some string\n");
    // ft_printf("\n\n");

    // ft_printf("%s\n", "Some String");
    // printf("%s\n","Some string");
    // ft_printf("\n\n");

    // ft_printf("%s %s\n" ,"Some", "string");
    // printf("%s %s\n" ,"Some", "string");
    // ft_printf("\n\n");

    // ft_printf("%c\n", 'v');
    // printf("%c\n", 'v');
    // ft_printf("\n\n");

    // ft_printf("%23c\n", 'v');
    // printf("%23c\n", 'v');
    // ft_printf("\n\n");

    // ft_printf("[%23.16s]\n", "Some string");
    // printf("[%23.16s]\n", "Some string");
    // ft_printf("\n\n");

    // ft_printf("%-23s\n", "Some string");
    // printf("%-23s\n", "Some string");
    // ft_printf("\n\n");

    // ft_printf("[%i]\n", 54236);
    // printf("[%i]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%-+15i]\n", 54236);
    // printf("[%-+15i]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%015i]\n", 54236);
    // printf("[%015i]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%-15i]\n", 54236);
    // printf("[%-15i]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%15.8i]\n", 54236);
    // printf("[%15.8i]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%#23o]\n", 54236);
    // printf("[%#23o]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%-15o]\n", 54236);
    // printf("[%-15o]\n", 54236);
    // ft_printf("\n\n");

    // ft_printf("[%015o]\n", 54236);
    // printf("[%015o]\n", 54236);
    // ft_printf("\n\n");

    printf("[%i]\n", ft_printf("[%15c]\n", 'c'));
    printf("[%i]\n", printf("[%15c]\n", 'c'));
    ft_printf("\n\n");


    //ft_printf("[%20%]\n");
    //printf("[%#X]\n\n", 5463);
    //ft_printf("%20c\n", "string");
    //printf("%20c\n", "Some string");

    // ft_printf("[%20.12d]\n./c", 1676341);
    // printf("[%20.12d]\n\n", 1676341);

    return (0);
}