/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/22 12:48:44 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_resolution(t_scene *scene, char **data)
{
	scene->resolution.h = ft_atoi(data[1]);
	scene->resolution.w = ft_atoi(data[2]);
}

void	get_amlight(t_scene *scene, char **data)
{
	(void)scene;
	(void)data;
}

void	get_camera(t_scene *scene, char **data)
{
	(void)scene;
	(void)data;
}

void	get_light(t_scene *scene, char **data)
{
	(void)scene;
	(void)data;
}
