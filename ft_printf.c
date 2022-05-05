/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:56:15 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/05 13:00:32 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *char_array(char *str, t_struct *node)
{
    char    *ret;
    int     str_len;
    int     tot_len;

    str_len = ft_strlen(str);
    if (str_len < node->min_len)
    {
        tot_len = str_len + node->min_len;
        ret = (char *)malloc(sizeof(char) * tot_len + 1);
        if (!ret)
            return (NULL);
       ret[tot_len] = '\0';
        while (tot_len >= 0)
            ret[--tot_len] = str_len >= 0 ? str[--str_len] : ' '; // This space varies depending on the 0 flag.
    }
    else
    {
        ret = (char *)malloc(sizeof(char) * (str_len + 1));
        if (!ret)
            return (NULL);
        ret[str_len] = '\0';
        while (--str_len >= 0)
            ret[str_len] = str_len >= 0 ? str[str_len] : ' '; // This space varies depending on the 0 flag.
    }
    printf("This happens %s\n", ret);
    return (ret);
    // Think about how to memory allocate here since there is no return value
}

void    ft_arg_conversion(va_list arg, t_struct *node)
{
    unsigned int    i;
    char            *str;
    
    // switch (node.arg)
    // {
    //     case 's' : str = va_arg(arg, char *);
    //         printf("This happens\n");
    //         node.str = char_array(str, node);
    //         ft_putstr(node.str);
    //         free(node.str);
    //         break;
    // }
    if (node->arg == 's')
    {
        str = va_arg(arg, char *);
        node->str = char_array(str, node);
        ft_putstr(node->str);
        free(node->str);
    }
}

void    ft_flags_check(char *format, t_struct *node)
{
    /*
    Check for flags:
    - Check for an integer for minimum field width
    */
    node->pos++;
    node->min_len = 0;
    while (format[node->pos] >= '0' && format[node->pos] <= '9')
    {
        node->min_len = node->min_len * 10 + (format[node->pos] - '0');
        node->pos++;
    }
    // What to do with min_len now? Should allocation of memory already happen? or check the len of the argument first, whichever is highest will be the memory size.
    // We make a collection of what kind of flags are here.
    node->arg = format[node->pos];
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
