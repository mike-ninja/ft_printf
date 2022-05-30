#include "../incs/ft_printf.h"

/*static int	width_printer(char *str, t_flags *flags, int len)
{
	int ret;
	int	tmp;
	
	ret = 0;
	tmp = 0;
	if (flags->zero)
		tmp++;
	if (flags->plus || flags->space)
		tmp++;
	if (flags->precision >= len)
		tmp+=flags->precision;
	while (--flags->width > 0)
	{
		if (flags->minus && *str != '\0')
			ret += write(1, str, 1);
		else
		{
			if (!flags->zero)
				write(1, " ", 1);
			else
				ret += write(1, "0", 1);
		}
			
		if (str)
			str++;
	}
		ret += write(1, "0", 1);
	return(ret);
}

int	ft_diu_convert(char *str, t_flags *flags)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	tmp = 0;
	len = (int)ft_strlen(str);
	if (flags->plus || *str == '-')
	{
		if (*str != '-')
			ret += write(1, "+", 1);
		else
			ret += write(1, "-", 1);
		tmp++;
	}
	//if (flags->minus)
	//	ret += ft_diu_printer(str, flags, len);
	if (flags->width)
	{
		//printf("%%\n");
		ret += width_printer(str, flags, len);
	}
		
	//if (!flags->minus)
	//	ret += ft_diu_printer(str, flags, len);
	return (ret);
}*/

int	ft_diu_convert(char *str, t_flags *flags)
{
	int	ret;
	int	tmp;
	int	len;
	
	ret = 0;
	tmp = 0;
	len = (int)ft_strlen(str);
	if (flags->minus)
		ret += ft_diu_printer(str, flags, len);
	if ((flags->plus || *str == '-') && flags->zero && !flags->minus)
	{
		if (flags->precision < 0)
		{
			if (*str != '-')
				ret += write(1, "+", 1);
			if (flags->width && *str == '-')
			{
				ret += write(1, "-", 1);
				len--;
			}
			tmp++;
		}	
	
	}
	if (flags->width)
	{
		if (!flags->minus)
			tmp += len;
		else
			tmp += ret;
		if (flags->precision > len)
			tmp = flags->precision;
		while ((--flags->width - tmp - flags->space - flags->plus) >= 0)
		{
			if (flags->zero && !flags->minus)
			{
				if ((flags->width - flags->precision) >= 0)
					ret += write(1, " ", 1);
				else
				ret += write(1, "0", 1);
			}
			else
				ret += write(1, " ", 1);
		}
	}
	if (!flags->minus)
		ret += ft_diu_printer(str, flags, len);
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