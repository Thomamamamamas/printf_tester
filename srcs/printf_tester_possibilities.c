/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_possibilities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:55 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 16:23:57 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

int	possibilities_handler(t_pt *pt)
{
	if (!pt->argument_str[0])
		number_possibilities(pt);
	else if (!pt->argument_nbr)
		str_possibilities(pt);
	else
		mix_possibilities(pt);
	handle_options(pt);
	if (pt->len_printf[0] == pt->len_printf[1])
		return (1);
	return (0);
}

void	number_possibilities(t_pt *pt)
{
	printf("\nargument = %lld\n", pt->argument_nbr[0]);
	printf("\nargument len = %d\n", pt->argument_nbr_len);
	freopen("printf_output.txt", "w+", stdout);
	if (pt->argument_nbr_len == 1)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0]);
		freopen("ft_printf_output.txt", "w+", stdout);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0]);
	}
	if (pt->argument_nbr_len == 2)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1]);
		freopen("ft_printf_output.txt", "w+", stdout);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1]);
	}
	if (pt->argument_nbr_len == 3)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2]);
		freopen("ft_printf_output.txt", "w+", stdout);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2]);
	}
	if (pt->argument_nbr_len == 4)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2], pt->argument_nbr[3]);
		freopen("ft_printf_output.txt", "w+", stdout);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2], pt->argument_nbr[3]);
	}
	if (pt->argument_nbr_len == 5)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2], pt->argument_nbr[3], pt->argument_nbr[4]);
		freopen("ft_printf_output.txt", "w+", stdout);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0], pt->argument_nbr[1], pt->argument_nbr[2], pt->argument_nbr[3], pt->argument_nbr[4]);
	}
	freopen("/dev/tty", "a", stdout);
}

void	str_possibilities(t_pt *pt)
{
	if (pt->argument_nbr_len == 1)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0]);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0]);
	}
}

void	mix_possibilities(t_pt *pt)
{
	if (pt->argument_nbr_len == 1)
	{
		pt->len_printf[0] = printf(pt->content, pt->argument_nbr[0]);
		pt->len_printf[1] = ft_printf(pt->content, pt->argument_nbr[0]);
	}
}
