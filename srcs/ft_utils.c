/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:10:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/05 15:40:58 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void flags_correction(t_flags *flags, char specifier)
{
	char	c;

	c = specifier;
	if (flags->minus)
		flags->zero = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		flags->hash = 0;
	if (flags->hash)
	{
		if (specifier == 'x' || specifier == 'X')
			flags->width -= 2;
		if (specifier == 'o')
			flags->width--;	
	}
	if (specifier == 'u')
	{
		flags->space = 0;
		flags->plus = 0;	
	}
}