/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:59:52 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/09 14:57:09 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_hex_char(unsigned long long nbr, char specifier)
{
    char    ret;
    
	if (nbr >= 0 && nbr <= 9)
		ret = nbr + '0';
    else
        if (specifier == 'x')
            ret = 'a' + (nbr - 10);
        else
            ret = 'A' + (nbr - 10);
    return (ret);
}

char    *ft_hex_convert(unsigned long long value, char specifier, t_struct *node)
{
    int             digits;
    char            *ret;
    unsigned long long    nbr;
    
    nbr = value;
    digits = 0;
    while (nbr > 0)
    {
        digits++;
        nbr /= 16;
    }
    ret = (char *)malloc(digits + 1);
    if (ret)
    {
        ret[digits] = '\0';
        nbr = value;
        while (digits >= 0)
        {
            ret[--digits] = ft_hex_char(nbr % 16, specifier);
            nbr /= 16;
		}
        return (ret);
    }
    return (NULL);
}
