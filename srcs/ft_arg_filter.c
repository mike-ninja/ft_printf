/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/07 11:58:53 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// static int	ft_add_printer(char *str, t_flags *flags)
// {
// 	if (flags->width)
	
// }

static int	ft_address_convert(t_arg *arg, t_flags *flags)
{
	// char	*str;
	char	*hex;
	int		ret;

	// str = NULL;
	ret = 0;
	hex = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 16);
	// if (hex)
	// {
	// 	str = ft_strjoin("0x", hex);
	// 	free(hex);
	// }
	// if (flags->precision == 0 && *hex == '0')
	// {
	// 	ret += write(1, "0x", 2);
	// 	return (ret);
	// }
	ret += ft_diu_convert(hex, flags, 'p');
	return (ret);
}

int	ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	int		ret;

	ret = 0;
	if (arg->specifier)
	{
		if (arg->specifier == 'c')
			ret += ft_char_convert(va_arg(arg->arg, signed int), flags);
		if (arg->specifier == 's')
			ret += ft_str_convert(va_arg(arg->arg, char *), flags);
		if (arg->specifier == 'p')
			ret += ft_address_convert(arg, flags);
		if (arg->specifier == '%')
			ret += ft_char_convert('%', flags);
		if (ft_strchr("diouxXf", arg->specifier))
			ret += ft_diouxf_convert(arg, flags, mod);
	}
	return (ret);
}
