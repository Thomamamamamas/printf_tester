/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_debug.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:09:11 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/21 16:39:23 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	print_tester_value(t_pt *pt)
{
	printf("\n__________TESTER_VALUE___________\n");
	printf("conversion = %c\n", pt->conversion);
	printf("flag = %c\n", pt->flag);
	printf("stop = %d\n", pt->stop);
	printf("option1 = %c\n", pt->option1);
	printf("option2 = %c\n", pt->option2);
	printf("all = %d\n", pt->all);
	printf("_________________________________\n");
}
