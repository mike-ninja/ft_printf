/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:19:03 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/27 12:32:46 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_bin_print(size_t nbr, int *ret)
{
	if (nbr > 1)
		ft_bin_print(nbr / 2, ret);
	else
		ret[0] += ft_printf("0");
	ret[0] += ft_printf("%i", nbr % 2);
}

void    non_printa_print(char val, int *ret)
{
    if (val == 9)
        *ret += write(1, "\\t", 2);
    if (val == 10)
        *ret += write(1, "\\n", 2);
    if (val == 11)
        *ret += write(1, "\\v", 2);    
    if (val == 12)
        *ret += write(1, "\\f", 2);  
}