/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/23 13:12:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static char	*second_percent(unsigned int c)
{
	char *ret;

	ret = NULL;
	if (c == '%')
		ret = ft_strdup("%");
	return (ret);
}

char	*ft_char_convert(unsigned int c, t_flags *flags)
{
	int		len;
	char	*ret;
	char	*width;

	width = ft_min_width_generator(flags);
	ret = second_percent(c);
	if (ret)
	{
		if (width)
			ft_width_joiner(width, ret, flags, 1);
		return (ret);
	}
	if (flags->width)
		len = flags->width;
	else
		len = 1;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret)
	{
		ret[len] = '\0';
		ret[0] = c;
		if (width)
			ft_width_joiner(width, ret, flags, 1);
		return (ret);
	}
	return (NULL);
}
