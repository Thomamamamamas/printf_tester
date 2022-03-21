/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:55:18 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/20 13:00:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_trimline(char *save);
char	*gnl_restline(char *save);
char	*gnl_ft_strchr(char *s, int c);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
