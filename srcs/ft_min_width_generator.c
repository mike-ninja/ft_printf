/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_width_generator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:30:45 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/18 13:44:00 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// This needs to do more that just create min width.
/* 
char *flag_str_generator(t_flags *flags, int str_len)
{
	
}

*/
char	*ft_min_width_generator(t_flags *flags)
{
	int		i;
	char	*ret;

	if (flags->width > 0)
	{
		i = 0;
		ret = (char *)malloc(flags->width + 1);
		if (ret)
		{
			ret[flags->width] = '\0';
			while (i < flags->width)
			{
				if (flags->zero)
					ret[i++] = '0';
				else
					ret[i++] = ' ';
			}
			return (ret);
		}
	}
	return (NULL);
}
