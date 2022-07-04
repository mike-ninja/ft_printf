#include "incs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int     main(void)
{
    int ret;
    ret = printf("%.14f\n", 4.99499999f);
    printf("[%d]\n", ret);
    ret = ft_printf("%.14f\n", 4.99499999f);
    printf("[%d]\n", ret);
    printf("\n");
    return (0);
}