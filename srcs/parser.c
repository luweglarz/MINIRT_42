/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/15 14:39:32 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void        init_scene(t_scene **scene)
{
    (*scene)->resolution = NULL;
    (*scene)->amli = NULL;
    // a finir avec list chaine pour les autres config
}

t_scene     append_data(t_scene **scene, char *line)
{
    (void)scene;
    (void)line;
    //trouver un moyen de faire ca sans foret de if 
    if (line[0] == RES)
        return (get_resolution(scene, line));
    if (ft_strncmp(line, SPHERE, 2) == 0)
        return (get_sphere(scene, line));
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

