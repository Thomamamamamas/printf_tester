/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:47:12 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/24 18:33:21 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	parse_argv(int argc, char **argv, t_pt *pt)
{
	int	n;

	n = 1;
	while (n < argc)
	{
		if (n == 1)
			pt->conversion = argv[n][0];
		else if (n == 2)
			pt->flag = argv[n][0];
		else if (n == 3)
			pt->option1 = argv[n][0];
		else if (n == 4)
			pt->option2 = argv[n][0];
		n++;
	}
}

int	start_iteration(t_pt *pt)
{
	if (pt->all >= 1)
		return (0);
	else if (pt->flag == '-')
		return (2);
	else if (pt->flag == '+')
		return (3);
	else if (pt->flag == ' ')
		return (4);
	else if (pt->flag == '0')
		return (5);
	else if (pt->flag == '.')
		return (6);
	else if (pt->flag == '#')
		return (7);
	return (0);
}

char	**parse_test(char *line, t_pt *pt)
{
	char	**tmp;
	char	**tmp2;
	char	**str;
	int		len_tmp2;
	int		n;

	tmp = ft_split(line, ';');
	pt->content = strdup(tmp[0]);
	tmp2 = ft_split(tmp[1], ',');
	len_tmp2 = 0;
	while (tmp2[len_tmp2] != NULL)
		len_tmp2++;
	str = (char **)malloc(sizeof(char *) * (1 + len_tmp2) + 1);
	if (!str)
		return (NULL);
	n = 0;
	while (n < len_tmp2 + 1)
	{
		if (n == 0)
			str[0] = strdup(tmp[0]);
		else
			str[n] = strdup(tmp2[n - 1]);
		n++;
	}
	free(tmp);
	free(tmp2);
	return (str);
}

char	*parse_content_conversion(char *content)
{
	int		n;
	int		len;
	char	*str;

	n = 0;
	len = 0;
	while (content[n])
	{
		if (content[n++] == '%')
			len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	n = 0;
	len = 0;
	while (content[n])
	{
		if (content[n++] == '%')
			str[len++] = content[n];
	}
	str[n] = '\0';
	return (str);
}

void	assign_argument(char *conversion, char **test_split, t_pt *pt)
{
	int	n;

	n = 0;
	set_argument_array((int)strlen(conversion), pt);
	while (conversion[n] && test_split[n + 1] && n < (int)strlen(conversion))
	{
		if (conversion[n] == 'c' || conversion[n] == 'd' || conversion[n] == 'i' || conversion[n] == '%')
		{
			pt->argument_nbr[n] = atoi(test_split[n + 1]);
			pt->argument_nbr_len++;
		}
		else if (conversion[n] == 'p' || conversion[n] == 'x' || conversion[n] == 'X')
		{
			pt->argument_nbr[n] = atoi(test_split[n + 1]);
			pt->argument_nbr_len++;
		}
		else if (conversion[n] == 's')
		{
			pt->argument_str[n] = strdup(test_split[n + 1]);
			pt->argument_str_len++;
		}
		n++;
	}
	pt->argument_str[n] = NULL;
	pt->argument_nbr[n] = 0;
}
