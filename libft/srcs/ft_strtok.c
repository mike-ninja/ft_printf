/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:02:24 by mbarutel          #+#    #+#             */
/*   Updated: 2022/01/16 12:21:19 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ret_char(char *str, int pos)
{
	char	*ret;

	ret = ft_strsub(str, 0, pos);
	ft_strdel(&str);
	str = ret;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	int		i;
	int		pos;

	if (str || delim)
		return (NULL);
	pos = 0;
	while (delim[0] != '\0')
	{	
		i = 0;
		while (str[i] != '\0')
		{
			if (delim[0] == str[i])
			{
				if (!pos)
					pos = i;
				if (i < pos)
					pos = i;
			}
			i++;
		}
		delim++;
	}
	if (pos)
		return (ret_char(str, pos));
	return (NULL);
}
