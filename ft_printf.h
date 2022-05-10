/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/10 11:47:54 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>

//char    *ft_converter(int value, int base);

typedef struct s_flags
{
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		width;
	int		space;
	int		precision;
}				t_flags;

typedef struct s_modifier
{
	/*
	0 - Default
	1 - h
	2 - hh
	3 - l
	4 - L
	5 - ll
	*/
	int	mod;
}				t_modifier;

// char    *ft_percent_convert(void);
int		ft_printf(char *format, ...);
// char    *ft_hex_convert(unsigned long long value, char specifier, t_struct *node);
// char    *ft_char_convert(char c, t_struct *node);
// char    *ft_str_convert(char *str, t_struct *node);
// char    *ft_nbr_converter(signed int value, int base, t_struct *node);
// char     *ft_min_width_generator(t_struct *node);
// void	ft_width_joiner(char *min_width, char *ret, t_struct *node, int len);

#endif