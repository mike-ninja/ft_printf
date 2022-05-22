/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 10:40:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static char	*ft_address_convert(t_arg *arg, t_flags *flags)
{
	char	*ret;

	ret = NULL;
	ret = ft_strjoin("0x", ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 16));
	ft_width_joiner(ft_min_width_generator(flags), ret, flags, ft_strlen(ret));
	return (ret);
}

int	ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	char	*str;
	int		ret;
	int		c;

	ret = 0;
	str = NULL;
	if (arg->specifier == 'c')
	{
		c = va_arg(arg->arg, signed int);
		str = ft_char_convert(c, flags);
		if (!c)
			ret++;
	}
	if (arg->specifier == 's')
		str = ft_str_convert(va_arg(arg->arg, char *), flags);
	if (arg->specifier == 'p')
		str = ft_address_convert(arg, flags);
	if (arg->specifier == '%')
		str = ft_char_convert('%', flags);
	if (ft_strchr("diouxXf", arg->specifier))
		str = ft_nbr_converter(arg, flags, mod);
	if (str)
	{
		ft_putstr(str);
		ret += ft_strlen(str);
		free(str);
	}
	else
	{
		ft_putstr("\0");
		ret++;
	}
		
	return (ret);
}
