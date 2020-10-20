/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/20 12:50:57 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//fonctions qui vont recuperer les donne en parsant le tableau de data que j'envoie

t_scene *get_resolution(t_scene *scene, char **data)
{
    scene->resolution->w = ft_atoi(data[1]);
    scene->resolution->h = ft_atoi(data[2]);
    return (scene);
}

t_scene *get_amlight(t_scene *scene, char **data)
{

(void)data;
    return(scene);
}

t_scene *get_camera(t_scene *scene, char **data)
{
(void)scene;
(void)data;
    return(scene);
}

t_scene *get_light(t_scene *scene, char **data)
{
(void)scene;
(void)data;
    return(scene);
}

