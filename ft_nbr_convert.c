/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/12 16:55:34 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  int_len(signed long long value, int base, t_flags *flags)
{
    int                 ret;
    signed long long    val;

    val = (value < 0 && base == 10) ? value*-1 : (unsigned long long)value;
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

char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
    char            *ret;
    int             tmp;
    int             index;
    char            *min_width;

    ret = NULL;
    index = 0;
    min_width = ft_min_width_generator(flags);
    if (arg->specifier == 'd' || arg->specifier == 'i')
    {
        if (mod->mod == 0)
            ret = ft_itoa_base(va_arg(arg->arg, int), 10);
        if (mod->mod == 1)
            ret = ft_itoa_base((short)va_arg(arg->arg, int), 10);
        if (mod->mod == 2)
            ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 10);
        if (mod->mod == 3)
            ret = ft_litoa_base(va_arg(arg->arg, long), 10);
        if (mod->mod == 5)
            ret = ft_llitoa_base(va_arg(arg->arg, long long), 10); 
        ft_width_joiner(min_width, ret, flags, ft_strlen(ret));
    }
    if (arg->specifier == 'o') // # Flag not taken into account yet;
    {
        if (mod->mod == 0)
            ret = ft_itoa_base(va_arg(arg->arg, int), 8);
        if (mod->mod == 1)
            ret = ft_itoa_base((short)va_arg(arg->arg, int), 8);
        if (mod->mod == 2)
            ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 8);
        if (mod->mod == 3)
            ret = ft_litoa_base(va_arg(arg->arg, long), 8);
        if (mod->mod == 5)
            ret = ft_llitoa_base(va_arg(arg->arg, long long), 8);
        ft_width_joiner(min_width, ret, flags, ft_strlen(ret));
    }
    if (arg->specifier == 'u')
    {
        if (mod->mod == 0)
            ret = ft_itoa_base(va_arg(arg->arg, int), 10);
        if (mod->mod == 1)
            ret = ft_itoa_base((short)va_arg(arg->arg, int), 10);
        if (mod->mod == 2)
            ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 10);
        if (mod->mod == 3)
            ret = ft_litoa_base(va_arg(arg->arg, long), 10);
        if (mod->mod == 5)
            ret = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
        ft_width_joiner(min_width, ret, flags, ft_strlen(ret));
    }
    if (arg->specifier == 'x' || arg->specifier == 'X') // # Flag not taken into account yet;
    {
        if (mod->mod == 0)
            ret = ft_itoa_base(va_arg(arg->arg, int), 16);
        if (mod->mod == 1)
            ret = ft_itoa_base((short)va_arg(arg->arg, int), 16);
        if (mod->mod == 2)
            ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 16);
        if (mod->mod == 3)
            ret = ft_litoa_base(va_arg(arg->arg, long), 16);
        if (mod->mod == 5)
            ret = ft_llitoa_base(va_arg(arg->arg, long long), 16);
        if (arg->specifier == 'X')
            while (ret[index] != '\0')
            {
                ret[index] = ft_toupper(ret[index]);
                index++;
            }
        ft_width_joiner(min_width, ret, flags, ft_strlen(ret));
    }
    return (ret);
}