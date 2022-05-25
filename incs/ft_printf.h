/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/25 13:32:29 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/incs/libft.h"
# include <stdio.h>
# include <stdarg.h>

//char    *ft_converter(int value, int base);

typedef struct s_flags
{
	int		dot;
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
	int	mod;
}				t_modifier;

typedef struct s_arg
{
	va_list arg;
	char	specifier;
}				t_arg;

#define U_LLONG unsigned long long

int		ft_printf(char *format, ...);
char     *ft_min_width_generator(t_flags *flags);
int		ft_str_convert(char *str, t_flags *flags);
int    ft_char_convert(unsigned int c, t_flags *flags);
int		ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod);
char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod);
void	ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len);

//Restructure

int	ft_printer(char *str, t_flags *flags);

#endif