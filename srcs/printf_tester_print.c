/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:53:11 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 16:21:12 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

void	print_test_ok(int n)
{
	printf("\033[0;32m %d: OK ", n + 1);
	printf("\033[0;37m");
}

void	print_test_not_ok(int n)
{
	printf("\033[0;31m %d: OK ", n + 1);
	printf("\033[0;37m");
}
