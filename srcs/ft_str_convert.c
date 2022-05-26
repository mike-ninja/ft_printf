/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/25 13:49:58 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// char	*ft_str_convert(char *str, t_flags *flags)
// {
// 	char	*ret;
// 	char	*width;
// 	int		str_len;
// 	int		tmp;
// 	int		int_ret;

// 	int_ret = 0;
// 	ret = NULL;
// 	if (str)
// 	{
// 		width = ft_min_width_generator(flags);
// 		str_len = (int)ft_strlen(str);
// 		if (flags->precision > 0 && flags->precision < str_len)
// 			str_len = flags->precision;
// 		tmp = str_len;
// 		ret = (char *)malloc(sizeof(char) * str_len + 1);
// 		if (ret)
// 		{
// 			ret[str_len] = '\0';
// 			while (str_len--)
// 				ret[str_len] = str[str_len];
// 			if (width)
// 				ft_width_joiner(width, ret, flags, tmp);
// 		}
// 	}
// 	else
// 		ret = ft_strdup("(null)");
// 	return (ret);
// 


int	ft_str_convert(char *str, t_flags *flags)
{
	int		ret;
	int		tmp;
	int		len;

	ret = 0;
	if (str)
	{
		if (flags->minus)
			ret += ft_printer(str, flags);
		if (flags->width)
		{
			if (!flags->minus)
			{
				len = (int)ft_strlen(str);
				
				if (flags->precision > 0 && flags->precision < len)
					tmp = len - flags->precision;
				else
					tmp = len;
			}
			else
				tmp = ret;
			// printf("[%i]\n", tmp);
			while ((--flags->width - tmp) >= 0)
				ret += write(1, " ", 1);
		}
		if (!flags->minus)
			ret += ft_printer(str, flags);
	}
	else
		ret += write(1, "(null)", 6);
	return (ret);
}


	