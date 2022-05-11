/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/10 13:12:04 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_decimal_convert(unsigned int val, int len, t_struct *node, char *ret)
{
    char    *min_width;
    int     tmp;
    
    tmp = len;
    min_width = NULL;
    while (tmp > 0)
    {
        ret[--tmp] = (val % 10) + '0';
        val /= 10;
    }
    if (val < 0 || node->plus)
    {
        if (val < 0)
            ret[0] = '-';
        else
            ret[0] = '+';
    }
    if (len < node->width)
    {
        min_width = ft_min_width_generator(node);
        if (min_width)
            ft_width_joiner(min_width, ret, node, len);
    }
}

static void ft_octal_convert(unsigned int val, int len, t_struct *node, char *ret)
{
    char    *min_width;
    int     tmp;
    
    tmp = len;
    min_width = NULL;
    while (tmp > 0)
    {
        ret[--tmp] = (val % 8) + '0';
        val /= 8;
    }
    if (len < node->width)
    {
        min_width = ft_min_width_generator(node);
        if (min_width)
            ft_width_joiner(min_width, ret, node, len);
    }
}

static int  int_len(signed int value, int base, t_struct *node)
{
    int ret;
    int val;

    val = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
    ret = ((value < 0 && base == 10) || value == 0 || (base == 10 && node->plus > 0) || (base != 10 && node->hash > 0)) ? 1 : 0;
    while (val != 0)
    {
        ret++;
        val /= base;
    }
    return (ret);
}

// char    *ft_nbr_converter(signed int value, int base, t_struct *node)
// {
//     int             len;
//     char            *ret;
//     unsigned int    nbr;

//     len = int_len(value, base, node);
//     ret = (char *)malloc(len + 1);
//     if (ret)
//     {
//         ret[len] = '\0';
//         nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
//         switch (base)
//         {
//             case 10 :
//                 ft_decimal_convert(nbr, len, node, ret);
//                 break;
//             case 8 :
//                 ft_octal_convert(nbr, len, node, ret);
//                 break;
//         }
//         return (ret);
//     }
//     return (NULL);
// }

char    *ft_nbr_converter(va_list arg, t_flags *flags, t_modifier *mod, int base)
{
    int             len;
    char            *ret;
    unsigned int    nbr;

    len = int_len(value, base, node);
    ret = (char *)malloc(len + 1);
    if (ret)
    {
        ret[len] = '\0';
        nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
        switch (base)
        {
            case 10 :
                ft_decimal_convert(nbr, len, node, ret);
                break;
            case 8 :
                ft_octal_convert(nbr, len, node, ret);
                break;
        }
        return (ret);
    }
    return (NULL);
}