/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:22 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/10 13:01:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_char_convert(unsigned int c, t_flags *flags)
{
    char    *ret;
    int     len;
    int     i;
    
    i = 0;
    len = flags->width > 0 ? flags->width : 1;
    ret = (char *)malloc(sizeof(char) * len + 1);
    if (ret)
    {
        ret[len] = '\0';
        while(i < len)
            ret[i++] = ' ';
        if (flags->minus)
            ret[0] = c;
        else
            ret[--len] = c;
        return (ret);
    }
    return (NULL);
}