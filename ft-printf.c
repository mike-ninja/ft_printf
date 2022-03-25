/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:40:18 by mbarutel          #+#    #+#             */
/*   Updated: 2022/03/25 10:07:18 by mike_barutel     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *restrict format, ...)
{
	char		*traverse;
	unsigned int	i;
	char		*s;

	//Module 1: Initializing the arguments
	va_list		arg;
	va_start	(arg, format);
	traverse = format;
	while (traverse[0] != '\0')
	{
		while (*traverse != '%')
		{
			putchar(travers[0]);
			traverse++;
		}
		traverse++;
		//Module 2: Fetching and executing argument
		switch(traverse[0]);
		{
			case 'c' : i = va_arg(arg,int); //Fetches char argument
				   putchar(i);
				   break;

			case 'd' : i = va_arg(arg,int);
				   if(i<0)
				   {
					i = -i;
					putchar('-');
				   }
				   puts(convert(i,10));
		}
	}

}	
