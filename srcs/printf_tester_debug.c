/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_debug.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:09:11 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/23 10:41:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	print_tester_value(t_pt *pt)
{
	int	n;
	int	m;

	n = 0;
	printf("\n__________TESTER_VALUE___________\n");
	printf("conversion = %c\n", pt->conversion);
	printf("flag = %c\n", pt->flag);
	printf("option1 = %c\n", pt->option1);
	printf("option2 = %c\n", pt->option2);
	printf("all = %d\n", pt->all);
	while (pt->argument_nbr[n] && pt->argument_nbr[n] != '\0')
	{
		printf("argument_nbr %d = %lld\n", n,  pt->argument_nbr[n]);
		n++;
	}
	printf("str_len = %d\n", pt->str_len);
	m = 0;
	while (m < pt->str_len && pt->argument_str[m][0] != '\0')
	{
		n = 0;
		while (pt->argument_str[m][n] && pt->argument_str[m][n] != '\0')
		{
			printf("argument_str %d = %s\n", n, pt->argument_str[n]);
			n++;
		}
		m++;
	}
	printf("_________________________________\n");
}
