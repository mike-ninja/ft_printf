/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_joiner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:32:02 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/12 16:35:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len)
{
    int i;
    int y;

    if (min_width && len < ft_strlen(min_width))
    {
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
        ft_strcpy(ret, min_width);
        ft_strdel(&min_width);
    }
}
