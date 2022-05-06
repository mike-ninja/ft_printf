/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/06 11:57:01 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_arg_conversion(va_list arg, t_struct *node)
{
    signed int        i;
    unsigned long long  y;
    char                *str;
    
    switch (node->specifier)
    {
        case 's' : str = va_arg(arg, char *);
            node->str = str_char_specifier(str, node);
            break;
        case 'c' : i = va_arg(arg, unsigned int);
            node->str = str_char_specifier((char *)&i, node);
            break;
        case 'i' : i = va_arg(arg, unsigned int);
            node->str = nbr_specifier(i, 10);
            break;
        case 'd' : i = va_arg(arg, unsigned int);
            node->str = nbr_specifier(i, 10);
            break;
        case 'o' : i = va_arg(arg, unsigned int);
            node->str = nbr_specifier(i, 8);
            break;
        case 'x' : y = va_arg(arg, unsigned long long);
            node->str = ft_hex(i);
            break;
        case 'X' : y = va_arg(arg, unsigned long long);
            node->str = ft_hex(i);
            break;
    }
    // if (node->str)
    //     ft_putstr(node->str);
    // else
    //     ft_putstr("(null)");
    // //free(node->str);
    // node->str = NULL;
}

void    ft_flags_check(char *format, t_struct *node)
{
    node->pos++;
	node->hash = 0;
	node->zero = 0;
	node->plus = 0;
	node->minus = 0;
	node->width = 0;
	node->space = 0;
	node->percent = 0;
    node->precision = 0;

    while(format[node->pos] == '#' || format[node->pos] == '0' || format[node->pos] == '+' || format[node->pos] == '-' || format[node->pos] == ' ' || format[node->pos] == '%' || format[node->pos] == '.')
    {
        if (format[node->pos] == '#')
            node->hash++;
        if (format[node->pos] == '0')
            node->zero++;
        if (format[node->pos] == '+')
            node->plus++;
        if (format[node->pos] == '-')
            node->minus++;
        if (format[node->pos] == ' ')
            node->space++;
        if (format[node->pos] == '%')
            node->percent++;
        node->pos++;
    }
    while (format[node->pos] >= '0' && format[node->pos] <= '9')
        node->width = node->width * 10 + (format[node->pos++] - '0');
    if (format[node->pos] == '.')
    {
        while(format[++node->pos] >= '0' && format[node->pos] <= '9')
            node->precision = node->precision * 10 + (format[node->pos] - '0');
    }
    node->specifier = format[node->pos];
}

void    ft_printf(char *format, ...)
{
    va_list     arg;
    t_struct    node[1];

    node->pos = 0;
    node->str = NULL;
    va_start(arg, format);
    while(format[node->pos] != '\0')
    {
        if (format[node->pos] != '%')
            ft_putchar(format[node->pos]);
        else
        {
            ft_flags_check(format, node);
            ft_arg_conversion(arg, node);
            ft_putstr(node->str);
            //ft_strdel(&node->str);
        }
        node->pos++;
    }
    va_end(arg);
}

