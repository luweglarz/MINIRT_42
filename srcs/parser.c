/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/23 15:18:11 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_tab		g_tab[9] = {
	{RES, 1, &get_resolution}, {AMLIGHT, 1, &get_amlight}, {CAMERA, 1, &get_camera},
	{LIGHT, 1, &get_light}, {SPHERE, 2, &get_sphere}, {PLANE, 2, &get_plane},
	{SQUARE, 2, &get_square}, {CYLINDER, 2, &get_cylinder}, {TRIANLGE, 2, &get_triangle}
};

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
			(ft_strncmp(g_tab[i].data_type, data[0], g_tab[i].data_len) != 0)) // ft_strncmp a fix car je recupere un cy quand j ai seulement c par exemple
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
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret != 0 && ft_strlen(line) != 0)
			append_data(scene, line);
		free(line);
		line = NULL;
	}
}
