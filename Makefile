# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 14:17:23 by lweglarz          #+#    #+#              #
#    Updated: 2021/02/10 17:10:10 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME=minirt.a

FLAGS= -Wall -Wextra -Werror

SRCS=   srcs/parser/get_scene_elements.c srcs/parser/get_scene_objects.c srcs/parser/parser.c srcs/utils/lib/lst_func.c srcs/raytracer/light.c \
		srcs/utils/lib/libftfunctions1.c srcs/utils/lib/libftfunctions2.c srcs/utils/lib/get_next_line.c srcs/utils/lib/ft_split.c srcs/raytracer/raytosphere.c \
		srcs/utils/utilsdata.c srcs/utils/vector/vector1.c srcs/utils/vector/vector2.c srcs/parser/parsing_error.c srcs/utils/displayutils.c srcs/raytracer/raytracer.c \
		main.c srcs/utils/color/color1.c srcs/utils/color/color2.c srcs/raytracer/raytoplane.c

RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) includes/minirt.h

	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
