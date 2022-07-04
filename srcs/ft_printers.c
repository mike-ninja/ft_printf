/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:35:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/04 12:15:08 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printer(char *str, t_flags *flags)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		if (ret == flags->precision)
			break ;
		ret += write(1, str, 1);
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
			ret += write(1, "0", 1);
			// if (*str != '0' || flags->precision >= 0)
			// {
			// 	ft_printf("This happens\n");
				// ret += write(1, "0", 1);
			// }
				
	}
	if (specifier == 'p')
		ret += write(1, "0x", 2);
	return (ret);
}

static int	di_width_printer(t_flags *flags, char *str, int len, char speci)
{
	int	tmp;
	int	ret;

	ret = 0;
	if (ft_strchr("xX", speci) && *str != '0') // This does nothing, delete when needed
		len += 0; 
	tmp = flags->width - len;
	if (flags->precision >= len)
	{
		tmp = flags->width - flags->precision;
		if (*str == '-')
			tmp--;
	}
	if (flags->precision == 0 && *str == '0')
		tmp++;
	if ((flags->space || flags->plus) && *str != '-')
		tmp--;
	while (--tmp >= 0)
	{
		if (flags->zero && flags->precision < len)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return (ret);
}

static int	str_printer(t_flags *flags, char *str, int len, char speci)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = flags->precision;
	if (*str == '-' && (flags->zero || flags->precision >= len))
	{
		if (flags->precision >= len && *str == '-')
			ret += write(1, "-", 1);
		str++;
		len--;
	}
	if (flags->hash && speci == 'o')
		tmp+= 0; // This does nothing, delete when needed
	while (tmp-- > len)
		ret += write(1, "0", 1);
	while (*str != '\0')
	{
		if (flags->precision == 0 && *str == '0' && speci != 'f')
			break ;
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int	ft_diouxf_printer(char *str, t_flags *flags, char specifier)
{
	int	ret;
	int	len;

	ret = 0;
	len = ft_strlen(str);
	flags_correction(str, flags, specifier);
	if (flags->minus)
	{
		ret += sign_space_print(flags, str, specifier);
		ret += str_printer(flags, str, len, specifier);
		ret += di_width_printer(flags, str, len, specifier);
	}
	else
	{
		if (flags->zero)
			ret += sign_space_print(flags, str, specifier);
		ret += di_width_printer(flags, str, len, specifier);
		if (!flags->zero)
			ret += sign_space_print(flags, str, specifier);
		ret += str_printer(flags, str, len, specifier);
	}
	return (ret);
}
