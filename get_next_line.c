/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:37:34 by vscabell          #+#    #+#             */
/*   Updated: 2020/02/18 17:35:37 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_breakline(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_newline(char **str, char **line, int i)
{
	char *aux;

	*line = ft_substr(*str, 0, i);
	aux = ft_substr(*str, i + 1, ft_strlen(*str) - i);
	free (*str);
	*str = aux;
	if (*str && *str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int	ft_endoffile(char **str, char **line)
{

	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}


int get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char *str;
	int			ret;
	char		*aux;
	int			posit;

	if (fd < 0 || !*line || BUFFER_SIZE < 1)
		return (-1);
	if (str && (posit = ft_breakline(str, '\n')) != -1)
		return (ft_newline(&str, line, posit));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(str, buffer);
			free(str);
			str = aux;
		}
		if ((posit = ft_breakline(str, '\n')) != -1)
			return (ft_newline(&str, line, posit));
	}
	return (ft_endoffile(&str, line));
}


/*
 fd retorno do open
 -1 erro
 0
 1
 2
 3 começa a enumerar os arquivos daqui por diante
 */


