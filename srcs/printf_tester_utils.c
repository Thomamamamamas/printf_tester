/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:48:21 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/21 19:48:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	set_tester(t_pt *pt)
{
	pt->conversion = 0;
	pt->flag = 0;
	pt->option1 = 0;
	pt->option2 = 0;
}

void	parse_arg(int argc, char **argv, t_pt *pt)
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
	str = (char *)malloc(sizeof(char) * 6);
	*str = pt->conversion;
	strcat(str, ".txt");
	return (str);
}
