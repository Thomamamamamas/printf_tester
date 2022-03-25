/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:01 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 16:07:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_tester.h"

int	count_test_line(char *conv_file, t_pt *pt)
{
	int		fd;
	int		i;
	int		res;
	char	*line;

	fd = open(conv_file, O_RDONLY);
	i = 0;
	res = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\n' && i <= start_iteration(pt))
	{
		line = get_next_line(fd);
		if (i == start_iteration(pt) && strchr(line, '%'))
			res++;
		if (line[0] == '\n')
			i++;
	}
	while (line)
		line = get_next_line(fd);
	free(line);
	close(fd);
	return (res);
}

int	test_conversion(char *conv_file, int total, t_pt *pt)
{
	int		fd;
	int		n;
	int		i;
	int		res;
	char	*line;

	fd = open(conv_file, O_RDONLY);
	n = 0;
	i = 0;
	res = 0;
	line = get_next_line(fd);
	while (line[0] != '\n' && n < total)
	{
		line = get_next_line(fd);
		if (i == start_iteration(pt) && strchr(line, '%'))
		{
			res += test_line(line, n, pt);
			n++;
		}
		if (line[0] == '\n')
			i++;
	}
	free(line);
	close(fd);
	return (res);
}

int	test_line(char *line, int n, t_pt *pt)
{
	char	**test_split;
	char	*conversion;
	int		res;

	test_split = parse_test(line, pt);
	if (!test_split[0])
		return (0);
	conversion = parse_content_conversion(test_split[0]);
	if (!conversion[0])
		return (0);
	assign_argument(conversion, test_split, pt);
	res = possibilities_handler(pt);
	if (res == 1)
		print_test_ok(n);
	else
		print_test_not_ok(n);
	return (res);
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
	parse_argv(argc, argv, &pt);
	check_tester_value(&pt);
	conv_file = get_file_name(&pt);
	total = count_test_line(conv_file, &pt);
	res = test_conversion(conv_file, total, &pt);
	printf("resultat %d/%d\n", res, total);
	return (0);
}
