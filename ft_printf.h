/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/12 15:34:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/incs/libft.h"
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

typedef struct s_arg
{
	va_list arg;
	char	specifier;
}				t_arg;

// char    *ft_percent_convert(void);
int		ft_printf(char *format, ...);
int		ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod);
// char    *ft_hex_convert(unsigned long long value, char specifier, t_struct *node);
char    *ft_char_convert(unsigned int c, t_flags *flags);
char	*ft_str_convert(char *str, t_flags *flags);
char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod);
char     *ft_min_width_generator(t_flags *flags);
void	ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len);

#endif