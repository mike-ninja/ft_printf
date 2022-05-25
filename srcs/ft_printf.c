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
static char    *ft_modifier_check(char *format, t_modifier *modifier)
{
    if ((ft_strncmp(format, "h", 1) == 0))
        modifier->mod = 1;
    if ((ft_strncmp(format, "hh", 2) == 0))
        modifier->mod = 2;
    if ((ft_strncmp(format, "l", 1) == 0))
        modifier->mod = 3;
    if ((ft_strncmp(format, "L", 1) == 0))
        modifier->mod = 4;
    if ((ft_strncmp(format, "ll", 2) == 0))
        modifier->mod = 5;
    while (*format == 'l' || *format == 'h' || *format == 'L')
        format++;
    return (format);
}

/*
    If one of the flag characters is found, it increments the value in the struct
*/
static char  *ft_flags_check(char *format, t_flags *flags)
{
    format++;
    while(*format == '#' || *format == '0' || *format == '+' || *format == '-' || *format == ' ')
    {
        if (*format == '#')
            flags->hash++;
        if (*format == '0')
            flags->zero++;
        if (*format == '+')
            flags->plus++;
        if (*format == '-')
            flags->minus++;
        if (*format == ' ')
            flags->space++;
        format++;
    }
    while (*format >= '0' && *format <= '9')
    {
        flags->width = flags->width * 10 + (*format - '0');
        format++;
    }
    if (*format == '.') // default if . is found, then precision is 1. If there are digits after, then precision should be it
    {
        flags->precision++;
        format++;
        while(*format >= '0' && *format <= '9')
        {
            flags->precision = flags->precision * 10 + (*format - '0');
            format++;
        }
    }
    return (format);
}

/*
    Initilizes the list
    Prints characters that are not %
    When % is encountered, ft_flag_check is called to collect all the flags and the specifier
*/
int ft_printf(char *format, ...)
{
    int         char_count;
    t_arg       arg[1];
    t_flags     flags[1];
    t_modifier  modifier[1];

    char_count = 0;
    va_start(arg->arg, format);
    while(*format != '\0')
    {
        if (*format != '%')
            char_count += write(1, format, 1);
        else
        {
            ft_init_struct(flags, modifier);
            format = ft_flags_check(format, flags);
            format = ft_modifier_check(format, modifier);
            arg->specifier = *format;
            char_count += ft_arg_filter(arg, flags, modifier);
        }
        format++;
    }
    va_end(arg->arg);
    return (char_count); // This will not be accurate
}
