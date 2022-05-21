/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 10:34:34 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/*
    Initialises both structs
*/
static  void    ft_init_struct(t_flags *flags, t_modifier *modifier)
{
    modifier->mod = 0;
    flags->hash = 0;
    flags->zero = 0;
    flags->plus = 0;
    flags->minus = 0;
    flags->width = 0;
    flags->space = 0;
    flags->precision = -1;
}

/*
    Assigns the int value within modifier struct depending on the modifer
    and will return current index position.
*/
static int    ft_modifier_check(char *format, t_modifier *modifier, int i)
{
    if ((ft_strncmp(&format[i], "h", 1)) == 0)
        modifier->mod = 1;
    if ((ft_strncmp(&format[i], "hh", 2)) == 0)
        modifier->mod = 2;
    if ((ft_strncmp(&format[i], "l", 1)) == 0)
        modifier->mod = 3;
    if ((ft_strncmp(&format[i], "L", 1)) == 0)
        modifier->mod = 4;
    if ((ft_strncmp(&format[i], "ll", 2)) == 0)
        modifier->mod = 5;
    while (format[i] == 'l' || format[i] == 'h' || format[i] == 'L')
        i++;
    return (i);
}

/*
    If one of the flag characters is found, it increments the value in the struct
*/
static int  ft_flags_check(char *format, t_flags *flags, int i)
{
    i++;
    while(format[i] == '#' || format[i] == '0' || format[i] == '+' || format[i] == '-' || format[i] == ' ')
    {
        if (format[i] == '#')
            flags->hash++;
        if (format[i] == '0')
            flags->zero++;
        if (format[i] == '+')
            flags->plus++;
        if (format[i] == '-')
            flags->minus++;
        if (format[i] == ' ')
            flags->space++;
        i++;
    }
    while (format[i] >= '0' && format[i] <= '9')
        flags->width = flags->width * 10 + (format[i++] - '0');
    if (format[i] == '.') // default if . is found, then precision is 1. If there are digits after, then precision should be it
    {
        flags->precision++;
        while(format[++i] >= '0' && format[i] <= '9')
            flags->precision = flags->precision * 10 + (format[i] - '0');
    }
    return (i);
}

/*
    Initilizes the list
    Prints characters that are not %
    When % is encountered, ft_flag_check is called to collect all the flags and the specifier
*/
int ft_printf(char *format, ...)
{
    int         i;
    int         char_count;
    t_arg       arg[1];
    t_flags     flags[1];
    t_modifier  modifier[1];

    i = 0;
    char_count = 0;
    va_start(arg->arg, format);
    while(format[i] != '\0')
    {
        if (format[i] != '%')
        {
            char_count++;
            // printf("[%c]", format[i]);
            ft_putchar(format[i]);
        }
        else
        {
            ft_init_struct(flags, modifier);
            i = ft_flags_check(format, flags, i);
            i = ft_modifier_check(format, modifier, i);
            arg->specifier = format[i];
            char_count += ft_arg_filter(arg, flags, modifier);
        }
        i++;
    }
    va_end(arg->arg);
    return (char_count); // This will not be accurate
}
