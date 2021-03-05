/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:23:47 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 12:16:51 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_sphere(t_scene *scene, char **data)
{
	t_sphere	*new_sphere;
	char		**cord;
	char		**rgb;

	if (!(new_sphere = malloc(sizeof(t_sphere))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_sphere->cord = *get_cord(cord);
	new_sphere->color = *get_color(rgb);
	new_sphere->radius = ft_atof(data[2]);
	ft_lstadd_front(&scene->sphere, ft_lstnew(new_sphere));
}

void	get_square(t_scene *scene, char **data)
{
	t_square	*new_square;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_square = malloc(sizeof(t_square))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[4], ',');
	new_square->cord = *get_cord(cord);
	new_square->ori = *get_orientation(ori);
	new_square->ori = normalize(new_square->ori);
	new_square->color = *get_color(rgb);
	new_square->height = ft_atoi(data[3]);
	ft_lstadd_front(&scene->square, ft_lstnew(new_square));
}

void	get_cylinder(t_scene *scene, char **data)
{
	t_cylinder	*new_cylinder;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_cylinder = malloc(sizeof(t_cylinder))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[5], ',');
	new_cylinder->cord = *get_cord(cord);
	new_cylinder->ori = *get_orientation(ori);
	new_cylinder->color = *get_color(rgb);
	new_cylinder->diameter = ft_atoi(data[3]);
	new_cylinder->height = ft_atoi(data[4]);
	ft_lstadd_front(&scene->cylinder, ft_lstnew(new_cylinder));
}

void	get_triangle(t_scene *scene, char **data)
{
	t_triangle	*new_triangle;
	char		**cord1;
	char		**cord2;
	char		**cord3;
	char		**rgb;

	if (!(new_triangle = malloc(sizeof(t_triangle))))
		error(ERR_MALLOC);
	cord1 = ft_split(data[1], ',');
	cord2 = ft_split(data[2], ',');
	cord3 = ft_split(data[3], ',');
	rgb = ft_split(data[4], ',');
	new_triangle->cord1 = *get_cord(cord1);
	new_triangle->cord2 = *get_cord(cord2);
	new_triangle->cord3 = *get_cord(cord3);
	new_triangle->color = *get_color(rgb);
	ft_lstadd_front(&scene->triangle, ft_lstnew(new_triangle));
}

void	get_plane(t_scene *scene, char **data)
{
	t_plane		*new_plane;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_plane = malloc(sizeof(t_plane))))
		error(ERR_MALLOC);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	new_plane->cord = *get_cord(cord);
	new_plane->ori = *get_orientation(ori);
	new_plane->ori = normalize(new_plane->ori);
	new_plane->color = *get_color(rgb);
	ft_lstadd_front(&scene->plane, ft_lstnew(new_plane));
}
