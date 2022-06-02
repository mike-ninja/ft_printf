/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:56:37 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/02 13:03:43 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

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

static void ft_banker_round(char *ret, double nbr)
{
    double tmp;
    int     index;

    tmp = nbr*10 - nbr;
    index = ft_strlen(ret);
    if (tmp >= 5)
    {
        while (ret[index-1] == '9' || ret[index-1] == '.')
        {   
            if (ret[index-1] == '.')
                index--;
            else
            {
                ret[index-1] = '0';
                index--;
            }
            
        }
        ret[index-1]++;
    }
}

char *ft_float(double nbr, t_flags *flags)
{
    char    *ret;
    char    *tmp;
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
        nbr = nbr - base;
        while (i < len)
        {
            nbr *= 10;
            base = nbr;
            nbr -= base;
            ret[i++] = base + '0';
        }
        tmp = ft_strjoin(first_part, ret);
        ft_banker_round(tmp, nbr);
        ft_strdel(&first_part);
        ft_strdel(&ret);
        return (tmp);
    }
    return (NULL);
}

char *ft_lfloat(long double nbr, t_flags *flags)
{
    char    *ret;
    char    *tmp;
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
        nbr = nbr - base;
        while (i < len)
        {
            nbr *= 10;
            base = nbr;
            nbr -= base;
            ret[i++] = base + '0';
        }
        tmp = ft_strjoin(first_part, ret);
        ft_banker_round(tmp, nbr);
        ft_strdel(&first_part);
        ft_strdel(&ret);
        return (tmp);
    }
    return (NULL);
}

// char *ft_float(double nbr, t_flags *flags)
// {
//    char *ret;

//    ret = 0;
   
//    return (ret)''
// }