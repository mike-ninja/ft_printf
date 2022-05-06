/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_specifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:39:36 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/06 10:40:51 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *str_char_specifier(char *str, t_struct *node)
{
    char    *ret;
    int     str_len;
    int     tot_len;

    if (str)
    {
        str_len = node->precision > 0 ? node->precision : ft_strlen(str);
        tot_len = str_len < node->width ? node->width : str_len;
        ret = (char *)malloc(sizeof(char) * tot_len + 1);
        if (ret)
        {
            ret[tot_len] = '\0';
            while (tot_len >= 0)
                ret[tot_len--] = str_len < 0 ? ' ' : str[str_len--];
            return (ret);
        }
    }
    return (NULL);
}
