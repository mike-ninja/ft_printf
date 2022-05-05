/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/05 14:14:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>

//char    *ft_converter(int value, int base);

typedef struct s_struct
{
	int		pos;
	char	*str;
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		width;
	int		space;
	int		percent;
	char	specifier;
}				t_struct;

void	ft_printf(char *format, ...);
char    *ft_hex(unsigned long long value);

#endif