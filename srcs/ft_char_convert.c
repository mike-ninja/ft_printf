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

// static char	*second_percent(unsigned int c)
// {
// 	char *ret;

// 	ret = NULL;
// 	// printf("This happens [%c]\n", c);
// 	if (c == '%')
// 		ret = ft_strdup("%");
// 	return (ret);
// }

// char	*ft_char_convert(unsigned int c, t_flags *flags)
// {
// 	int		len;
// 	char	*ret;
// 	char	*width;

// 	ret = second_percent(c);
// 	if (ret)
// 		return (ret);
// 	width = ft_min_width_generator(flags);
// 	if (flags->width)
// 		len = flags->width;
// 	else
// 		len = 1;
// 	ret = (char *)malloc(sizeof(char) * len + 1);
// 	if (ret)
// 	{
// 		ret[len] = '\0';
// 		ret[0] = c;
// 		if (width)
// 			ft_width_joiner(width, ret, flags, 1);
// 		return (ret);
// 	}
// 	return (NULL);
// }

int ft_char_convert(unsigned int c, t_flags *flags)
{
	int ret;

	ret = 0;
	if (flags->minus)
		ret += write(1, &c, 1);
	if (flags->width)
	{
		while (--flags->width > 0)
			ret += write(1, " ", 1);
	}
	if (!flags->minus)
		ret += write(1, &c, 1);
	return (ret);
}