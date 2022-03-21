/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:55:06 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/20 12:55:27 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*gnl_trimline(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*gnl_restline(char *save)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
	{
		line = malloc(sizeof(char) * (gnl_ft_strlen(save) - i + 1));
		if (!line)
			return (NULL);
		while (save[i])
			line[j++] = save[++i];
		line[j] = 0;
		free(save);
		return (line);
	}
	else
	{
		free(save);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && !gnl_ft_strchr(save, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = 0;
		save = gnl_ft_strjoin(save, buf);
		if (!save)
			return (NULL);
	}
	line = gnl_trimline(save);
	save = gnl_restline(save);
	return (line);
}
