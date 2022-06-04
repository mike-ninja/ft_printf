#include "../incs/ft_printf.h"

static int sign_space_print(t_flags *flags, char *str)
{
	int ret;
	
	ret = 0;
	if (flags->plus && *str != '-')
		ret += write(1, "+", 1);
	if (*str == '-' && flags->zero)
		ret += write(1, "-", 1);
	if (flags->space && (!flags->plus && *str != '-'))
		ret += write(1, " ", 1);
	return (ret);
}

static int di_width_printer(t_flags *flags, char *str, int len)
{
	int tmp;
	int	ret;

	ret = 0;
	if (flags->precision >= 0)
		tmp = flags->width - flags->precision;
	else
		tmp = flags->width - len;
	if (flags->space || (flags->plus && *str != '-'))
		tmp--;
	if (*str == '-' && flags->precision > 0)
		tmp--;
	while (--tmp >= 0)
	{
		if (flags->zero && flags->precision < len)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return  (ret);
}

static int	str_printer(t_flags *flags, char *str, int len)
{
	int ret;
	int tmp;

	ret = 0;
	tmp = flags->precision;
	if (*str == '-' && flags->zero)
		str++;
	if (flags->precision > len && *str == '-')
	{
		ret += write(1, "-", 1);
		len--;
		str++;
	}
	if (flags->zero)
	{
		str--;
		if (*str == '-')
			len--;
		str++;
	}
	while (tmp-- > len)
		ret += write(1, "0", 1);
	while (*str != '\0')
	{
		if (flags->precision == 0 && *str == '0')
			break;
		ret += write(1, str, 1);
		str++;
	}	
	return (ret);
}

int	ft_diu_convert(char *str, t_flags *flags)
{
	int	ret;
	int	len;

	ret = 0;
	len = ft_strlen(str);
	if (flags->minus)
	{
		ret += sign_space_print(flags, str);
		ret += str_printer(flags, str, len);
		ret += di_width_printer(flags, str, len);
	}
	else
	{
		if (flags->zero)
			ret += sign_space_print(flags, str);
		ret += di_width_printer(flags, str, len);
		if (!flags->zero)
			ret += sign_space_print(flags, str);
		ret += str_printer(flags, str, len);
	}
	return (ret);
}

static int u_width_printer(t_flags *flags, char *str, int len)
{
	int tmp;
	int	ret;

	ret = 0;
	if (flags->precision >= 0)
		tmp = flags->width - flags->precision;
	else
		tmp = flags->width - len;
	if (*str == '-' && flags->precision > 0)
		tmp--;
	while (--tmp >= 0)
	{
		if (flags->zero && !flags->minus && flags->precision < len)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return  (ret);
}

int	ft_u_convert(char *str, t_flags *flags)
{
	int	ret;
	int	len;

	ret = 0;
	len = ft_strlen(str);
	if (flags->minus)
	{
		ret += str_printer(flags, str, len);
		ret += u_width_printer(flags, str, len);
	}
	else
	{
		ret += u_width_printer(flags, str, len);
		ret += str_printer(flags, str, len);
	}
	return (ret);
}

int	ft_x_convert(char *str, t_flags *flags, char speci)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	tmp = 0;
	len = (int)ft_strlen(str);
	if (flags->minus)
	{
		if (flags->hash)
		{
			if (speci == 'X')
					ret += write(1, "0X", 2);
			else
				ret += write(1, "0x", 2);
		}
		ret += ft_x_printer(str, flags, len, speci);
	}
	if (flags->width)
	{
		if (!flags->minus)
			tmp = len;
		else
			tmp = ret;
		if (flags->precision > len)
			tmp = flags->precision;
		if (flags->hash && !flags->minus)
			tmp+=2;
		if (flags->precision == 0)
			tmp = 0;
		if (flags->hash && flags->zero && !flags->minus)
		{
			if (len != 1 || *str != '0')
			{
				if (speci == 'X')
					ret += write(1, "0X", 2);
				else
					ret += write(1, "0x", 2);
			}
		}
		while ((--flags->width - tmp) >= 0)
		{
			if (flags->zero && !flags->minus)
			{
				if (flags->zero)
					ret += write(1, "0", 1);
				else
					ret += write(1, " ", 1);
			}
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_x_printer(str, flags, len, speci);
	return (ret);
}

int	ft_o_convert(char *str, t_flags *flags)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	tmp = 0;
	len = (int)ft_strlen(str);
	if (flags->minus)
		ret += ft_o_printer(str, flags, len);
	if (flags->width)
	{
		if (!flags->minus)
		{
			tmp = len;
			if (flags->hash)
				tmp++;
		}	
		else
			tmp = ret;
		if (flags->precision > len)
			tmp = flags->precision;
		if (flags->precision == 0)
			tmp = 0;
		while ((--flags->width - tmp) >= 0)
		{
			if (flags->zero && !flags->minus)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_o_printer(str, flags, len);
	return (ret);
}


int	ft_f_convert(char *str, t_flags *flags)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	len = (int)ft_strlen(str);
	if (flags->minus)
		ret += ft_f_printer(str, flags, len);
	if (flags->width)
	{
		if (!flags->minus)
			tmp = len;
		else
			tmp = ret;
		if (flags->precision > len)
			tmp = flags->precision;
		while ((--flags->width - tmp) >= 0)
		{
			if (flags->zero && !flags->minus)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_f_printer(str, flags, len);
	return (ret);
}