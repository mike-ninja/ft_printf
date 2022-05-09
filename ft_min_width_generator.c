/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:30:45 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/09 10:36:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char     *ft_min_width_generator(t_struct *node)
{
    int     i;
    char    *ret;
    
    if (node->width > 0)
    {
        i = 0;
        ret = (char *)malloc(node->width + 1);
        if (ret)
        {
            ret[node->width] = '\0';
            while (i < node->width)
                ret[i++] = node->zero > 0 && node->precision == 0 ? '0' : ' ';
            return (ret);
        }
    }
    return (NULL);
}