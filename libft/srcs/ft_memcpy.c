/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:53 by mbarutel          #+#    #+#             */
/*   Updated: 2021/11/16 14:04:53 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	ft_memcpy:
**	: Copies n bytes from memory area src to memory area dst.
**	: If dst and src overlap, behavior is undefined.
**	: Applications in which dst and src might overlap should use
**   ft_memmove instead.
**  : Code below written by Cchen.
*/

/* void	*ft_memcpy(void *dest, const void *src, size_t n)
** {
** 	size_t	i;

** 	i = 0;
** 	if (!dest && !src)
** 		return (NULL);
** 	while (i < n)
** 	{
** 		((char *)dest)[i] = ((const char *)src)[i];
** 		i++;
** 	}
** 	return (dest);
** }
*/

static void	ft_copy_chunks(unsigned char **dst,
		const unsigned char **src, size_t n)
{
	unsigned long		*d;
	const unsigned long	*s;

	d = (unsigned long *)*dst;
	s = (const unsigned long *)*src;
	*dst += n * sizeof(long);
	*src += n * sizeof(long);
	while (n--)
		*d++ = *s++;
}

static void	ft_copy_trail(unsigned char **dst,
		const unsigned char **src, size_t n)
{
	unsigned int	chunk;
	unsigned int	trail;

	chunk = n / sizeof(int);
	trail = n % sizeof(int);
	if (chunk)
		*(*(unsigned int **)dst)++ = *(*(const unsigned int **)src)++;
	if (trail / sizeof(short))
		*(*(unsigned short **)dst)++ = *(*(const unsigned short **)src)++;
	if (n % sizeof(short))
		*(*dst)++ = *(*src)++;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		chunks;
	unsigned int		trail;

	if (n == 0 || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	chunks = n / sizeof(long);
	trail = n % sizeof(long);
	if (chunks)
		ft_copy_chunks(&d, &s, chunks);
	ft_copy_trail(&d, &s, trail);
	return (dst);
}
