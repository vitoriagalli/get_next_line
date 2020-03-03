/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:01:45 by vscabell          #+#    #+#             */
/*   Updated: 2020/02/19 10:57:37 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int fd;
	int ret;
	char *line;

	fd = open("1.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
		printf("%s\nreturn %i\n\n", line, ret);
	if (ret == 0)
		printf("%s\nreturn %i\n", line, ret);
}



/*
int main ()
{
	//int fd1;
	//int fd2;
	//int fd3;
	//int fd4;
	//int fd5;
	int fd6;
	int	ret;
	char *line;

	//fd1 = open("teste1", O_RDONLY);
	//fd2 = open("teste2", O_RDONLY);
//	fd3 = open("teste3", O_RDONLY); //sem quebra de linha
	//fd4 = open("teste4", O_RDONLY); //apenas a quebra de linha
	//fd5 = open("teste5", O_RDONLY); //arq vazio sem quebra de linha RET 0
	fd6 = open("2.txt", O_RDONLY);

	printf("--- arq 1 ---\n");
	while ((ret = get_next_line(fd1, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);

	printf("--- arq 2 ---\n");
	while ((ret = get_next_line(fd2, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);

	printf("--- arq 3 ---   no newline\n");
	while ((ret = get_next_line(fd3, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);

	printf("--- arq 4 ---   just new line\n");
	while ((ret = get_next_line(fd4, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);

	printf("--- arq 5 ---\n");
	while ((ret = get_next_line(fd5, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);

	printf("--- arq 6 ---\n");
	while ((ret = get_next_line(fd6, &line)) == 1)
		printf("%s\nreturn %i\n", line, ret);


}

int main (void)
{
	int fd1;
	int fd2;
	char *line;

	fd1 = open("teste1", O_RDONLY);
	fd2 = open("teste2", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);

}


*/
