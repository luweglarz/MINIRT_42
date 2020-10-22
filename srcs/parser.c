/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/22 12:57:09 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_tab		g_tab[9] = {
	{RES, 1, &get_resolution}, {AMLIGHT, 1, &get_amlight}, {CAMERA, 1, &get_camera},
	{LIGHT, 1, &get_light}, {SPHERE, 2, &get_sphere}, {PLANE, 2, &get_plane},
	{SQUARE, 2, &get_square}, {CYLINDER, 2, &get_cylinder}, {TRIANLGE, 2, &get_triangle}
};

void	init_scene(t_scene *scene)
{
	scene->resolution.h = 0;
	scene->resolution.w = 0;
	scene->amli.ratio = 0;
	scene->amli.color.r = 0;
	scene->amli.color.g = 0;
	scene->amli.color.b = 0;
	scene->camera = NULL;
	scene->light = NULL;
	scene->sphere = NULL;
	scene->plane = NULL;
	scene->square = NULL;
	scene->cylinder = NULL;
	scene->triangle = NULL;
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
		g_tab[i].func(scene, data);
	free_data(data);
}

void	parsing_config(t_scene *scene, int fd)
{
	char	*line;
	int		ret;

	if (!(scene = malloc(sizeof(*scene))))
		write(2, "error", 5);
	init_scene(scene);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret != 0)
			append_data(scene, line);
		free(line);
		line = NULL;
	}
}
