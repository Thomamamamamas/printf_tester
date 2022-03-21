/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/21 19:50:15 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef PRINTF_TESTER_H
# define PRINTF_TESTER_H

# include "get_next_line/get_next_line.h" 
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_pt
{
	int			conversion;
	int			flag;
	int			stop;
	int			option1;
	int			option2;
	int			all;
	const char	*content;
}				t_pt;

//printf_tester
int				count_test_line(char *conv_file, t_pt *pt);
int				test_conversion(char *conv_file, t_pt *pt);

//printf_tester_utils
void			set_tester(t_pt *pt);
void			check_tester_value(t_pt *pt);
void			parse_arg(int argc, char **argv, t_pt *pt);
char			*get_file_name(t_pt *pt);

//printf_tester_parsing
int				start_iteration(t_pt *pt);

//printf_tester_debug
void			print_tester_value(t_pt *pt);

//ft_printf
int	ft_printf(const char *content, ...);

# endif
