# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 14:17:23 by lweglarz          #+#    #+#              #
#    Updated: 2020/10/20 12:57:35 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt.a

FLAGS= -Wall -Wextra -Werror

SRCS= srcs/ft_split.c srcs/get_next_line.c srcs/get_scene_elements.c srcs/get_scene_objects.c srcs/parser.c srcs/utils.c

OBJS= ft_split.o get_next_line.o get_scene_elements.o get_scene_objects.o parser.o utils.o

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