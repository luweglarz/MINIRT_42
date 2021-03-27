/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/25 22:54:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tab		g_tab[9] = {
	{SPHERE, 2, &get_sphere}, {PLANE, 2, &get_plane},
	{SQUARE, 2, &get_square}, {CYLINDER, 2, &get_cylinder},
	{TRIANLGE, 2, &get_triangle}, {RES, 1, &get_resolution},
	{AMLIGHT, 1, &get_amlight}, {CAMERA, 1, &get_camera},
	{LIGHT, 1, &get_light}
};

void	init_scene(t_scene *scene)
{
	scene->line = NULL;
	scene->gnl = NULL;
	scene->reso.h = 0;
	scene->reso.w = 0;
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

void	free_data(char **data)
{
	int		i;
	int		data_nb;

	i = 0;
	data_nb = 0;
	while (data[data_nb])
		data_nb++;
	while (i < data_nb)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	append_data(t_scene *scene, char *line)
{
	char	**data;
	int		i;

	data = ft_split(line, ' ');
	i = 0;
	while ((i < 9) &&
			(ft_strncmp(g_tab[i].data_type, data[0], g_tab[i].data_len) != 0))
		i++;
	if (i <= 9)
		g_tab[i].tab_elem(scene, data);
	free_data(data);
}

t_scene	parsing_config(int fd, t_scene scene)
{
	int		ret;

	while ((ret = get_next_line(fd, &scene.line, &scene)) > 0)
	{
		if (ret != 0 && ft_strlen(scene.line) != 0)
			append_data(&scene, scene.line);
		free(scene.line);
		scene.line = NULL;
	}
	free(scene.line);
	return (scene);
}
