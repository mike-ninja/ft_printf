/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:33:19 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/08 16:16:06 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_percent_convert(void)
{
    char *ret;
    
    ret = (char *)malloc(2);
    if (ret)
    {
        ret[1] = '\0';
        ret[0] = '%';
        return (ret);
    }
    return (NULL);
}