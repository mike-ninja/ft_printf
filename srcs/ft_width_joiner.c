/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_joiner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:32:02 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/18 13:26:24 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void     ft_width_joiner(char *min_width, char *ret, t_flags *flags, int len)
{
    int i;
    int y;
    if (min_width && len < (int)ft_strlen(min_width))
    {
        y = len;
        // printf("[%i]\n", y);
        i = flags->width;
        if (!flags->minus)
            while (y > 0 || flags->precision > 0)
            {
                y--;
                if (y >= 0)
                    min_width[--i] = ret[y];
                else
                    
                    min_width[--i] = ' ';
                flags->precision--;
            }
        else
            while (y > 0)
            {
                i--;
                if (i < y)
                    min_width[i] = ret[--y];
                else
                    min_width[i] = ' ';
            }
        //printf("[1:%s]", ret);
        ft_strcpy(ret, min_width);
    }
    if (min_width)
        ft_strdel(&min_width);
}
