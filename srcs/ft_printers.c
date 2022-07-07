/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:35:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/07 23:11:40 by mbarutel         ###   ########.fr       */
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
		return (ft_strdup("+"));
	if (*str == '-')
		return (ft_strdup("-"));
	if (flags->space)
		return (ft_strdup(" "));
	// if (flags->hash)
	// {
	// 	if (spec == 'o')
	// 	{
	// 		if (flags->precision <= (int)ft_strlen(str))
	// 				return (ft_strdup("0"));
	// 	}
	// }
	if (!zero)
	{
		if (flags->hash)
		{
			if (spec == 'o')
			{
				// printf("This happens\n");
				// if (flags->precision < (int)ft_strlen(str))
				// {
					// printf("This happens\n");
					return (ft_strdup("0"));
				// }
			}
			if (spec == 'x')
				return (ft_strdup("0x"));
			if (spec == 'X')
				return (ft_strdup("0X"));
		}
	}
	return (NULL);
}

static char	*di_width_printer(t_flags *flags, char *str, char *padd, char speci)
{
	int		len;
	char	*width;
	int		mem_alloc;

	width = NULL;
	if (flags->width)
	{
		len = ft_strlen(str);
		if (padd)
		{
			len += ft_strlen(padd);
		}
		if (flags->precision == 0 && speci != 'f')
			len--;
		mem_alloc = flags->width - len;
		if (mem_alloc > 0)
		{
			width = (char *)malloc(sizeof(char) * mem_alloc + 1);
			if (!width)
				return (NULL);
			width[mem_alloc] = '\0';
			if (flags->zero && (flags->precision == -1 || speci == 'f'))
				ft_memset((void *)width, '0', (mem_alloc));
			else
			{
				ft_memset((void *)width, ' ', (mem_alloc));
				flags->zero = 0;
			}
		}
	}
	return (width);
}

static char	*precision(char *str, int precision, int padd)
{
	int		len;
	int		sign;
	char	*ret;
	char	*tmp;

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
		{
			if (len)
			{
				ret[precision--] = str[--len];
				if (ret[precision + 1] == '-')
				{
					ret[precision + 1] = '0';
					sign++;
				}	
			}		
			else
				ret[precision--] = '0';
		}
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
	char *tmp;

	ret = 0;
	tmp = str;
	// printf("%s}\n", str);
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
	char	*tmp;
	char	*width;
	char	*padd;
	bool	zero;
	bool	nan;
	bool	inf;
	int padd_len;

	ret = 0;
	padd = NULL;
	width = NULL;
	nan = false;
	zero = false;
	inf = false;
	
	if (ft_strcmp("0", str) == 0)
	{
		zero = true;
		if (specifier != 'f' && flags->precision != 0)
			flags->hash = 0;
	}
		
	if (ft_strcmp("nan", str) == 0)
	{
		nan = true;
		flags->zero = 0;
	}
	if (ft_strstr(str, "inf"))
	{
		inf = true;
		flags->zero = 0;
	}
	if (flags->precision == 0 && specifier == 'f' && flags->hash && !nan && !inf)
	{
		tmp = str;
		str = ft_strjoin(str, ".");
		free(tmp);
	}
	if (!nan)
	{
		
		padd = padding(flags, str, specifier, zero);
		padd_len = 0;
		if (padd)
		{
			if (specifier == 'o')
				padd_len = ft_strlen(padd);
		}
		// printf("%s}\n", padd);
		if (!inf)
		{
			
				str = precision(str, flags->precision, padd_len);
		}
		// printf("%s]\n", str);
	}
	if (*str == '-')
	{
		tmp = str;
		str = ft_strdup(&str[1]);
		free(tmp);
	}
	width = di_width_printer(flags, str, padd, specifier);
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
	free (padd);
	free(width);
	return (ret);
}
