#include "ft_printf.h"

int     main(void)
{
    char    i;

    // No Argument Check
    //ft_printf("There are no arguments in this text\n");
    ft_printf("%20s\n", "String");
       

    // CSP checks
	// Unsigned Char Check
    // ft_printf("char check: %c\n", 'm');
    // printf("char check: %c\n", 'm');
	// String Check
	// ft_printf("%s", "This a a string argument\n");
    // printf("%s", "This a a string argument\n");
	// ft_printf("%s , %s", "This a a string argument", "2nd string argument\n\n");
    // printf("%s , %s", "This a a string argument", "2nd string argument\n\n");


	// Address Check
    // printf("%lld\n", (unsigned long long)&i);
    // //ft_printf("address - %p\n\n", &i);
    // printf("ft_hex - %s\n", ft_hex((unsigned long long)&i));
    // printf("address %p\n", &i);
    //ft_printf("address - %p, char %c\n\n", i, 'M');


    // Numbers Check
    //short int       i = 3;
    //printf("integer %d\n", i);
    //ft_printf("integer %d\n\n", i);
    //printf("octal   %o\n", 176);
    //ft_printf("octal   %c\n\n", 'a');
    //printf("integer %x\n", -78);
    //ft_printf("integer %x\n\n", -78);
    return (0);
}
