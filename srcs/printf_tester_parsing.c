/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:47:12 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/21 19:53:44 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

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
