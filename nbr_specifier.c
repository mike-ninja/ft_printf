/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:09:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/06 11:48:32 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char    *nbr_specifier(signed int value, int base)
{
    unsigned int    nbr;
    char            *ret;
    int             digits;
    
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
            ret[--digits] = ft_int_to_str(nbr, base);
            nbr /= base;
        }
        if (value < 0 && base == 10) ret[0] = '-';
        return (ret);
    }
    return (NULL);
}