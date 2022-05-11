/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:26:57 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/11 12:32:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_filter(t_arg *arg, t_flags *flags, t_modifier *mod)
{
	char	*str; 
	int		ret;
	
	ret = 0;
	str = NULL;
	switch(arg->specifier)
	{
		case 'c' :
			str = ft_char_convert(va_arg(arg->arg, signed int), flags);
			break;
		case 's' :
			str = ft_str_convert(va_arg(arg->arg, char *), flags);
			break;
		case 'd' || 'i' || 'f' || 'x' || 'X' || "u"  :
			str = ft_nbr_converter(arg, flags, mod);
			printf("decimal\n");
			break;
	}
	ft_putstr(str);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
