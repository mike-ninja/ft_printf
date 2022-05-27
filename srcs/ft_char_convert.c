/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/23 13:12:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_char_convert(unsigned int c, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (c)
	{
		if (flags->minus)
			ret += write(1, &c, 1);
		if (flags->width)
			while (--flags->width > 0)
				ret += write(1, " ", 1);
		if (!flags->minus)
			ret += write(1, &c, 1);
	}
	else
	{
		if (flags->width)
			while (--flags->width > 0)
				ret += write(1, " ", 1);
		ret += write(1, "\0", 1);
	}
	return (ret);
}
