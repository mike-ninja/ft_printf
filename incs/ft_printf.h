/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/06 10:50:58 by mbarutel         ###   ########.fr       */
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

int		ft_str_convert(char *str, t_flags *flags);
int		ft_char_convert(unsigned int c, t_flags *flags);
int		ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod);
int		ft_diouxf_convert(t_arg *arg, t_flags *flags, t_modifier *mod);

//Restructure

int	ft_printer(char *str, t_flags *flags);
int	ft_nbr_convert(char *str, t_flags *flags);
char *ft_float(double nbr, t_flags *flags);
char *ft_lfloat(long double nbr, t_flags *flags);

// dioux convert
int	ft_diu_convert(char *str, t_flags *flags, char specifier);

// print_utils
int	ft_printf(const char *restrict format, ...);

// utils
void flags_correction(t_flags *flags, char specifier);
int speci_correction(char specifier);

#endif