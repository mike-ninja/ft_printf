/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/10 13:11:41 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_filter(char *format, va_list arg, t_flags *flags, t_modifier *mod)
{
	char	*str; 
	
	str = NULL;
	switch(format[0])
	{
		case 'c' :
			str = ft_char_convert(va_arg(arg, unsigned int), flags);
			break;
		case 's' :
			str = ft_str_convert(va_arg(arg, char *), flags);
			break;
		case 'd' :
			str = ft_nbr_converter(arg, flags, mod, 10);
			printf("decimal\n");
			break;
		case 'i' :
			printf("integer\n");
			break;
		case 'f' :
			printf("double\n");
			break;
		case 'x' :
			printf("hexi\n");
			break;
		case 'X' :
			printf("HEXI\n");
			break;
		case 'u' :
			printf("unsigned\n");
			break;
	}
	ft_putstr(str);
	free(str);
}
