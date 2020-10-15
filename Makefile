# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 14:17:23 by lweglarz          #+#    #+#              #
#    Updated: 2020/10/15 15:01:27 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt.a

FLAGS= -Wall -Wextra -Werror

SRCS= srcs/get_next_line.c  srcs/parser.c srcs/utils.c

OBJS= get_next_line.o parser.o utils.o

RM	= rm -f

CC = cc

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) includes/minirt.h
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME) 

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all