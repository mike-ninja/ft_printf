/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:05 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/25 15:04:25 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printer(char *str, t_flags *flags)
{
	int	ret;
	// int	tmp; 
	
	ret = 0;
	// if (flags->precision)
	// 		tmp = ret;
	while (*str != '\0')
	{
		ret += write(1, str, 1);
		// if ((ret - tmp) == flags->precision)
		// 	break;
		if (ret == flags->precision)
			break;
		str++;
	}
	return (ret);
}

static int ft_nbr_printer(char *str, t_flags *flags, int len)
{
	int	ret;
	// int	tmp; 
	
	ret = 0;
	while (flags->precision > len++)
		ret += write(1, "0", 1);
	while (*str != '\0')
	{
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int	ft_nbr_convert(char *str, t_flags *flags)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	len = (int)ft_strlen(str);
	if (flags->minus)
		ret += ft_nbr_printer(str, flags, len);
	if (flags->width)
	{
		if (!flags->minus)
			tmp = len;
		else
			tmp = ret;
		if (flags->precision > len)
			tmp = flags->precision;
		while ((--flags->width - tmp) >= 0)
		{
			if (flags->zero && !flags->minus)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_nbr_printer(str, flags, len);
	return (ret);
}

	