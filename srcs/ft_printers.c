/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:35:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/06 13:41:59 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printer(char *str, t_flags *flags)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		if (ret == flags->precision)
			break ;
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

static char	*padding(t_flags *flags, char *str, char spec, bool zero)
{
	if (flags->plus && *str != '-')
			return(ft_strdup("+"));
	if (*str == '-')
		return(ft_strdup("-"));
	if (flags->space)
		return(ft_strdup(" "));
	if (!zero)
	{
		if (flags->hash)
		{
			if (spec == 'o')
					return(ft_strdup("0"));
			if (spec == 'x')
				return(ft_strdup("0x"));
			if (spec == 'X')
				return(ft_strdup("0X"));
		}
	}
	return(NULL);
}

static char	*di_width_printer(t_flags *flags, char *str, char *padd, char speci, bool nan)
{
	int		len;
	char	*width;
	int		mem_alloc;
	
	width = NULL;
	if (flags->width)
	{
		len = ft_strlen(str);
		if (padd)
			len += ft_strlen(padd);
		if (flags->precision == 0 && speci != 'f')
			len--;
		// if (speci == 'f')
		// 	len++;
		mem_alloc = flags->width - len;
		if (mem_alloc > 0)
		{
			width = (char *)malloc(sizeof(char) * mem_alloc + 1);
			if (!width)
				return (NULL);
			width[mem_alloc] = '\0';
			if (flags->zero && (flags->precision == -1 || speci == 'f') && !nan)
				ft_memset((void *)width, '0', (mem_alloc));				
			else
				ft_memset((void *)width, ' ', (mem_alloc));
		}
	}
	return (width);
}

static char	*precision(char *str, int precision)
{
	int		len;
	int		sign;
	char	*ret;
	char	*tmp;

	sign = 0;
	ret = NULL;
	len = ft_strlen(str);
	// printf("%i\n", len);
	// if (padd)
	// 	len+= ft_strlen(padd);
	if (precision >= len)
	{
		ret = (char *)malloc(sizeof(char) * precision + 1);
		if (!ret)
			return (NULL);
		ret[precision--] = '\0';
		while (precision >= 0)
		{
			if (len)
			{
				ret[precision--] = str[--len];
				if (ret[precision+1] == '-')
				{
					ret[precision+1] = '0';
					sign++;
				}	
			}		
			else
				ret[precision--] = '0';
		}
		// printf("%s}\n", ret);
		if (sign)
		{
			tmp = ret;
			ret = ft_strjoin("-", ret);
			free(tmp);
		}
		free(str);
		
		str = ret;
		
	}
	
	return (str);
}

static int	str_printer(t_flags *flags, char *str, char *width, char speci)
{
	int	ret;

	ret = 0;
	// printf("%s}\n", str);
	while (*str != '\0')
	{
		if (flags->precision == 0 && *str == '0' && (speci != 'f'))
		{
			if (width && flags->minus)
				ret += write(1, width, (int)ft_strlen(width));
			if (flags->hash && speci == 'o')
				ret += write(1, "0", 1);
			break ;
		}
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int	ft_diouxf_printer(char *str, t_flags *flags, char specifier)
{
	int		ret;
	char	*tmp;
	char	*width;
	char	*padd;
	bool	zero;
	bool	nan;

	ret = 0;
	padd = NULL;
	nan = false;
	zero = false;
	if (ft_strcmp("0", str) == 0)
		zero = true;
	if (ft_strcmp("nan", str) == 0)
		nan = true;
	if (!nan)
	{
		
		str = precision(str, flags->precision);
		padd = padding(flags, str, specifier, zero);
	}
	// else
	// 	nan = true;
	if (*str == '-')
	{
		tmp = str;
		str = ft_strdup(&str[1]);
		free(tmp);
	}
	width = di_width_printer(flags, str, padd, specifier, nan);
	if (!flags->zero && padd)
	{
		tmp = str;
		str = ft_strjoin(padd, str);
		free(tmp);	
	}
	if (width)
	{
		tmp = str;
		if (!flags->minus)
			str = ft_strjoin(width, str);
		else
			str = ft_strjoin(str, width);
		free(tmp);
	}
	if (flags->zero && padd)
	{
		tmp = str;
		str = ft_strjoin(padd, str);
		free(tmp);
	}
	ret += str_printer(flags, str, width, specifier);
	// ret += str_printer(flags, str, width);
	// free(width)
	free(str);
	free(padd);
	free(width);
	return (ret);
}
