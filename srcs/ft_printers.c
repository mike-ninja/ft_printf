/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:35:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/08 15:16:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*padding(t_flags *flags, char *str, char spec, bool zero)
{
	if (flags->plus && *str != '-')
		return (ft_strdup("+"));
	if (*str == '-')
		return (ft_strdup("-"));
	if (flags->space)
		return (ft_strdup(" "));
	if (!zero || spec == 'p')
	{
		if (flags->hash || spec == 'p')
		{
			if (spec == 'o')
				return (ft_strdup("0"));
			if (spec == 'x' || spec == 'p')
				return (ft_strdup("0x"));
			if (spec == 'X')
				return (ft_strdup("0X"));
		}
	}
	return (NULL);
}

char	*di_width_printer(t_flags *flags, char *str, t_attr *attr, char speci)
{
	int		len;

	if (flags->width)
	{
		len = ft_strlen(str);
		if (attr->padd)
			len += ft_strlen(attr->padd);
		if (flags->precision == 0 && speci != 'f')
			len--;
		if ((flags->width - len) > 0)
		{
			attr->width = (char *)malloc((flags->width - len) + 1);
			if (!attr->width)
				return (NULL);
			attr->width[(flags->width - len)] = '\0';
			if (flags->zero && (flags->precision == -1 || speci == 'f'))
				ft_memset((void *)attr->width, '0', ((flags->width - len)));
			else
			{
				ft_memset((void *)attr->width, ' ', ((flags->width - len)));
				flags->zero = 0;
			}
		}
	}
	return (attr->width);
}

// char	*precision(char *str, int precision, int padd)
// {
// 	int		len;
// 	int		sign;
// 	char	*ret;
// 	char	*tmp;

// 	sign = 0;
// 	ret = NULL;
// 	len = ft_strlen(str) + padd;
// 	if (precision >= len)
// 	{
// 		ret = (char *)malloc(sizeof(char) * precision + 1);
// 		if (!ret)
// 			return (NULL);
// 		ret[precision--] = '\0';
// 		while (precision >= 0)
// 		{
// 			if (len)
// 			{
// 				ret[precision--] = str[--len];
// 				if (ret[precision + 1] == '-')
// 				{
// 					ret[precision + 1] = '0';
// 					sign++;
// 				}	
// 			}		
// 			else
// 				ret[precision--] = '0';
// 		}
// 		if (sign)
// 		{
// 			tmp = ret;
// 			ret = ft_strjoin("-", ret);
// 			free(tmp);
// 		}
// 		free(str);
// 		str = ret;
// 	}
// 	return (str);
// }

char	*precision(char *str, int precision, int padd)
{
	int		len;
	bool	sign;
	char	*ret;

	sign = 0;
	ret = NULL;
	len = ft_strlen(str) + padd;
	if (precision >= len)
	{
		ret = (char *)malloc(sizeof(char) * precision + 1);
		if (!ret)
			return (NULL);
		ret[precision--] = '\0';
		while (precision >= 0)
			sign = precision_util(ret, &precision, &len, str);
		if (sign)
			ret = strjoin_tail("-", ret);
		free(str);
		str = ret;
	}
	return (str);
}

static int	str_printer(t_flags *flags, char *str, char *width, char speci)
{
	int		ret;
	char	*tmp;

	ret = 0;
	tmp = str;
	while (*str != '\0')
	{
		if (flags->precision == 0 && *str == '0' && (speci != 'f'))
		{
			if (speci == 'p')
				ret += write(1, str, (int)ft_strlen(str) - 1);
			if (width && flags->minus)
				ret += write(1, width, (int)ft_strlen(width));
			break ;
		}
		ret += write(1, str, 1);
		str++;
	}
	free(tmp);
	return (ret);
}

int	ft_diouxf_printer(char *str, t_flags *flags, char specifier)
{
	int		ret;
	t_attr	attr[1];

	ret = 0;
	attr_init(attr);
	attr_parse(str, attr, flags, specifier);
	str = str_correction(str, flags, attr, specifier);
	if (attr->width)
	{
		if (!flags->minus)
			str = strjoin_tail(attr->width, str);
		else
			str = strjoin_head(str, attr->width);
	}
	if (flags->zero && attr->padd)
		str = strjoin_tail(attr->padd, str);
	ret += str_printer(flags, str, attr->width, specifier);
	free(attr->padd);
	free(attr->width);
	return (ret);
}
