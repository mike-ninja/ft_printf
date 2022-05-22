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

	ret = second_percent(c);
	if (ret)
		return (ret);
	if (flags->width)
		len = flags->width;
	else
		len = 1;
	width = ft_min_width_generator(flags);
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
