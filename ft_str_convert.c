/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/10 13:05:53 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_convert(char *str, t_flags *flags)
{
	char	*ret;
	int		str_len;
	int		tot_len;

	if (str)
	{
		str_len = flags->precision > 0 && flags->precision < ft_strlen(str) ? flags->precision : ft_strlen(str);
		tot_len = str_len < flags->width ? flags->width : str_len;
		ret = (char *)malloc(sizeof(char) * tot_len + 1);
		if (ret)
		{
			ret[tot_len] = '\0';
			if (!flags->minus)
				while (tot_len > 0)
					ret[--tot_len] = str_len <= 0 ? ' ' : str[--str_len];
			else
			{
				while (str_len)
				{
					tot_len--;
					ret[tot_len] = str_len <=tot_len ? ' ' : str[--str_len];
				}   
			}       
			return (ret);
		}
	}
	return (NULL);
}