/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:09:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/02 10:19:33 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char    ft_hexter(unsigned int nbr, int base)
{
    char    ret;
    //int     tmp;
    char    str[16] = "0123456789abcdef";

    switch (base)
    {
        case 10:
            ret = (nbr % 10) + '0';
            break;
        case 8:
            ret = (nbr % base) + '0';
            break;
        case 16:
            //tmp = nbr % base;
            // if (tmp >= 0 && tmp <= 9)
            //     ret = tmp + '0';
            // if (tmp >= 10 && tmp <= 16)
            //     ret = (tmp - 10) + 'a';
            ret = str[nbr % base];
            break;
    }
    return (ret);
}

char    *ft_converter(int value, int base)
{
    int             digits;
    char            *ret;
    unsigned int    nbr;
    
    nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
    digits = ((value < 0 && base == 10) || value == 0) ? 1 : 0;
    while (nbr != 0)
    {
        digits++;
        nbr /= base;
    }
    ret = (char *)malloc(digits + 1);
    if (ret)
    {
        ret[digits] = '\0';
        nbr = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
        while (digits >= 0)
        {
            ret[--digits] = ft_hexter(nbr, base);
            nbr /= base;
        }
        if (value < 0 && base == 10) ret[0] = '-';
        return (ret);
    }
    return (NULL);
}
