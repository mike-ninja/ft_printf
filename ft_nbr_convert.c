/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/11 13:10:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  int_len(signed long long value, int base, t_flags *flags)
{
    int ret;
    int val;

    val = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
    ret = ((value < 0 && base == 10) || value == 0 || (base == 10 && flags->plus > 0) || (base != 10 && flags->hash > 0)) ? 1 : 0;
    while (val != 0)
    {
        ret++;
        val /= base;
    }
    return (ret);
}

char *ft_decimal_convert(signed long long val, t_flags *flags)
{
    char    *min_width;
    char    *ret;
    int     tmp;
    int     len;
    
    len = int_len(val, 10, flags);
    ret = (char *)malloc(len + 1);
    if (ret)
    {
        tmp = len;
        ret[len] = '\0';
        min_width = NULL;
        while (tmp > 0)
        {
            ret[--tmp] = (val % 10) + '0';
            val /= 10;
        }
        if (val < 0 || flags->plus)
        {
            if (val < 0)
                ret[0] = '-';
            else
                ret[0] = '+';
        }
        if (len < flags->width)
        {
            min_width = ft_min_width_generator(flags);
            if (min_width)
                ft_width_joiner(min_width, ret, flags, len);
        }
        return (ret);
    }
    return (NULL);
}

// static void ft_octal_convert(unsigned int val, int len, t_struct *node, char *ret)
// {
//     char    *min_width;
//     int     tmp;
    
//     tmp = len;
//     min_width = NULL;
//     while (tmp > 0)
//     {
//         ret[--tmp] = (val % 8) + '0';
//         val /= 8;
//     }
//     if (len < node->width)
//     {
//         min_width = ft_min_width_generator(node);
//         if (min_width)
//             ft_width_joiner(min_width, ret, node, len);
//     }
// }



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

char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
    char            *ret;
    signed int      val;

    ret = NULL;
    if (arg->specifier == 'd' || arg->specifier == 'i')
    {
        switch (mod->mod)
        {
            case 0 :
                ret = ft_decimal_convert(va_arg(arg->arg, signed int), flags);
                break;
            // case 1 :
            //     ret = ft_decimal_convert(va_arg(arg->arg, short int), flags);
            //     break;
            case 3:
                ret = ft_decimal_convert(va_arg(arg->arg, long signed int), flags);
        }
    }
    return (ret);
    // switch (mod->mod)
    // {
    //     // case 0:
    //     //     function(va_arg(arg->arg, signed int), arg->specifier, flags);
    //     //     break;
    //     // case 1 :
    //     //     function(va_arg(arg->arg, short int), arg->specifier, flags);
    //     //     break;
    //     // case 2 :
    //     //     function(va_arg(arg->arg, short short int), arg->specifier, flags);
    //     //     break;
    //     // case 3 : 
    //     //     function(va_arg(arg->arg, long int), arg->specifier, flags);
    //     //     break;
    //     // case 4 :
    //     //     function(va_arg(arg->arg, long long int), arg->specifier, flags);
    //     //     break;
    //     // case 5 :
    //     //     function(va_arg(arg->arg, long double), arg->specifier, flags);
    //     //     break;
    // }

    // return (ret);
}