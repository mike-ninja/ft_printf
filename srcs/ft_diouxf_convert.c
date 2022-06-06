/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/06 12:16:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static char	*option_a(t_arg *arg, t_modifier *mod)
{
	char	*str;

	if (arg->specifier == 'd' || arg->specifier == 'i')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 10);
		if (mod->mod == 1)
			str = ft_itoa_base((short)va_arg(arg->arg, int), 10);
		if (mod->mod == 2)
			str = ft_itoa_base((signed char)va_arg(arg->arg, int), 10);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 10);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 10);
	}
	if (arg->specifier == 'u')
	{
		if (mod->mod == 0)
			str = ft_ullitoa_base(va_arg(arg->arg, unsigned int), 10);
		if (mod->mod == 1)
			str = ft_ullitoa_base((unsigned short)va_arg(arg->arg, int), 10);
		if (mod->mod == 2)
			str = ft_ullitoa_base((unsigned char)va_arg(arg->arg, int), 10);
		if (mod->mod == 3)
			str = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
		if (mod->mod == 5)
			str = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
	}
	return (str);
}

static char	*option_b(t_arg *arg, t_modifier *mod)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	if (arg->specifier == 'o')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 8);
		if (mod->mod == 1)
			str = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 8);
		if (mod->mod == 2)
			str = ft_itoa_base((unsigned char)va_arg(arg->arg, int), 8);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 8);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 8);
	}
	if (arg->specifier == 'x' || arg->specifier == 'X')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 16);
		if (mod->mod == 1)
			str = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 16);
		if (mod->mod == 2)
			str = ft_itoa_base((unsigned char)va_arg(arg->arg, int), 16);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 16);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 16);
		if (arg->specifier == 'X')
		{
			tmp = str;
			while (*tmp != '\0')
			{
				*tmp = ft_toupper(*tmp);
				tmp++;
			}
		}
	}
	return (str);
}

static char	*option_f(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	char	*str;

	str = NULL;
	if (arg->specifier == 'f')
	{
		if (flags->dot > 0 && flags->precision == 0)
			str = ft_itoa_base((int)va_arg(arg->arg, double), 10);
		else
		{
			if (mod->mod == 4)
				str = ft_lfloat(va_arg(arg->arg, long double), flags);
			else
				str = ft_float(va_arg(arg->arg, double), flags);
		}
	}
	return (str);
}

int	ft_diouxf_convert(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	int		ret;
	char	*str;

	ret = 0;
	if (arg->specifier == 'd' || arg->specifier == 'i' || arg->specifier == 'u')
		str = option_a(arg, mod);
	if (arg->specifier == 'o' || arg->specifier == 'x' || arg->specifier == 'X')
		str = option_b(arg, mod);
	if (arg->specifier == 'f')
		str = option_f(arg, flags, mod);
	if (str)
	{
		ret += ft_diu_convert(str, flags, arg->specifier);
		free(str);
	}
	return (ret);
}
