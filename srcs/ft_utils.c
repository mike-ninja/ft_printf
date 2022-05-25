/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:05 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/25 13:32:09 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printer(char *str, t_flags *flags)
{
	int	ret;
	int	tmp; 
	
	ret = 0;
	if (flags->precision)
			tmp = ret;
	while (*str != '\0')
	{
		ret += write(1, str, 1);
		if ((ret - tmp) == flags->precision)
			break;
		str++;
	}
	return (ret);
}
