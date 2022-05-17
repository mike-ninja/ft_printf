/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 10:34:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*ft_char_convert(unsigned int c, t_flags *flags)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (flags->width)
		len = flags->width;
	else
		len = 1;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret)
	{
		ret[len] = '\0';
		while (i < len)
			ret[i++] = ' ';
		if (flags->minus)
			ret[0] = c;
		else
			ret[--len] = c;
		return (ret);
	}
	return (NULL);
}
