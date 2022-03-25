/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:48:21 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 16:28:30 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	set_tester(t_pt *pt)
{
	pt->conversion = 0;
	pt->flag = 0;
	pt->option1 = 0;
	pt->option2 = 0;
	pt->argument_str_len = 0;
	pt->argument_nbr_len = 0;
}

void	set_argument_array(int len, t_pt *pt)
{
	if (pt->argument_nbr)
		free(pt->argument_nbr);
	if (pt->argument_str)
		free(pt->argument_str);
	pt->argument_nbr = (long long *)malloc(sizeof(long long) * len);
	pt->argument_str = (char **)malloc(sizeof(char *) * len);
	pt->len_printf = (int *)malloc(sizeof(int) * 2);
	pt->argument_str_len = 0;
	pt->argument_nbr_len = 0;
}

void	check_tester_value(t_pt *pt)
{
	if (pt->conversion == 'm' || pt->conversion == 'b')
	{
		pt->all = 1;
		pt->conversion = 'c';
	}
}

char	*get_file_name(t_pt *pt)
{
	char	*str;
	char	*tmp;

	if (pt->all > 1)
	{
		if (pt->conversion == 'c')
			pt->conversion = 's';
		else if (pt->conversion == 's')
			pt->conversion = 'p';
		else if (pt->conversion == 'p')
			pt->conversion = 'd';
		else if (pt->conversion == 'd')
			pt->conversion = 'i';
		else if (pt->conversion == 'i')
			pt->conversion = 'u';
		else if (pt->conversion == 'u')
			pt->conversion = 'x';
		else if (pt->conversion == 'x')
			pt->conversion = 'X';
		else if (pt->conversion == 'X')
			pt->conversion = '%';
	}
	str = (char *)malloc(sizeof(char) * 13);
	tmp = (char *)malloc(sizeof(char) * 6);
	str = strcat(str, "tests/");
	*tmp = pt->conversion;
	strcat(tmp, ".txt");
	strcat(str, tmp);
	free(tmp);
	return (str);
}
