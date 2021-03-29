/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:23:47 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/25 23:08:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_sphere(t_scene *scene, char **data)
{
	t_sphere	*new_sphere;
	char		**cord;
	char		**rgb;

	if (!(new_sphere = malloc(sizeof(*new_sphere))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_sphere->cord = get_cord(cord, scene, data, new_sphere);
	new_sphere->color = get_color(rgb, scene, data, new_sphere);
	new_sphere->radius = ft_atof(data[2]);
	ft_lstadd_front(&scene->sphere, ft_lstnew(new_sphere));
}

void	get_square(t_scene *scene, char **data)
{
	t_square	*new_square;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_square = malloc(sizeof(*new_square))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[4], ',');
	new_square->cord = get_cord(cord, scene, data, new_square);
	new_square->ori = get_orientation(ori, scene, data, new_square);
	new_square->ori = normalize(new_square->ori);
	new_square->color = get_color(rgb, scene, data, new_square);
	new_square->height = ft_atoi(data[3]);
	ft_lstadd_front(&scene->square, ft_lstnew(new_square));
}

void	get_cylinder(t_scene *scene, char **data)
{
	t_cylinder	*new_cylinder;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_cylinder = malloc(sizeof(*new_cylinder))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[5], ',');
	new_cylinder->cord = get_cord(cord, scene, data, new_cylinder);
	new_cylinder->ori = get_orientation(ori, scene, data, new_cylinder);
	new_cylinder->ori = normalize(new_cylinder->ori);
	new_cylinder->color = get_color(rgb, scene, data, new_cylinder);
	new_cylinder->diameter = ft_atof(data[3]);
	new_cylinder->height = ft_atof(data[4]);
	ft_lstadd_front(&scene->cylinder, ft_lstnew(new_cylinder));
}

void	get_triangle(t_scene *scene, char **data)
{
	t_triangle	*new_triangle;
	char		**cord1;
	char		**cord2;
	char		**cord3;
	char		**rgb;

	if (!(new_triangle = malloc(sizeof(*new_triangle))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord1 = ft_split(data[1], ',');
	cord2 = ft_split(data[2], ',');
	cord3 = ft_split(data[3], ',');
	rgb = ft_split(data[4], ',');
	new_triangle->cord1 = get_cord(cord1, scene, data, new_triangle);
	new_triangle->cord2 = get_cord(cord2, scene, data, new_triangle);
	new_triangle->cord3 = get_cord(cord3, scene, data, new_triangle);
	new_triangle->color = get_color(rgb, scene, data, new_triangle);
	ft_lstadd_front(&scene->triangle, ft_lstnew(new_triangle));
}

void	get_plane(t_scene *scene, char **data)
{
	t_plane		*new_plane;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_plane = malloc(sizeof(*new_plane))))
	{
		free_data(data);
		error(ERR_MALLOC, scene);
	}
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	new_plane->cord = get_cord(cord, scene, data, new_plane);
	new_plane->ori = get_orientation(ori, scene, data, new_plane);
	new_plane->ori = normalize(new_plane->ori);
	new_plane->color = get_color(rgb, scene, data, new_plane);
	ft_lstadd_front(&scene->plane, ft_lstnew(new_plane));
}
