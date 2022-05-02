/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/02 10:09:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void ft_printf(char *format, ...)
// {
//     unsigned int    i; //this will contain the argument depending on the type; numbers like arguments and/or char
//     char            *str; //same use as i, but for strings
//     char            *traverse;
//     va_list         arg; //va_list is a data type included from stdarg.h

//     //Module 1: We need to initialise printf's arguments, with the help of stdarg, we can have an unlimited amount of variables.
//     va_start(arg, format);
//     traverse = format;
//     while(traverse[0] != '\0')
//     {
//         while (traverse[0] != '%')
//         {
//             ft_putchar(traverse[0]);
//             traverse++;
//         }
//         traverse++;
//         //Module 2: Fetching and executing arguments
//         switch(traverse[0])
//         {
//             case 'c' : i = va_arg(arg, int); // fetching char argument
//                 ft_putchar(i);
//                 break;
//             case 'd' : i = va_arg(arg, int); // fetching decimal/integer argument
//                 if (i < 0)
//                 {
//                     i = -i;
//                     ft_putchar('-');
//                 }
//                 ft_putstr(ft_converter(i, 10));
//                 break;
//             case 'o' : i = va_arg(arg, unsigned int); // fetching octal argument which is base 8
//                 ft_putstr(ft_converter(i, 8));
//                 break;
//             case 's' : str = va_arg(arg, char *); // fetching string argument
//                 ft_putstr(str);
//                 break;
//             case 'x' : i = va_arg(arg, unsigned int); // fetching hexadecimal representation
//                 ft_putstr(ft_converter(i, 16));
//                 break;
//         }
//     }
//     //Module 3: Closing the argument list to necessary clean-up
//     va_end(arg); }

#ifdef TEST             // To enable this block of code, compile with `-D TEST`
#include <stdio.h>
#include <limits.h>
int     main(void)
{
        int base;
        int test;

        printf("Base 10\n");
        base = 10;
        test = INT_MIN;
        printf("%s\n%d\n", ft_converter(test, base), test);
        test = -1;
        printf("%s\n%d\n", ft_converter(test, base), test);
        test = 0;
        printf("%s\n%d\n", ft_converter(test, base), test);
        test = 1;
        printf("%s\n%d\n", ft_converter(test, base), test);
        test = INT_MAX;
        printf("%s\n%d\n\n", ft_converter(test, base), test);

        printf("Base 8\n\n");        
        base = 8;
        test = 28;
        printf("ret %s\ncor %o\n", ft_converter(test, base), test);
        test = INT_MAX;
        printf("ret %s\ncor %o\n", ft_converter(test, base), test);


        printf("Base 16\n");
        base = 16;
        test = 0xABCDEF9;
        printf("%s\n%x\n\n", ft_converter(test, base), test);
        test = INT_MAX;
        printf("%s\n%x\n\n", ft_converter(test, base), test);
        test = INT_MIN;
        printf("%s\n%x\n\n", ft_converter(test, base), test);

        base = 9;
        test = -86872362;
        printf("%s\n\n", ft_converter(test, base));
        return (0);
}
#endif