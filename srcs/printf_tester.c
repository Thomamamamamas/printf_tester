/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:01 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/21 19:49:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

int	count_test_line(char *conv_file, t_pt *pt)
{
	int		fd;
	int		i;
	int		res;
	char	*str;

	fd = open(conv_file, O_RDONLY);
	i = 0;
	res = 0;
	str = get_next_line(fd);
	while (str[0] != '\n' && i < start_iteration(pt))
	{
		str = get_next_line(fd);
		if (i < start_iteration(pt))
		{

		}
		else
			res++;
	}
	free(str);
	close(fd);
	return (res);
}

int	test_conversion(char *conv_file, t_pt *pt)
{
	int	fd;

	fd = open(conv_file, O_RDONLY);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int		res;
	int		total;
	char	*conv_file;
	t_pt	pt;

	res = 0;
	if (argc < 2)
		return (1);
	set_tester(&pt);
	parse_arg(argc, argv, &pt);
	check_tester_value(&pt);
	print_tester_value(&pt);
	conv_file = get_file_name(&pt);
	printf("\n %s\n", conv_file);
	total = count_test_line(conv_file, &pt);
	printf("\n%d\n", total);
	res = test_conversion(conv_file, &pt);
	printf("\n%d\n", res);
	return (0);
}
