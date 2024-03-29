/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:37:34 by vscabell          #+#    #+#             */
/*   Updated: 2020/07/29 18:49:13 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_breakline(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static int	ft_newline(char **str, char **line, int i, char *buffer)
{
	char *aux;

	*line = ft_substr(*str, 0, i);
	aux = ft_substr(*str, i + 1, ft_strlen(*str) - i);
	free(*str);
	*str = aux;
	if (*str && *str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	free(buffer);
	buffer = NULL;
	return (1);
}

static int	ft_endoffile(char **str, char **line, char *buffer)
{
	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
		*line = ft_strdup("");
	free(buffer);
	buffer = NULL;
	return (0);
}

static int	ft_gnl(char **line, int fd, char *buffer)
{
	static char	*str[OPEN_MAX];
	char		*aux;
	int			posit;
	int			ret;

	if (str[fd] && (posit = ft_breakline(str[fd], '\n')) != -1)
		return (ft_newline(&str[fd], line, posit, buffer));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = aux;
		}
		if ((posit = ft_breakline(str[fd], '\n')) >= 0)
			return (ft_newline(&str[fd], line, posit, buffer));
	}
	return (ft_endoffile(&str[fd], line, buffer));
}

int			get_next_line(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *))))
		return (-1);
	return (ft_gnl(line, fd, buffer));
}
