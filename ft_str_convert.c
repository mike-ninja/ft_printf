/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:35:48 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/08 15:36:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_str_convert(char *str, t_struct *node)
{
    char    *ret;
    int     str_len;
    int     tot_len;

    if (str)
    {
        str_len = node->precision > 0 && node->precision < ft_strlen(str) ? node->precision : ft_strlen(str);
        tot_len = str_len < node->width ? node->width : str_len;
        ret = (char *)malloc(sizeof(char) * tot_len + 1);
        if (ret)
        {
            ret[tot_len] = '\0';
            if (!node->minus)
                while (tot_len > 0)
                    ret[--tot_len] = str_len <= 0 ? ' ' : str[--str_len];
            else
                while (tot_len)
                    ret[--tot_len] = str_len < tot_len ? ' ' : str[--str_len];
            return (ret);
        }
    }
    return (NULL);
}