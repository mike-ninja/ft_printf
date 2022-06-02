#include "incs/ft_printf.h"
#include <limits.h>

// Float Check
int     main(void)
{
    // printf("[%i]\n", ft_printf("[%f]", 42.42));
    // printf("[%i]\n", printf("[%f]", 42.42));
    // printf("\n");
	printf("[%i]\n", ft_printf("[%f]", 2.3));
    printf("[%i]\n", printf("[%f]", 2.3));
    printf("\n");

    printf("[%i]\n", ft_printf("[%f]", 2.99999999));
    printf("[%i]\n", printf("[%f]", 2.99999999));
    printf("\n");

    printf("[%i]\n", ft_printf("[%f]", 2.36526382));
    printf("[%i]\n", printf("[%f]", 2.36526382));
    printf("\n");
	// printf("[%i]\n", ft_printf("%f\n", 2.5555545L));
    // printf("[%i]\n", printf("%f\n", 2.5555545L));
    //printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", -42.42));
    // printf("[%i]\n", printf("[%f]", -42.42));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 9.9999997));
    // printf("[%i]\n", printf("[%f]", 9.9999997));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 9.999999));
    // printf("[%i]\n", printf("[%f]", 9.9999999));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 9.9999999));
    // printf("[%i]\n", printf("[%f]", 9.9999999));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 3.55));
    // printf("[%i]\n", printf("[%f]", 3.55));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 3.55 / 1.5));
    // printf("[%i]\n", printf("[%f]", 3.55 / 1.5));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555505f));
    // printf("[%i]\n", printf("[%f]", 2.5555505f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555515f));
    // printf("[%i]\n", printf("[%f]", 2.5555515f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555525f));
    // printf("[%i]\n", printf("[%f]", 2.5555525f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555535f));
    // printf("[%i]\n", printf("[%f]", 2.5555535f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555545f));
    // printf("[%i]\n", printf("[%f]", 2.5555545f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555555f));
    // printf("[%i]\n", printf("[%f]", 2.5555555f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555565f));
    // printf("[%i]\n", printf("[%f]", 2.5555565f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555534f));
    // printf("[%i]\n", printf("[%f]", 2.5555534f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555544f));
    // printf("[%i]\n", printf("[%f]", 2.5555544f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555554f));
    // printf("[%i]\n", printf("[%f]", 2.5555554f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555564f));
    // printf("[%i]\n", printf("[%f]", 2.5555564f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555536f));
    // printf("[%i]\n", printf("[%f]", 2.5555536f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555546f));
    // printf("[%i]\n", printf("[%f]", 2.5555546f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555556f));
    // printf("[%i]\n", printf("[%f]", 2.5555556f));
    // printf("\n");
	// printf("[%i]\n", ft_printf("[%f]", 2.5555566f));
    // printf("[%i]\n", printf("[%f]", 2.5555566f));
    // printf("\n");
    return (0);
}

// Flags Check
// int     main(void)
// {
//     printf("\nTesting flag specifiers\n");
// 	printf("[%i]", ft_printf("Test #o flag: %#o\n", 42));
// 	printf("[%i]", ft_printf("Test ##o flag: %##o\n", 42));
// 	printf("[%i]", ft_printf("Test 0o flag: %0o\n", 42));
// 	printf("[%i]", ft_printf("Test #0o flag: %#0o\n", 42));
// 	printf("[%i]", ft_printf("Test #x flag: %#x\n", 42));
// 	printf("[%i]", ft_printf("Test #X flag: %#X\n", 42));
// 	printf("[%i]", ft_printf("Test #8d: %#8d", 42));
// 	printf("[%i]", ft_printf("Test #8o: %#8o", 42));
// 	printf("[%i]", ft_printf("Test #8x: %#8x", 42));
// 	printf("[%i]", ft_printf("Test #8X: %#8X", 42));
// 	printf("[%i]", ft_printf("Test #8.2o: %#8.2o", 42));
// 	printf("[%i]", ft_printf("Test #8.2x: %#8.2x", 42));
// 	printf("[%i]", ft_printf("Test #8.2X: %#8.2X", 42));
// 	printf("[%i]", ft_printf("Test #2.8o: %#2.8o", 42));
// 	printf("[%i]", ft_printf("Test #2.8x: %#2.8x", 42));
// 	printf("[%i]", ft_printf("Test #2.8X: %#2.8X", 42));
// 	printf("[%i]", ft_printf("Test #08d: %#08d", 42));
// 	printf("[%i]", ft_printf("Test #08o: %#08o", 42));
// 	printf("[%i]", ft_printf("Test #08x: %#08x", 42));
// 	printf("[%i]", ft_printf("Test #08X: %#08X", 42));
// 	printf("[%i]", ft_printf("Test #08.2o: %#08.2o", 42));
// 	printf("[%i]", ft_printf("Test #08.2x: %#08.2x", 42));
// 	printf("[%i]", ft_printf("Test #08.2X: %#08.2X", 42));
// 	printf("[%i]", ft_printf("Test #02.8o: %#02.8o", 42));
// 	printf("[%i]", ft_printf("Test #02.8x: %#02.8x", 42));
// 	printf("[%i]", ft_printf("Test #02.8X: %#02.8X", 42));
// 	printf("[%i]", ft_printf("Test #-08d: %#-08d", 42));
// 	printf("[%i]", ft_printf("Test #-08o: %#-08o", 42));
// 	printf("[%i]", ft_printf("Test #-08x: %#-08x", 42));
// 	printf("[%i]", ft_printf("Test #-08X: %#-08X", 42));
// 	specs_one_long("Test #llx: %#llx", 9223372036854775807));
// 	printf("[%i]", ft_printf("Test {+03d}: {%+03d}", 0));
// 	printf("[%i]", ft_printf("Test { 03d}: {% 03d}", 0));
// 	printf("[%i]", ft_printf("Test {0-3d}: {%0-3d}", 0));
// 	printf("[%i]", ft_printf("Test 03d: %03d", 0));
// 	printf("[%i]", ft_printf("Test 03i: %03i", 0));
//     return (0);
// }