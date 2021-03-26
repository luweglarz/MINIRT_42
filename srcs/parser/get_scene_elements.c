/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/26 18:21:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_resolution(t_scene *scene, char **data)
{
	scene->reso.w = ft_atoi(data[1]);
	scene->reso.h = ft_atoi(data[2]);
	if (scene->reso.h <= 0 || scene->reso.w <= 0)
	{
		free_data(data);
		error(ERR_ELEMENT, scene);
	}
}

void	get_amlight(t_scene *scene, char **data)
{
	char	**rgb;
	t_amli	*amlight;

	if (!(amlight = malloc(sizeof(*amlight))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	rgb = ft_split(data[2], ',');
	scene->amli.color = get_color(rgb, scene, data, amlight);
	free_data(rgb);
	scene->amli.ratio = ft_atof(data[1]);
	free(amlight);
}

void	get_camera(t_scene *scene, char **data)
{
	t_camera	*new_cam;
	char		**cord;
	char		**ori;

	if (!(new_cam = malloc(sizeof(*new_cam))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	new_cam->cord = get_cord(cord);
	free_data(cord);
	new_cam->ori = get_orientation(ori, scene, data, new_cam);
	free_data(ori);
	new_cam->ori = normalize(new_cam->ori);
	new_cam->fov = ft_atoi(data[3]);
	if (new_cam->fov > 180 || new_cam->fov < 0)
	{
		free(new_cam);
		free_data(data);
		error(ERR_ELEMENT, scene);
	}
	ft_lstadd_front(&scene->camera, ft_lstnew(new_cam));
}

void	get_light(t_scene *scene, char **data)
{
	t_light		*new_light;
	char		**cord;
	char		**rgb;

	if (!(new_light = malloc(sizeof(*new_light))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_light->cord = get_cord(cord);
	free_data(cord);
	new_light->color = get_color(rgb, scene, data, new_light);
	free_data(rgb);
	new_light->ratio = ft_atof(data[2]);
	if (new_light->ratio < 0.0 || new_light->ratio > 1.0)
	{
		free(new_light);
		free_data(data);
		error(ERR_ELEMENT, scene);
	}
	ft_lstadd_front(&scene->light, ft_lstnew(new_light));
}
