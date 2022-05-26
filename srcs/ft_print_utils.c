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
	ret = 0;
	while (*str != '\0')
	{
		ret += write(1, str, 1);
		if (ret == flags->precision)
			break;
		str++;
	}
	return (ret);
}

int ft_diu_printer(char *str, t_flags *flags, int len)
{
	int	ret;
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

int ft_x_printer(char *str, t_flags *flags, int len, char speci)
{
	int	ret;
	ret = 0;
	if (flags->hash)
	{
		if (speci == 'X')
			ret += write(1, "0X", 2);
		else
			ret += write(1, "0x", 2);
	}
	while (flags->precision > len++)
		ret += write(1, "0", 1);
	while (*str != '\0')
	{
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int ft_o_printer(char *str, t_flags *flags, int len)
{
	int	ret;
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

int ft_f_printer(char *str, t_flags *flags, int len)
{
	int	ret;
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
	