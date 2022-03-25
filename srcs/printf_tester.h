/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/25 15:59:08 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_TESTER_H
# define PRINTF_TESTER_H

# include "get_next_line/get_next_line_bonus.h" 
# include "../../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pt
{
	int			conversion;
	int			flag;
	int			option1;
	int			option2;
	int			all;
	const char	*content;
	char		**argument_str;
	int			argument_str_len;
	long long	*argument_nbr;
	int			argument_nbr_len;
	int			*len_printf;
	char		**str_printf;
}				t_pt;


//printf_tester
int				count_test_line(char *conv_file, t_pt *pt);
int				test_conversion(char *conv_file, int total, t_pt *pt);
int				test_line(char *line, int n, t_pt *pt);

//printf_tester_utils
void			set_tester(t_pt *pt);
void			set_argument_array(int len, t_pt *pt);
void			check_tester_value(t_pt *pt);
char			*get_file_name(t_pt *pt);
char			**strcat_2d_array(char **s1, char **s2);

//printf_tester_parsing
void			parse_argv(int argc, char **argv, t_pt *pt);
int				start_iteration(t_pt *pt);
char			**parse_test(char *line, t_pt *pt);
char			*parse_content_conversion(char *content);
void			assign_argument(char *conversion, char **test_split, t_pt *pt);

//printf_tester_possibilities
int				possibilities_handler(t_pt *pt);
void			number_possibilities(t_pt *pt);
void			str_possibilities(t_pt *pt);
void			mix_possibilities(t_pt *pt);

//printf_tester_options
void			handle_options(t_pt *pt);
void			options_print();

//printf_tester_print
void			print_test_ok(int n);
void			print_test_not_ok(int n);

//printf_tester_debug
void			print_tester_value(t_pt *pt);

//ft_split
char			**ft_split(char const *s, char c);

//ft_printf
int				ft_printf(const char *content, ...);

#endif
