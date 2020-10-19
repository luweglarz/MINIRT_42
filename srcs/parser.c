/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/19 11:41:42 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void        init_scene(t_scene **scene)
{
    (*scene)->resolution = NULL;
    (*scene)->amli = NULL;
    (*scene)->camera = NULL;
    (*scene)->sphere = NULL;
}

void		free_data(int data_nb, char **data)
{
	int	i;

	i = 0;
	while (i < data_nb)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

t_scene     append_data(t_scene **scene, char *line)
{
    //trouver un moyen de faire ca sans foret de if 
    char **data;
    int    data_nb;

    data_nb = 0;
    data = ft_split(line, ' ');
    while (data[data_nb])
        data_nb++;
    if (data[0] == RES)
        return (get_resolution(scene, data));
    if (data[0] == AMLIGHT)
        return (get_amlight(scene, data));
    if (data[0] == CAMERA)
        return (get_camera(scene, data));
    if (data[0] == LIGHT)
        return (get_light(scene, data));
    if (data[0] == SPHERE)
        return (get_sphere(scene, data));
    if (data[0] == SQUARE)
        return (get_square(scene, data));
    if (data[0] == CYLINDER)
        return (get_cylinder(scene, data));
    if (data[0] == SQUARE)
        return (get_triangle(scene, data));
    free_data(data_nb, data);
}

//gestion d'erreur a faire ??
t_scene     *parsing_config(int fd)
{
    t_scene *scene;
    char    *line;
    int     ret;

    init_scene(&scene);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (ret != 0)
            append_data(&scene, line);
        free(line);
        line = NULL;
    }
    return (scene);
}

