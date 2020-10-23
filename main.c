/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/23 13:41:31 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
#include <stdio.h>

void	init_scene(t_scene *scene)
{
	scene->resolution.h = 0;
	scene->resolution.w = 0;
	scene->amli.ratio = 0;
	scene->amli.color.r = 0;
	scene->amli.color.g = 0;
	scene->amli.color.b = 0;

	scene->camera = ft_lstnew(NULL);
	scene->light = ft_lstnew(NULL);
	scene->sphere = ft_lstnew(NULL);
	scene->plane = ft_lstnew(NULL);
	scene->square = ft_lstnew(NULL);
	scene->cylinder = ft_lstnew(NULL);
	scene->triangle = ft_lstnew(NULL);
}

int		main(int argc, char **argv)
{
	t_scene	scene;
	int		fd;

	init_scene(&scene);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		parsing_config(&scene, fd);
		close(fd);
	}
	else
		write(STDERR_FILENO, "error", 5);
}
