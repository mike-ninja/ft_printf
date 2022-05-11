/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:23:42 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/11 10:41:39 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  int_len(signed long long value, int base, t_flags *flags)
{
    int ret;
    int val;

    val = (value < 0 && base == 10) ? value*-1 : (unsigned int)value;
    ret = ((value < 0 && base == 10) || value == 0 || (base == 10 && flags->plus > 0) || (base != 10 && node->hash > 0)) ? 1 : 0;
    while (val != 0)
    {
        ret++;
        val /= base;
    }
    return (ret);
}

int optionA(char *ret, t_arg *arg, t_flags *flags)
{
    int ret;
    int len;

    ret = 0;
    switch (arg->specifier)
    {
        case 'd' || 'i':
            len = int_len(va_arg(arg->arg, signed int), 10, flags);
            break;

    }
}