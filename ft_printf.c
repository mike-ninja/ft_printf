/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/04/29 13:10:38 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdarg.h>

void ft_printf(char *format, ...)
{
    unsigned int    i; //this will contain the argument depending on the type; numbers like arguments and/or char
    char            *str; //same use as i, but for strings
    char            *traverse;
    va_list         arg; //va_list is a data type included from stdarg.h

    //Module 1: We need to initialise printf's arguments, with the help of stdarg, we can have an unlimited amount of variables.
    va_start(arg, format);
    traverse = format;
    while(traverse[0] != '\0')
    {
        while (traverse[0] != '%')
        {
            ft_putchar(traverse[0]);
            traverse++;
        }
        traverse++;
        //Module 2: Fetching and executing arguments
        switch(traverse[0])
        {
            case 'c' : i = va_arg(arg, int); // fetching char argument
                ft_putchar(i);
                break;
            case 'd' : i = va_arg(arg, int); // fetching decimal/integer argument
                if (i < 0)
                {
                    i = -i;
                    ft_putchar('-');
                }
                ft_putstr(ft_converter(i, 10));
                break;
            case 'o' : i = va_arg(arg, unsigned int); // fetching octal argument which is base 8
                ft_putstr(ft_converter(i, 8));
                break;
            case 's' : str = va_arg(arg, char *); // fetching string argument
                ft_putstr(str);
                break;
            case 'x' : i = va_arg(arg, unsigned int); // fetching hexadecimal representation
                ft_putstr(ft_converter(i, 16));
                break;
        }
    }
    //Module 3: Closing the argument list to necessary clean-up
    va_end(arg); }

char    *ft_converter(unsigned int  nbr, int base)
{
    char    *ret;
    // returns the string value of the number, might need itoa_base for this. 
}

int main(void)
{
    ft_printf("Hello my name is mike! %s hello\n", "mongrel");
    return (0);
}