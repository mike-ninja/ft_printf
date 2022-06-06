/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:35:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/06 12:41:00 by mbarutel         ###   ########.fr       */
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
			break ;
		str++;
	}
	return (ret);
}

static int	sign_space_print(t_flags *flags, char *str, char specifier)
{
	int	ret;

	ret = 0;
	if (flags->plus && *str != '-')
		ret += write(1, "+", 1);
	if (*str == '-' && flags->zero)
		ret += write(1, "-", 1);
	if (flags->space && (!flags->plus && *str != '-'))
		ret += write(1, " ", 1);
	if (flags->hash)
	{
		if (*str != '0')
		{
			if (specifier == 'x')
				ret += write(1, "0x", 2);
			if (specifier == 'X')
				ret += write(1, "0X", 2);
		}
		if (specifier == 'o')
			if (*str != '0' || flags->precision >= 0)
				ret += write(1, "0", 1);
			
	}
	return (ret);
}

static int	di_width_printer(t_flags *flags, char *str, int len)
{
	int	tmp;
	int	ret;

	ret = 0;
	if (flags->precision >= len)
	{
		tmp = flags->width - flags->precision;
		if (*str == '-')
			tmp--;
	}
	else
		tmp = flags->width - len;
	if (flags->precision == 0 && *str == '0')
		tmp++;
	if (flags->space || (flags->plus && *str != '-'))
		tmp--;
	// if (*str == '-' && flags->precision > 0)
	// 	tmp--;
	while (--tmp >= 0)
	{
		if (flags->zero && flags->precision < len)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return (ret);
}

static int	str_printer(t_flags *flags, char *str, int len)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = flags->precision;
	if (*str == '-' && (flags->zero || flags->precision > len))
	{
		if (flags->precision > len && *str == '-')
			ret += write(1, "-", 1);
		str++;
		len--;
	}
	while (tmp-- > len)
		ret += write(1, "0", 1);
	while (*str != '\0')
	{
		if (flags->precision == 0 && *str == '0')
			break ;
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int	ft_diu_convert(char *str, t_flags *flags, char specifier)
{
	int	ret;
	int	len;

	ret = 0;
	len = ft_strlen(str);
	if (flags->minus)
	{
		ret += sign_space_print(flags, str, specifier);
		ret += str_printer(flags, str, len);
		ret += di_width_printer(flags, str, len);
	}
	else
	{
		if (flags->zero)
			ret += sign_space_print(flags, str, specifier);
		ret += di_width_printer(flags, str, len);
		if (!flags->zero)
			ret += sign_space_print(flags, str, specifier);
		ret += str_printer(flags, str, len);
	}
	return (ret);
}
