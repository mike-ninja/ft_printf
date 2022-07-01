/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niche.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:11:04 by altikka           #+#    #+#             */
/*   Updated: 2022/07/01 15:53:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>


int	main(void)
{
	printf("hello world\n");
	printf("something %s\n", NULL);
	printf("%s\n", NULL);
	printf("hello world %s grrr\n", "str");
	printf("hello world %s grrr\n", NULL);
	printf("%s %s %s\n", "str", "str", NULL);
	printf("%X\n", 1234);
	printf("%p\n", "string");
	printf("%x\n", 00);
	printf("%f\n", (float) 5);
	printf("%lu\n", sizeof(float));
	printf("%f\n", 9.999999);
	printf("%f\n", 1.3354);
	printf("%f\n", 9.9999999);
	printf("%.0f\n", 0.5);
	printf("%.0f\n", 1.5);
	printf("%.0f\n", 2.5);
	printf("%.0f\n", 3.5);
	printf("%.0f\n", 4.5);
	printf("%.0f\n", 5.5);
	printf("%010.12d\n", 33);
	printf("%.d\n", 3);
	printf("%.d\n", 0);
	printf("%.3d\n", 3);
	printf("%.10d\n", 3);
	printf("%.2d\n", 300);
	printf(" %.d\n", 4);
	printf(" %.00000000d\n", 4);
	printf(" %.4d\n", 4);
	printf(" %.20d\n", 4);
	printf("%u\n", -100);
	printf("%.18f\n", 0.0005f);
	printf("%.3d\n", -3);
	printf("%d\n", -3);
	printf("%000d\n", -3);
	printf("%4.3d\n", -2);
	printf("%4d\n", -2);
	printf("\t/%#8.2o/\t/%#8.2o/\t/%#8.2o/\n", 0, 17, 1234);
	printf("\t/%#8.4o/\t/%#8.4o/\t/%#8.4o/\n", 0, 17, 1234);
	printf("\t/%#8.5o/\t/%#8.5o/\t/%#8.5o/\n", 0, 17, 1234);
	printf("%%%");
	printf("\n");
	printf("%hh\n", 7);
	printf("%+10f\n", 1.0 / 0);
	printf("%-10f\n", 0.0 / 0.0);
	printf("%+Lf\n", (long double)(1.0 / 0));
	printf("%+10f\n", -1.0 / 0);
	printf("%f\n", 0.0 / 0.0);
	printf("%+f\n", 0.0 / 0.0);
	printf("% f\n", 0.0 / 0.0);
	printf("%-10f\n", 0.0 / 0.0);
	printf("%10f\n", 0.0 / 0.0);
	printf("%1f\n", 0.0 / 0.0);
	printf("%f\n", -0.0 / 0.0);
	printf("%.6f\n", -0.0 / 0.0);
	printf("%.2f\n", -0.0 / 0.0);
	printf("%10.5f\n", 0.0 / 0.0);
	printf("%f / %f / %f\n", (1.0 / 0), -0.0, (0.0 / 0.0));
	printf("%f / %f / %f\n", 0.0, -0.0, (-1.0 / 0));
	printf("%#+10f\n", 1.0 / 0);
	printf("%#-10f\n", 0.0 / 0.0);
	printf("%#+Lf\n", (long double)(1.0 / 0));
	printf("%#+10f\n", -1.0 / 0);
	printf("%#f\n", 0.0 / 0.0);
	printf("%#+f\n", 0.0 / 0.0);
	printf("% #f\n", 0.0 / 0.0);
	printf("%-#10f\n", 0.0 / 0.0);
	printf("%0+f\n", 0.0 / 0.0);
	printf("% 0f\n", 0.0 / 0.0);
	printf("%-010f\n", 0.0 / 0.0);
	printf("%010f\n", 0.0 / 0.0);
	printf("%01f\n", 0.0 / 0.0);
	printf("%0f\n", -0.0 / 0.0);
	printf("%0.6f\n", -0.0 / 0.0);
	printf("%0.2f\n", -0.0 / 0.0);
	printf("%010.5f\n", 0.0 / 0.0);
	printf("%0f / %0f / %0f\n", (1.0 / 0), -0.0, (0.0 / 0.0));
	printf("%0f / %0f / %0f\n", 0.0, -0.0, (-1.0 / 0));
	printf("%+10.3u\n", 1);
	printf("%+010.5u\n", 895);
	printf("% 10.5u\n", 895);
	printf("%#.f\n", 0.545);
	printf("%#.Lf\n", 0.51);
	printf("%.Lf\n", 0.51l);
	printf("%c% 06.4x%c\n", '{', 1, '}');
	printf("%0#30x\n", 0);
	printf("%#03o\n", 0);
	printf("%0#3o\n", 0);
	printf("%012.9d\n", 0);
	printf("%+012.0d\n", 0);
	printf("%#8d\n", 66);
	printf("%#08d\n", 66);
	printf("%#10d\n", 33);
	printf("%#010d\n", 33);
	return(0);
}

