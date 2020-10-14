/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:52:23 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/14 15:48:29 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void        init_scene(t_scene *scene)
{
    scene->resolution.h = 0;
    scene->resolution.w = 0;
    scene->amli.ratio = 0;  
    scene->amli.color.r = 0;
    scene->amli.color.g = 0;
    scene->amli.color.b = 0;
    
}

int         append_data(t_scene **scene, char *line)
{
    //fonction d'attribution des donne recuperer avec get next line
}

t_scene     *parsing_config(int fd)
{
    t_scene *scene;
    char    *line;
    int     ret;
    init_scene(scene);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (!(ret = append_data(&scene, line)) == -1)
            return (NULL);
        free(line);
    }
    return (scene);
}

