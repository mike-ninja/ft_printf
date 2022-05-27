/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/25 14:59:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_address_convert(t_arg *arg, t_flags *flags)
{
	char	*str;
	char	*hex;

	str = NULL;
	hex = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 16);
	if (hex)
	{
		str = ft_strjoin("0x", hex);
		free(hex);
	}
	return (ft_str_convert(str, flags));
}

int	ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	int		ret;

	ret = 0;
	if (arg->specifier == 'c')
		ret += ft_char_convert(va_arg(arg->arg, signed int), flags);
	if (arg->specifier == 's')
		ret += ft_str_convert(va_arg(arg->arg, char *), flags);
	if (arg->specifier == 'p')
		ret += ft_address_convert(arg, flags);
	if (arg->specifier == '%')
		ret += write(1, "%", 1);
	if (ft_strchr("diouxXf", arg->specifier))
		ret += ft_diouxf_filter(arg, flags, mod);
	return (ret);
}
