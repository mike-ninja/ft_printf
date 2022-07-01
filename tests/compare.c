/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:07:51 by atenhune          #+#    #+#             */
/*   Updated: 2022/06/03 17:31:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define GREEN  "\x1B[32m"
#define RED  "\x1B[31m"
#define KMAG  "\x1B[35m"

int main(int argc, char **argv)
{
	char buff[100000];
	int fd;
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	int lasku = 0;
	int read_ret;
	int offset = 20;

	printf("\n%s%s:\n", KMAG, argv[2]);
	fd = open(argv[1], O_RDONLY);
	read_ret = read(fd, buff, 10000);
	while(i < read_ret)
	{
		if(count % 30 == 0 && j != 1)
		{
			printf("\n");
			j = 1;
		}
		if(buff[i]=='\n')
		{
			if (k != 1)
				printf("%s[OK]", GREEN);
			k = 0;
			lasku++;
			count++;
			j = 0; 
		}
		if(buff[i]== '|')
		{
			printf("%s[KO](%d)", RED, count + offset);
			k = 1;
			j = 0; 
		}
		i++;
	}
	printf("\n\n%s%d / %d\n", KMAG, lasku, count);
	close(fd);


}
