/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_joiner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:32:02 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/09 11:58:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_width_joiner(char *min_width, char *ret, t_struct *node, int len)
{
    int i;
    int y;

    y = len;
    i = node->width;
    if (!node->minus)
        while (y > 0 || node->precision > 0)
        {
            min_width[--i] = --y >= 0 ? ret[y] : 0 + '0';
            node->precision--;
        }
    else
        while (y > 0)
        {
            i--;
            min_width[i] = i < y ? ret[--y] : ' ';
        }
    // if (node->hash && (node->specifier != 'i' && node->specifier != 'd')) // This is supposed to handle # flag, but instead, this just adds another 0. I dont know why
    //     min_width[--i] = '0';   
    ft_strcpy(ret, min_width);
    ft_strdel(&min_width);
}
