/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/01 10:51:36 by mbarutel         ###   ########.fr       */
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

char    *ft_min_width_generator(t_flags *flags);
int		ft_str_convert(char *str, t_flags *flags);
int		ft_char_convert(unsigned int c, t_flags *flags);
int		ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod);
int		ft_diouxf_filter(t_arg *arg, t_flags *flags, t_modifier *mod);
void	ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len);

//Restructure

int	ft_printer(char *str, t_flags *flags);
int	ft_nbr_convert(char *str, t_flags *flags);
char *ft_float(double nbr, t_flags *flags);

// dioux convert
int	ft_diu_convert(char *str, t_flags *flags);
int	ft_x_convert(char *str, t_flags *flags, char speci);
int	ft_o_convert(char *str, t_flags *flags);
int	ft_f_convert(char *str, t_flags *flags);

// print_utils
int	ft_printf(const char *restrict format, ...);
int ft_diu_printer(char *str, t_flags *flags, int len);
int ft_x_printer(char *str, t_flags *flags, int len, char speci);
int ft_o_printer(char *str, t_flags *flags, int len);
int ft_f_printer(char *str, t_flags *flags, int len);
int	ft_u_convert(char *str, t_flags *flags);

#endif