/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:26 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/23 15:17:10 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_resolution(t_scene *scene, char **data)
{
	scene->resolution.h = ft_atoi(data[1]);
	scene->resolution.w = ft_atoi(data[2]);
	printf("RESOLUTION\n");
	printf("res height : %d\n", scene->resolution.h);
	printf("res width : %d\n", scene->resolution.w);
}

void	get_amlight(t_scene *scene, char **data)
{
	char	**rgb;

	rgb = ft_split(data[2], ',');
	scene->amli.ratio = ft_atof(data[1]);
	scene->amli.color.r = ft_atoi(rgb[0]);
	scene->amli.color.g = ft_atoi(rgb[1]);
	scene->amli.color.b = ft_atoi(rgb[2]);
	printf("AMLIGHT\n");
	printf("rgb r : %d\n", scene->amli.color.r);
	printf("rgb g : %d\n", scene->amli.color.g);
	printf("rgb b : %d\n", scene->amli.color.b);
	printf("ratio : %f\n", scene->amli.ratio);
}

void	get_camera(t_scene *scene, char **data)
{
	t_camera	*new_cam;
	char	**cordo;
	char	**ori;

	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	if (!(new_cam = malloc(sizeof(t_camera))))
		write(2, "error", 5);
	new_cam->cordo.x = ft_atof(cordo[0]);
	new_cam->cordo.y = ft_atof(cordo[1]);
	new_cam->cordo.z = ft_atof(cordo[2]);
	new_cam->ori.x = ft_atof(ori[0]);
	new_cam->ori.y = ft_atof(ori[0]);
	new_cam->ori.z = ft_atof(ori[0]);
	new_cam->fov = ft_atoi(data[3]);
	printf("CAMERA\n");
	printf("cordo x : %f\n", new_cam->cordo.x);
	printf("cordo y : %f\n", new_cam->cordo.y);
	printf("cordo z : %f\n", new_cam->cordo.z);
	ft_lstadd_front(&scene->camera, ft_lstnew(new_cam));
}

void	get_light(t_scene *scene, char **data)
{
	(void)scene;
	(void)data;
}
