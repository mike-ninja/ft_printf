/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:56:37 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/07 12:46:40 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static char	*ft_float_base(long val)
{
	int		len;
	long	tmp;
	char	*ret;

	len = 1;
	if (val < 0)
	{
		len++;
		tmp = val * -1;
	}
	else
		tmp = val;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (val < 0)
		tmp = val * -1;
	else
		tmp = val;
	if (val == 0)
		len++;
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		ret[len--] = '\0';
		ret[len--] = '.';
		if (val == 0)
			ret[len] = '0';
		if (val < 0)
			ret[0] = '-';
		while (tmp)
		{
			ret[len--] = (tmp % 10) + '0';
			tmp /= 10;
		}
		return (ret);
	}
	return (NULL);
}

static void	ft_banker_round(char *ret, double nbr)
{
	int	tmp;
	int	index;

	tmp = nbr * 10;
	index = ft_strlen(ret);
	if (tmp >= 5)
	{
		while (ret[index - 1] == '9' || ret[index - 1] == '.')
		{
			if (ret[index - 1] == '.')
				index--;
			else
			{
				ret[index - 1] = '0';
				index--;
			}
		}
		ret[index - 1]++;
	}
}

char	*ft_float(double nbr, t_flags *flags)
{
	char	*ret;
	char	*tmp;
	char	*first_part;
	long	base;
	int		len;
	int		i;

	i = 0;
	ret = NULL;
	first_part = NULL;
	base = (long)nbr;
	first_part = ft_float_base(base);
	if (nbr < 0)
	{
		nbr *= -1;
		base *= -1;
	}
	if (flags->precision > 0)
		len = flags->precision;
	else
		len = 6;
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		ret[len] = '\0';
		nbr = nbr - base;
		while (i < len)
		{
			nbr *= 10;
			base = nbr;
			nbr -= base;
			ret[i++] = base + '0';
		}
		tmp = ft_strjoin(first_part, ret);
		ft_banker_round(tmp, nbr);
		ft_strdel(&first_part);
		ft_strdel(&ret);
		return (tmp);
	}
	return (NULL);
}

static void	ft_lbanker_round(char *ret, long double nbr)
{
	long double	tmp;
	int			index;

	tmp = nbr * 10 - nbr;
	index = ft_strlen(ret);
	if (tmp >= 5)
	{
		while (ret[index - 1] == '9' || ret[index - 1] == '.')
		{
			if (ret[index - 1] == '.')
				index--;
			else
			{
				ret[index - 1] = '0';
				index--;
			}
		}
		ret[index - 1]++;
	}
}

char	*ft_lfloat(long double nbr, t_flags *flags)
{
	char	*ret;
	char	*tmp;
	char	*first_part;
	long	base;
	int		len;
	int		i;

	i = 0;
	ret = NULL;
	first_part = NULL;
	base = (long)nbr;
	first_part = ft_float_base(base);
	if (nbr < 0)
	{
		nbr *= -1;
		base *= -1;
	}
	if (flags->precision > 0)
		len = flags->precision;
	else
		len = 6;
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		ret[len] = '\0';
		nbr = nbr - base;
		while (i < len)
		{
			nbr *= 10;
			base = nbr;
			nbr -= base;
			ret[i++] = base + '0';
		}
		tmp = ft_strjoin(first_part, ret);
		ft_lbanker_round(tmp, nbr);
		ft_strdel(&first_part);
		ft_strdel(&ret);
		return (tmp);
	}
	return (NULL);
}
