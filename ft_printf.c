/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/05 23:03:49 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *str_char_specifier(char *str, t_struct *node)
{
    char    *ret;
    int     str_len;
    int     tot_len;

    if (str)
    {
        str_len = node->precision > 0 ? ft_strlen(str) : node->precision;
        printf("%i\n", str_len);
        tot_len = str_len < node->width ? node->width : str_len;
        ret = (char *)malloc(sizeof(char) * tot_len + 1);
        if (ret)
        {
            ret[tot_len] = '\0';
            while (tot_len >= 0)
                ret[tot_len--] = str_len < 0 ? ' ' : str[str_len--];
            return (ret);
        }
    }
    return (NULL);
}

void    ft_arg_conversion(va_list arg, t_struct *node)
{
    unsigned int        i;
    unsigned long long  y;
    char                *str;
    
    switch (node->specifier)
    {
        case 's' : str = va_arg(arg, char *);
            node->str = str_char_specifier(str, node);
            break;
        case 'c' : i = va_arg(arg, int);
            node->str = str_char_specifier((char *)&i, node);
            break;
    }
    if (node->str)
        ft_putstr(node->str);
    else
        ft_putstr("(null)");
    free(node->str);
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
    va_start(arg, format);
    while(format[node->pos] != '\0')
    {
        if (format[node->pos] != '%')
            ft_putchar(format[node->pos]);
        else
        {
            ft_flags_check(format, node);
            ft_arg_conversion(arg, node);
        }
            //ft_putstr(node.str);
            //free(node.str);
        node->pos++;
    }
    va_end(arg);
}

