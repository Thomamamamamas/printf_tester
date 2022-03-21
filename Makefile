# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:36:41 by tcasale           #+#    #+#              #
#    Updated: 2022/03/21 19:50:05 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 'printf_tester'

CONV	= 'c'
FLAG	= ''

SRCS	= ./srcs/printf_tester.c \
		./srcs/printf_tester_utils.c \
		./srcs/printf_tester_parsing.c \
		./srcs/printf_tester_debug.c

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

PRINTF	= ../ft_printf

%.o: %.c
		${CC} ${CFLAGS} -I./srcs/get_next_line/get_next_line.a -c $< -o $@

all :			$(NAME)

$(NAME) :		$(OBJS) get_next_line ft_printf 
				$(CC) $(OBJS) ./srcs/get_next_line/get_next_line.a -o $(NAME)


get_next_line :
				$(MAKE) -C ./srcs/get_next_line

ft_printf :
				$(MAKE) -C $(PRINTF)

clean :			rm -f ${OBJS}
				$(MAKE) -C ./srcs/get_next_line $@
				$(MAKE) -C $(PRINTF) $@

fclean :		clean
				rm -f $(NAME)
				$(MAKE) -C ./srcs/get_next_line $@
				$(MAKE) -C $(PRINTF) $@

re :			fclean all

.PHONHY :		all clean fclean re
