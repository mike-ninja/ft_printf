/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/08 15:49:06 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_char_convert(char c, t_struct *node)
{
    char    *ret;
    int     len;
    int     i;
    
    i = 0;
    len = node->width > 0 ? node->width : 1;
    ret = (char *)malloc(sizeof(char) * len + 1);
    if (ret)
    {
        ret[len] = '\0';
        while(i < len)
            ret[i++] = ' ';
        if (node->minus)
            ret[0] = c;
        else
            ret[--len] = c;
        return (ret);
    }
    return (NULL);
}