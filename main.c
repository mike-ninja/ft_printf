#include "ft_printf.h"

int     main(void)
{
    char    i;

    // No Argument Check
    //ft_printf("There are no arguments in this text\n");
    ft_printf("ft %10c\n", 'c');
    printf("pr %10c\n", 'c');
       
    // Flags checks
    // ft_printf("Flags check: %#\n");
    // ft_printf("Flags check: %0\n");
    // ft_printf("Flags check: %+\n");
    // ft_printf("Flags check: %-\n");
    // ft_printf("Flags check: % \n");
    // ft_printf("Flags check: %%\n");
    // ft_printf("Width check: %20\n");

    return (0);
}
