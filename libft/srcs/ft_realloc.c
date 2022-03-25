/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:39:45 by mbarutel          #+#    #+#             */
/*   Updated: 2022/01/11 17:53:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	i;
	void	*ret;

	if (ptr && size > 0)
	{
		i = 0;
		while (((char *)ptr)[i] != '\0')
			i++;
		ret = (void *)malloc(i + size);
		ft_memcpy(ret, ptr, i + size);
		return (ret);
	}
	return (NULL);
}
