/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:59:52 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/04 12:20:27 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:09:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/03 11:02:30 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_hex_char(unsigned long long nbr)
{
	if (nbr >= 0 && nbr <= 9)
		return (nbr + '0');
    return ('a' + (nbr - 10));
}

char    *ft_hex(unsigned long long value)
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
            ret[--digits] = ft_hex_char(nbr % 16);
            nbr /= 16;
		}
        return (ret);
    }
    return (NULL);
}
