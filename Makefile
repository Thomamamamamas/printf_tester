# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:36:41 by tcasale           #+#    #+#              #
#    Updated: 2022/03/25 15:53:07 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 'printf_tester'

CONV	= 'c'
FLAG	= ''

SRCS	= ./srcs/printf_tester.c \
		./srcs/printf_tester_utils.c \
		./srcs/printf_tester_parsing.c \
		./srcs/printf_tester_debug.c \
		./srcs/printf_tester_possibilities.c \
		./srcs/printf_tester_options.c \
		./srcs/printf_tester_print.c \
		./srcs/ft_split.c

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

PRINTF	= ../ft_printf

%.o: %.c
		${CC} ${CFLAGS} -I./srcs/get_next_line/get_next_line.a -I./$(PRINTF)/libftprintf.a -c $< -o $@

all :			$(NAME)

$(NAME) :		$(OBJS) get_next_line ft_printf 
				$(CC) $(OBJS) ./srcs/get_next_line/get_next_line.a  ./$(PRINTF)/libftprintf.a -o $(NAME)


get_next_line :
				$(MAKE) -C ./srcs/get_next_line

ft_printf :
				$(MAKE) -C $(PRINTF)

clean :
				${RM} ${OBJS}
				$(MAKE) -C ./srcs/get_next_line $@
				$(MAKE) -C $(PRINTF) $@

fclean :		clean
				rm -f $(NAME)
				$(MAKE) -C ./srcs/get_next_line $@
				$(MAKE) -C $(PRINTF) $@

re :			fclean all

.PHONHY :		all clean fclean re
