/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/08 19:41:09 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     ft_str_joiner(char *min_width, char *ret, t_struct *node)
{
    int i;
    int y;

    i = node->width;
    y = ft_strlen(ret);
    // if (!node->minus)
    //     while (y > 0 || node->precision > 0)
    //     {
    //         min_width[--i] = --y >= 0 ? ret[y] : 0 + '0';
    //         node->precision--;
    //     }
    // else
    while (y > 0 || node->precision > 0)
    {
        min_width[--i] = --y >= 0 ? ret[y] : 0 + '0';
        node->precision--;
    }
}

static char     *ft_min_width_generator(t_struct *node)
{
    int     i;
    char    *ret;
    
    if (node->width > 0)
    {
        i = 0;
        ret = (char *)malloc(node->width + 1);
        if (ret)
        {
            ret[node->width] = '\0';
            while (i < node->width)
                ret[i++] = node->zero > 0 && node->precision == 0 ? '0' : ' ';
            return (ret);
        }
    }
    return (NULL);
}

static char		ft_int_to_str(unsigned int nbr, int base)
{
    char    ret;

    switch (base)
    {
        case 10:
            ret = (nbr % 10) + '0';
            break;
        case 8:
            ret = (nbr % base) + '0';
            break;
    }
    return (ret);
}

// char    *ft_nbr_converter(signed int value, int base, t_struct *node)
// {
//     int             digits;
//     char            *ret;
//     char            *min_width;
//     unsigned int    nbr;

//     nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
//     digits = ((value < 0 && base == 10) || value == 0) ? 1 : 0;
//     while (nbr != 0)
//     {
//         digits++;
//         nbr /= base;
//     }
//     ret = (char *)malloc(digits + 1);
//     if (ret)
//     {
//         ret[digits] = '\0';
//         nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
//         while (digits > 0)
//         {
//             ret[--digits] = ft_int_to_str(nbr, base);
//             nbr /= base;
//         }
//         if (value < 0 && base == 10) ret[0] = '-';
//         if (digits < node->width)
//         {
//             min_width = ft_min_width_generator(node);
//             if (min_width)
//             {
//                 ft_str_joiner(min_width, ret, node);
//                 return (min_width);
//             }
//         }
//         return (ret);
//     }
//     return (NULL);
// }

static void ft_decimal_convert(unsigned int val, int len, t_struct *node, char *ret)
{
    char *min_width;
    int tmp;
    
    tmp = len;
    while (tmp > 0)
    {
        ret[--tmp] = (val % 10) + '0';
        val /= 10;
    }
    if (val < 0)
        ret[0] = '-';
    if (len < node->width)
    {
        min_width = ft_min_width_generator(node);
        if (min_width)
        {
            printf("This happens\nlen %i %i\n", len, node->width);
            ft_str_joiner(min_width, ret, node);
        }
            
    }
}

static void ft_octal_convert(unsigned int val, int len, t_struct *node, char *ret)
{
    char *min_width;
    
    while (len > 0)
    {
        ret[--len] = (val % 8) + '0';
        val /= 8;
    }
    if (len < node->width)
    {
        min_width = ft_min_width_generator(node);
        if (min_width)
            ft_str_joiner(min_width, ret, node);
    }
}

static int  int_len(signed int value, int base, t_struct *node)
{
    int ret;
    int val;

    val = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
    ret = ((value < 0 && base == 10) || value == 0 || (base == 10 && node->plus > 0)) ? 1 : 0;
    while (val != 0)
    {
        ret++;
        val /= base;
    }
    return (ret);
}

char    *ft_nbr_converter(signed int value, int base, t_struct *node)
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
        // ret[len] = '\0';
        // nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
        // while (len > 0)
        // {
        //     ret[--len] = ft_int_to_str(nbr, base);
        //     nbr /= base;
        // }
        // if (value < 0 && base == 10) ret[0] = '-';
        // if (len < node->width)
        // {
        //     min_width = ft_min_width_generator(node);
        //     if (min_width)
        //     {
        //         ft_str_joiner(min_width, ret, node);
        //         return (min_width);
        //     }
        // }
        // return (ret);
    }
    return (NULL);
}