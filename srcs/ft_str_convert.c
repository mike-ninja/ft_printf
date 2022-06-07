/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/07 12:51:56 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_str_convert(char *str, t_flags *flags)
{
	int		ret;
	int		tmp;
	int		len;

	ret = 0;
	tmp = 0;
	if (!str)
		str = ft_strdup("(null)");
	if (flags->minus)
		ret += ft_printer(str, flags);
	if (flags->width)
	{
		if (!flags->minus)
		{
			len = (int)ft_strlen(str);
			tmp = len;
			if (flags->precision >= 0)
			{
				if (flags->precision < len)
					tmp = flags->precision;
			}	
		}
		else
			tmp = ret;
		while ((--flags->width - tmp) >= 0)
		{
			if (flags->zero)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_printer(str, flags);
	return (ret);
}
