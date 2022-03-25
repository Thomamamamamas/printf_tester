/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:46:39 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 15:48:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	handle_options(t_pt *pt)
{
	if (pt->option1 == 'p' || pt->option2 == 'p' || pt->flag == 'p')
		options_print(pt);
}

void	options_print()
{
	int		fd;
	char	*tmp;
	char	*tmp2;
	char	*str;

	fd = open("printf_output.txt", O_RDONLY);
	str = (char*)malloc(sizeof(char) * 1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		tmp2 = (char *)malloc(sizeof(char) * ((int)strlen(tmp) + (int)strlen(str)) + 1);
		strcat(tmp2, tmp);
		strcat(tmp2, str);
		free(str);
		str = ft_strdup(tmp2);
		free(tmp2);
		tmp = get_next_line(fd);
	}
	printf("printf :\n%s\n", str);
	close(fd);
	free(str);
	fd = open("ft_printf_output.txt", O_RDONLY);
	str = (char *)malloc(sizeof(char) * 1);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		tmp2 = (char *)malloc(sizeof(char) * ((int)strlen(tmp) + (int)strlen(str)) + 1);
		strcat(tmp2, tmp);
		strcat(tmp2, str);
		free(str);
		str = ft_strdup(tmp2);
		free(tmp2);
		tmp = get_next_line(fd);
	}
	printf("ft_printf :\n%s\n", str);
	free(str);
	free(tmp);
	close(fd);
}
