/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 10:34:37 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*ft_str_convert(char *str, t_flags *flags)
{
	char	*ret;
	int		str_len;
	int		tot_len;

	if (str)
	{
		str_len = (int)ft_strlen(str);
		if (flags->precision > 0 && flags->precision < str_len)
			str_len = flags->precision;
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