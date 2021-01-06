# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 14:17:23 by lweglarz          #+#    #+#              #
#    Updated: 2021/01/06 14:08:25 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME=minirt.a

FLAGS= -Wall -Wextra -Werror

SRCS=   srcs/get_scene_elements.c srcs/get_scene_objects.c srcs/parser.c srcs/lst_func.c \
		srcs/utils/utils1.c srcs/utils/utils2.c srcs/utils/get_next_line.c srcs/utils/ft_split.c \
		srcs/utils/utilsdata.c srcs/parsing_error.c

RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) includes/minirt.h

	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) main.c minirt.a

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all