/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_joiner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:32:02 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/11 12:19:54 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len)
{
    int i;
    int y;

    y = len;
    i = flags->width;
    if (!flags->minus)
        while (y > 0 || flags->precision > 0)
        {
            min_width[--i] = --y >= 0 ? ret[y] : 0 + '0';
            flags->precision--;
        }
    else
        while (y > 0)
        {
            i--;
            min_width[i] = i < y ? ret[--y] : ' ';
        }
    // if (flags->hash && (flags->specifier != 'i' && flags->specifier != 'd')) // This is supposed to handle # flag, but instead, this just adds another 0. I dont know why
    //     min_width[--i] = '0';   
    ft_strcpy(ret, min_width);
    ft_strdel(&min_width);
}
