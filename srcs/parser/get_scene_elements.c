/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/04 17:24:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_resolution(t_scene *scene, char **data)
{
	scene->reso.w = ft_atoi(data[1]);
	scene->reso.h = ft_atoi(data[2]);
	if (scene->reso.h <= 0 || scene->reso.w <= 0)
		error(ERR_ELEMENT);
}

void	get_amlight(t_scene *scene, char **data)
{
	char	**rgb;
	t_amli	*amlight;

	if (!(amlight = malloc(sizeof(t_amli))))
		error(ERR_MALLOC);
	rgb = ft_split(data[2], ',');
	amlight->color = *get_color(rgb);
	scene->amli.ratio = ft_atof(data[1]);
}

void	get_camera(t_scene *scene, char **data)
{
	t_camera	*new_cam;
	char		**cord;
	char		**ori;

	if (!(new_cam = malloc(sizeof(t_camera))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	new_cam->cord = *get_cord(cord);
	new_cam->ori = *get_orientation(ori);
	new_cam->fov = ft_atoi(data[3]);
	ft_lstadd_front(&scene->camera, ft_lstnew(new_cam));
}

void	get_light(t_scene *scene, char **data)
{
	t_light		*new_light;
	char		**cord;
	char		**rgb;

	if (!(new_light = malloc(sizeof(t_light))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_light->cord = *get_cord(cord);
	new_light->color = *get_color(rgb);
	new_light->ratio = ft_atof(data[2]);
	if (new_light->ratio < 0.0 || new_light->ratio > 1.0)
		error(ERR_ELEMENT);
	ft_lstadd_front(&scene->light, ft_lstnew(new_light));
}
