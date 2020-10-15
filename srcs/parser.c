/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/15 16:32:23 by lweglarz         ###   ########.fr       */
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

t_scene     append_data(t_scene **scene, char *line)
{
    //trouver un moyen de faire ca sans foret de if 
    // utilister ft_split ?
    char **data;
    data = ft_split(line, ' '); // add une fonction qui detecte les espaces
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
    // ainsi de suite
}

//gestion d'erreur a faire ??
t_scene     *parsing_config(int fd)
{
    t_scene *scene;
    char    *line;
    int     ret;
    fd = 0;
    init_scene(&scene);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (ret != -1)
            append_data(&scene, line);
        free(line);
    }
    return (scene);
}

