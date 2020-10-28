/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 11:06:43 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_resolution(t_scene *scene, char **data)
{
	scene->resolution.h = ft_atoi(data[1]);
	scene->resolution.w = ft_atoi(data[2]);
	if (scene->resolution.h <= 0 || scene->resolution.w <= 0)
		write(2, "error", 5);
}

void	get_amlight(t_scene *scene, char **data)
{
	char	**rgb;
	t_amli	*amlight;

	if (!(amlight = malloc(sizeof(t_rgb))))
		write(2, "error", 5);
	rgb = ft_split(data[2], ',');
	amlight->color = *get_color(rgb);
	scene->amli.ratio = ft_atof(data[1]);
	scene->amli = *amlight;
}

void	get_camera(t_scene *scene, char **data)
{
	t_camera	*new_cam;
	char		**cordo;
	char		**ori;

	if (!(new_cam = malloc(sizeof(t_camera))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	new_cam->cordo.x = ft_atof(cordo[0]);
	new_cam->cordo.y = ft_atof(cordo[1]);
	new_cam->cordo.z = ft_atof(cordo[2]);
	new_cam->ori = *get_orientation(ori);
	new_cam->fov = ft_atoi(data[3]);
	ft_lstadd_front(&scene->camera, ft_lstnew(new_cam));
}

void	get_light(t_scene *scene, char **data)
{
	t_light		*new_light;
	char		**cordo;
	char		**rgb;

	if (!(new_light = malloc(sizeof(t_light))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_light->cordo.x = ft_atof(cordo[0]);
	new_light->cordo.y = ft_atof(cordo[1]);
	new_light->cordo.z = ft_atof(cordo[2]);
	new_light->color = *get_color(rgb);
	new_light->ratio = ft_atof(data[2]);
	ft_lstadd_front(&scene->light, ft_lstnew(new_light));
}
