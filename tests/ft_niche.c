/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_niche.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:34:44 by altikka           #+#    #+#             */
/*   Updated: 2022/07/01 15:53:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
int	ft_printf(const char *str, ...);

int	main(void)
{
	ft_printf("hello world\n");
	ft_printf("something %s\n", NULL);
	ft_printf("%s\n", NULL);
	ft_printf("hello world %s grrr\n", "str");
	ft_printf("hello world %s grrr\n", NULL);
	ft_printf("%s %s %s\n", "str", "str", NULL);
	ft_printf("%X\n", 1234);
	ft_printf("%p\n", "string");
	ft_printf("%x\n", 00);
	ft_printf("%f\n", (float) 5);
	ft_printf("%lu\n", sizeof(float));
	ft_printf("%f\n", 9.999999);
	ft_printf("%f\n", 1.3354);
	ft_printf("%f\n", 9.9999999);
	ft_printf("%.0f\n", 0.5);
	ft_printf("%.0f\n", 1.5);
	ft_printf("%.0f\n", 2.5);
	ft_printf("%.0f\n", 3.5);
	ft_printf("%.0f\n", 4.5);
	ft_printf("%.0f\n", 5.5);
	ft_printf("%010.12d\n", 33);
	ft_printf("%.d\n", 3);
	ft_printf("%.d\n", 0);
	ft_printf("%.3d\n", 3);
	ft_printf("%.10d\n", 3);
	ft_printf("%.2d\n", 300);
	ft_printf(" %.d\n", 4);
	ft_printf(" %.00000000d\n", 4);
	ft_printf(" %.4d\n", 4);
	ft_printf(" %.20d\n", 4);
	ft_printf("%u\n", -100);
	ft_printf("%.18f\n", 0.0005f);
	ft_printf("%.3d\n", -3);
	ft_printf("%d\n", -3);
	ft_printf("%000d\n", -3);
	ft_printf("%4.3d\n", -2);
	ft_printf("%4d\n", -2);
	ft_printf("\t/%#8.2o/\t/%#8.2o/\t/%#8.2o/\n", 0, 17, 1234);
	ft_printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234);
	ft_printf("\t/%#8.5o/\t/%#8.5o/\t/%#8.5o/\n", 0, 17, 1234);
	ft_printf("%%%");
	ft_printf("\n");
	ft_printf("%hh\n", 7);
	ft_printf("%+10f\n", 1.0 / 0);
	ft_printf("%-10f\n", 0.0 / 0.0);
	ft_printf("%+Lf\n", (long double)(1.0 / 0));
	ft_printf("%+10f\n", -1.0 / 0);
	ft_printf("%f\n", 0.0 / 0.0);
	ft_printf("%+f\n", 0.0 / 0.0);
	ft_printf("% f\n", 0.0 / 0.0);
	ft_printf("%-10f\n", 0.0 / 0.0);
	ft_printf("%10f\n", 0.0 / 0.0);
	ft_printf("%1f\n", 0.0 / 0.0);
	ft_printf("%f\n", -0.0 / 0.0);
	ft_printf("%.6f\n", -0.0 / 0.0);
	ft_printf("%.2f\n", -0.0 / 0.0);
	ft_printf("%10.5f\n", 0.0 / 0.0);
	ft_printf("%f / %f / %f\n", (1.0 / 0), -0.0, (0.0 / 0.0));
	ft_printf("%f / %f / %f\n", 0.0, -0.0, (-1.0 / 0));
	ft_printf("%#+10f\n", 1.0 / 0);
	ft_printf("%#-10f\n", 0.0 / 0.0);
	ft_printf("%#+Lf\n", (long double)(1.0 / 0));
	ft_printf("%#+10f\n", -1.0 / 0);
	ft_printf("%#f\n", 0.0 / 0.0);
	ft_printf("%#+f\n", 0.0 / 0.0);
	ft_printf("% #f\n", 0.0 / 0.0);
	ft_printf("%-#10f\n", 0.0 / 0.0);
	ft_printf("%0+f\n", 0.0 / 0.0);
	ft_printf("% 0f\n", 0.0 / 0.0);
	ft_printf("%-010f\n", 0.0 / 0.0);
	ft_printf("%010f\n", 0.0 / 0.0);
	ft_printf("%01f\n", 0.0 / 0.0);
	ft_printf("%0f\n", -0.0 / 0.0);
	ft_printf("%0.6f\n", -0.0 / 0.0);
	ft_printf("%0.2f\n", -0.0 / 0.0);
	ft_printf("%010.5f\n", 0.0 / 0.0);
	ft_printf("%0f / %0f / %0f\n", (1.0 / 0), -0.0, (0.0 / 0.0));
	ft_printf("%0f / %0f / %0f\n", 0.0, -0.0, (-1.0 / 0));
	ft_printf("%+10.3u\n", 1);
	ft_printf("%+010.5u\n", 895);
	ft_printf("% 10.5u\n", 895);
	ft_printf("%#.f\n", 0.545);
	ft_printf("%#.Lf\n", 0.51);
	ft_printf("%.Lf\n", 0.51l);
	ft_printf("%c% 06.4x%c\n", '{', 1, '}');
	ft_printf("%0#30x\n", 0);
	ft_printf("%#03o\n", 0);
	ft_printf("%0#3o\n", 0);
	ft_printf("%012.9d\n", 0);
	ft_printf("%+012.0d\n", 0);
	ft_printf("%#8d\n", 66);
	ft_printf("%#08d\n", 66);
	ft_printf("%#10d\n", 33);
	ft_printf("%#010d\n", 33);
	return (0);
}

