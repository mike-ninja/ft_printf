/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/05 14:33:56 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *char_array(char *str, t_struct *node) // Maybe this should just return a string with the 0 or spaces and strjoin the arg? And this should be renamed, It's main function is to manage minimum width and (precision) not yet implemented
{
    char    *ret;
    int     str_len;
    int     tot_len;

    str_len = ft_strlen(str);
    tot_len = str_len < node->width ? node->width : str_len;
    ret = (char *)malloc(sizeof(char) * tot_len + 1);
    if (ret)
    {
        ret[tot_len] = '\0';
        while (tot_len >= 0)
            ret[tot_len--] = str_len < 0 ? ' ' : str[str_len--];
        // This space varies depending on the 0 flag.
        return (ret);
    }
    return (NULL);
}

void    ft_arg_conversion(va_list arg, t_struct *node)
{
    unsigned int    i;
    char            *str;
    
    switch (node->specifier)
    {
        case 's' : str = va_arg(arg, char *);
            node->str = char_array(str, node);
            ft_putstr(node->str);
            free(node->str);
            break;
        case 'c' : i = va_arg(arg, int);
            node->str = char_array((char *)&i, node);
            ft_putstr(node->str);
            free(node->str);
            break;
    }
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
    
    while(format[node->pos] == '#' || format[node->pos] == '0' || format[node->pos] == '+' || format[node->pos] == '-' || format[node->pos] == ' ' || format[node->pos] == '%')
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
    while (format[++node->pos] >= '0' && format[node->pos] <= '9')
        node->width = node->width * 10 + (format[node->pos] - '0');
    // What to do with width now? Should allocation of memory already happen? or check the len of the argument first, whichever is highest will be the memory size.
    // We make a collection of what kind of flags are here.
    node->specifier = format[node->pos];
    printf("specifier -> %c\n", node->specifier);
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
            //ft_putstr(node.str);
            //free(node.str);
        }
        node->pos++;
    }
    va_end(arg);
}
