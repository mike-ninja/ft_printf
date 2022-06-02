/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:56:37 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/02 11:08:49 by mbarutel         ###   ########.fr       */
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

static void ft_banker_round(char *ret, double nbr, int index)
{
    double tmp;

    // printf("[%s]\n", ret);
    // printf("[%f]\n", nbr);
    //printf("[%s]\n", ret);
    tmp = (nbr - (int)nbr)*10;
    // printf("[%f]\n", tmp);
    // printf("[%f]\n", tmp);
    if (tmp >= 5)
    {
        //printf("[%c][%i]\n", ret[index], index);
        ret[--index]++;
        //printf("[%c][%i]\n", ret[index], index);
    }
        
}

// static int ft_banker_round(char *ret, double nbr, int index)
// {
//     while (*ret != '\0')
//     {
        
//     }
        
// }


// float my_float = 42.8f;
// int my_int;
// my_int = FLOAT_TO_INT(my_float); // => my_int=43

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
        nbr = nbr - (double)base;
        while (i < len)
        {
            nbr *= 10;
            base = nbr;
            printf("[%i]\n", (int)nbr*10);
            //printf("[%f]\n", nbr % (double)10);
            ret[i++] = (base % 10) + '0';
            //printf("[%c]\n", (base % 10) + '0');
        }
        
        ft_banker_round(ret, nbr, i);
        tmp = ft_strjoin(first_part, ret);
        ft_strdel(&first_part);
        ft_strdel(&ret);
        return (tmp);
    }
    return (NULL);
}
