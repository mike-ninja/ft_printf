/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 09:37:17 by mbarutel         ###   ########.fr       */
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

static char *ft_float_base(int val)
{
    int     len;
    int     tmp;
    char    *ret;

    len = 1;
    tmp = val;
    while (tmp)
    {
        len++;
        tmp /= 10;
    }
    if (val == 0)
        len++;
    ret = (char *)malloc(len + 1);
    if (ret) // Fix Float precision problem
    {
        ret[len--] = '\0';
        ret[len--] = '.';
        if (val == 0)
            ret[len] = '0';
        while(val)
        {
            ret[len--] = (val % 10) + '0';
            val /= 10;
        }
        return (ret);
    }
    return (NULL);
}

static void ft_banker_round(char *ret, double nbr, int index)
{
    double tmp;

    tmp = (nbr - (int)nbr)*10;
    if (tmp >= 5)
        ret[--index]++;
}

static char *ft_float_convert(double nbr, t_flags *flags)
{
    char    *ret;
    char    *first_part;
    int     base;
    int     len;
    int     i;

    i = 0;
    ret = NULL;
    first_part = NULL;
    base = (int)nbr;
    first_part = ft_float_base(base);
    if (flags->precision > 0)
        len = flags->precision;
    else
        len = 6;
    ret = (char *)malloc(len + 1);
    if (ret)
    {
        ret[len] = '\0';
        nbr = nbr - (double)base;
        while (i < len)
        {
            nbr *= 10;
            base = (int)nbr;
            ret[i++] = (base % 10) + '0';
        }
        ft_banker_round(ret, nbr, i);
        return (ft_strjoin(first_part, ret));
    }
    return (NULL);
}

static char *plus_hash(t_flags *flags, char *str, char specifier)
{
    char *ret;

    ret = NULL;
    if (str)
    {
        if (specifier == 'i' || specifier == 'd')
            if (flags->plus)
                ret = ft_strjoin("+", str);
        if (specifier == 'o')
            if (flags->hash)
                ret = ft_strjoin("0", str);
        if (specifier == 'x')
            if (flags->hash)
                ret = ft_strjoin("0x", str);
        if (specifier == 'X')
            if (flags->hash)
                ret = ft_strjoin("0X", str);
        if (ret)
        {
            free(str);
            str = ret;
        }
    }
    return (str);
}

char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
    char            *ret;
    int             index;

    ret = NULL;
    index = 0;
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
    }
    if (arg->specifier == 'o')
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
    }
    if (arg->specifier == 'x' || arg->specifier == 'X')
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
    }
    ret = plus_hash(flags, ret, arg->specifier);
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
    }
    if (arg->specifier == 'f')
    {
        if (flags->dot > 0 && flags->precision == 0)
            ret = ft_itoa_base((int)va_arg(arg->arg, double), 10);
        else
            ret = ft_float_convert(va_arg(arg->arg, double), flags);
    }
    ft_width_joiner(ft_min_width_generator(flags), ret, flags, ft_strlen(ret));
    return (ret);
}