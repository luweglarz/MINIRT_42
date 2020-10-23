/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/23 11:06:42 by lweglarz         ###   ########.fr       */
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
	char	**rgb;

	rgb = ft_split(data[2], ',');
	scene->amli.ratio = ft_atof(data[1]);
	scene->amli.color.r = ft_atoi(rgb[0]);
	scene->amli.color.g = ft_atoi(rgb[1]);
	scene->amli.color.b = ft_atoi(rgb[2]);
}

void	get_camera(t_scene *scene, char **data)
{
	char	**cordo;
	char	**ori;

	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	scene->camera->cordo.x = ft_atof(cordo[0]);
	scene->camera->cordo.y = ft_atof(cordo[1]);
	scene->camera->cordo.z = ft_atof(cordo[2]);
	scene->camera->ori.x = ft_atof(ori[0]);
	scene->camera->ori.y = ft_atof(ori[0]);
	scene->camera->ori.z = ft_atof(ori[0]);
	scene->camera->fov = ft_atoi(data[3]);
	printf("%f\n");
}

void	get_light(t_scene *scene, char **data)
{
	(void)scene;
	(void)data;
}
