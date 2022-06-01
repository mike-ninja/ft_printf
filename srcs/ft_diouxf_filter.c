/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxf_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:17:09 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/01 09:32:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// static char *precision_cut(char *str, t_flags *flags, char speci)
// {
//     char *ret;

//     ret = NULL;
//     if (flags->precision > (int)ft_strlen(str))
//     {
//         ret = (char *)malloc(flags->precision + 1);
//         if (ret)
//         {
//             // printf("precision: [%i]\n", flags->precision);
//             ret[flags->precision] = '\0';
//             ret = ft_strncpy(ret, str, flags->precision-1);
//             //free(str);
//             //printf("[%s]\n", ret);
//             return (ret);
//         }
//     }
//         // printf("This happens\n");
//     //printf("\n[%i][%i]\n", flags->precision, flags->hash);
//     if (flags->precision == 0)
//         if (!flags->hash || ft_strchr("xX", speci))
//             str[flags->precision] = '\0';
//     return (str);
// }

// static char *plus_hash(t_flags *flags, char *str, char *width, char specifier)
// {
//     char    *ret;
//     char    *tmp;
//     char    *precision;
//     int     len;
//     int     int_tmp;

//     ret = NULL;
//     int_tmp = flags->precision;
//     if (str && *str != '0')
//     {
//         len = ft_strlen(str);
//         if (specifier == 'i' || specifier == 'd')
//             if (flags->plus)
//                 ret = ft_strjoin("+", str);
//         if (int_tmp > 1 && int_tmp > len)
//         {
//             int_tmp -= len;
//             precision = (char *)malloc(int_tmp);
//             precision[int_tmp] = '\0';
//             while (int_tmp > 0)
//                     precision[--int_tmp] = '0';
//             tmp = str;
//             str = ft_strjoin(precision, str);
//             free(tmp);
//         }
//         if (flags->hash)
//         {
//             if (specifier == 'o')
//                 ret = ft_strjoin("0", str);
//             if (specifier == 'x')
//             {
//                 if (!width || flags->zero == 0 || flags->minus)
//                     ret = ft_strjoin("0x", str);
//                 else
//                     width[1] = 'x';
					
//             }
//             if (specifier == 'X')
//             {
//                 if (!width || flags->zero == 0 || flags->minus)
//                     ret = ft_strjoin("0X", str);
//                 else
//                     width[1] = 'X';
//             }
//         }
			
//         if (ret)
//         {
//             free(str);
//             str = ret;
//         }
//     }
//     return (str);
// }

// char    *ft_nbr_converter(t_arg *arg, t_flags *flags, t_modifier *mod)
// {
//     char            *ret;
//     char            *width;
//     int             index;

//     index = 0;
//     ret = NULL;
//     width = ft_min_width_generator(flags);
//     if (arg->specifier == 'd' || arg->specifier == 'i')
//     {
//         if (mod->mod == 0)
//             ret = ft_itoa_base(va_arg(arg->arg, int), 10);
//         if (mod->mod == 1)
//             ret = ft_itoa_base((short)va_arg(arg->arg, int), 10);
//         if (mod->mod == 2)
//             ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 10);
//         if (mod->mod == 3)
//             ret = ft_litoa_base(va_arg(arg->arg, long), 10);
//         if (mod->mod == 5)
//             ret = ft_llitoa_base(va_arg(arg->arg, long long), 10);
//     }
//     if (arg->specifier == 'o')
//     {
//         if (mod->mod == 0)
//             ret = ft_itoa_base(va_arg(arg->arg, int), 8);
//         if (mod->mod == 1)
//             ret = ft_itoa_base((short)va_arg(arg->arg, int), 8);
//         if (mod->mod == 2)
//             ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 8);
//         if (mod->mod == 3)
//             ret = ft_litoa_base(va_arg(arg->arg, long), 8);
//         if (mod->mod == 5)
//             ret = ft_llitoa_base(va_arg(arg->arg, long long), 8);
//     }
//     if (arg->specifier == 'x' || arg->specifier == 'X')
//     {
//         if (mod->mod == 0)
//         {
//             ret = ft_itoa_base(va_arg(arg->arg, int), 16);
//         }
//         if (mod->mod == 1)
//             ret = ft_itoa_base((short)va_arg(arg->arg, int), 16);
//         if (mod->mod == 2)
//             ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 16);
//         if (mod->mod == 3)
//             ret = ft_litoa_base(va_arg(arg->arg, long), 16);
//         if (mod->mod == 5)
//             ret = ft_llitoa_base(va_arg(arg->arg, long long), 16);
//         if (arg->specifier == 'X')
//             while (ret[index] != '\0')
//             {
//                 ret[index] = ft_toupper(ret[index]);
//                 index++;
//             }
//     }
   
//     ret = plus_hash(flags, ret, width, arg->specifier);
//     if (arg->specifier == 'u')
//     {
//         if (mod->mod == 0)
//             ret = ft_itoa_base(va_arg(arg->arg, int), 10);
//         if (mod->mod == 1)
//             ret = ft_itoa_base((short)va_arg(arg->arg, int), 10);
//         if (mod->mod == 2)
//             ret = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 10);
//         if (mod->mod == 3)
//             ret = ft_litoa_base(va_arg(arg->arg, long), 10);
//         if (mod->mod == 5)
//             ret = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
//     }
//     if (arg->specifier == 'f')
//     {
//         if (flags->dot > 0 && flags->precision == 0)
//             ret = ft_itoa_base((int)va_arg(arg->arg, double), 10);
//         else
//             ret = ft_float_convert(va_arg(arg->arg, double), flags);
//     }
//     // Cut for precision
//     // printf("\nret -> [%s]\n", ret);
//     ret = precision_cut(ret, flags, arg->specifier);
//     // printf("width[%i]\n", flags->width)
	
//     ft_width_joiner(width, ret, flags, ft_strlen(ret));
//     // printf("ret %s]", ret);
//     return (ret);
// }

// void    flag_input(t_flags *flags, char c)
// {   
//     if ((c == 'd' || c == 'i') && flags->precision > flags->width)
//         flags->precision = -1;
// }

static char *option_a(t_arg *arg, t_modifier *mod)
{
	char *str;

	str = NULL;
	if (arg->specifier == 'd' || arg->specifier == 'i')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 10);
		if (mod->mod == 1)
			str = ft_itoa_base((short)va_arg(arg->arg, int), 10);
		if (mod->mod == 2)
			str = ft_itoa_base((signed char)va_arg(arg->arg, int), 10);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 10);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 10);
	}
	if (arg->specifier == 'u')
	{
		if (mod->mod == 0)
			str = ft_litoa_base((unsigned)va_arg(arg->arg, int), 10);
		if (mod->mod == 1)
			str = ft_itoa_base((short)va_arg(arg->arg, int), 10);
		if (mod->mod == 2)
			str = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 10);
		if (mod->mod == 3)
			str = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
		if (mod->mod == 5)
			str = ft_ullitoa_base(va_arg(arg->arg, unsigned long long), 10);
	}
	return (str);
}

static char *option_b(t_arg *arg, t_modifier *mod)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	 if (arg->specifier == 'o')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 8);
		if (mod->mod == 1)
			str = ft_itoa_base((short)va_arg(arg->arg, int), 8);
		if (mod->mod == 2)
			str = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 8);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 8);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 8);
	}
	if (arg->specifier == 'x' || arg->specifier == 'X')
	{
		if (mod->mod == 0)
			str = ft_itoa_base(va_arg(arg->arg, int), 16);
		if (mod->mod == 1)
			str = ft_itoa_base((short)va_arg(arg->arg, int), 16);
		if (mod->mod == 2)
			str = ft_itoa_base((unsigned short)va_arg(arg->arg, int), 16);
		if (mod->mod == 3)
			str = ft_litoa_base(va_arg(arg->arg, long), 16);
		if (mod->mod == 5)
			str = ft_llitoa_base(va_arg(arg->arg, long long), 16);
		if (arg->specifier == 'X') // can put this in utils
		{
			tmp = str;
			while (*tmp != '\0')
			{
				*tmp = ft_toupper(*tmp);
				tmp++;
			}
		}
	}
	return (str);
}

static char *option_f(t_arg *arg, t_flags *flags)
{
	char *str;

	str = NULL;
	if (arg->specifier == 'f')
	{
		if (flags->dot > 0 && flags->precision == 0)
			str = ft_itoa_base((int)va_arg(arg->arg, double), 10);
		else
			str = ft_float(va_arg(arg->arg, double), flags);
	}
	return (str);
}

int ft_diouxf_filter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	int     ret;
	char    *str; 

	ret = 0;
	if (arg->specifier == 'd' || arg->specifier == 'i' || arg->specifier == 'u')
		str = option_a(arg, mod);
	if (arg->specifier == 'o' || arg->specifier == 'x' || arg->specifier == 'X')
		str = option_b(arg, mod);
	if (arg->specifier == 'f')
		str = option_f(arg, flags);
	if (str)
	{
		if (arg->specifier == 'd' || arg->specifier == 'i')
			ret	+= ft_diu_convert(str, flags);
		if (arg->specifier == 'u')
			ret	+= ft_u_convert(str, flags);
		if (arg->specifier == 'x' || arg->specifier == 'X')
			ret += ft_x_convert(str, flags, arg->specifier);
		if (arg->specifier == 'o')
			ret += ft_o_convert(str, flags);
		if (arg->specifier == 'f')
			ret += ft_f_convert(str, flags);
		free(str);
	}
	return (ret);
}