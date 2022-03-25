/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:53:40 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/20 12:53:42 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	static char	*save[FD_MAX];
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && !gnl_ft_strchr(save[fd], '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = 0;
		save[fd] = gnl_ft_strjoin(save[fd], buf);
		if (!save[fd])
			return (NULL);
	}
	line = gnl_trimline(save[fd]);
	save[fd] = gnl_restline(save[fd]);
	return (line);
}
