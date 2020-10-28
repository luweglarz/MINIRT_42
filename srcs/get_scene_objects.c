/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:23:47 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 11:26:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_sphere(t_scene *scene, char **data)
{
	t_sphere	*new_sphere;
	char		**cord;
	char		**rgb;

	if (!(new_sphere = malloc(sizeof(t_sphere))))
		write(2, "error", 5);
	cord = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_sphere->cord.x = ft_atof(cord[0]);
	new_sphere->cord.y = ft_atof(cord[1]);
	new_sphere->cord.z = ft_atof(cord[2]);
	new_sphere->color = *get_color(rgb);
	new_sphere->diameter = ft_atof(data[2]);
	ft_lstadd_front(&scene->sphere, ft_lstnew(new_sphere));
}

void	get_square(t_scene *scene, char **data)
{
	t_square	*new_square;
	char		**cord;
	char		**ori;
	char		**rgb;

	if (!(new_square = malloc(sizeof(t_square))))
		write(2, "error", 5);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[4], ',');
	new_square->cord.x = ft_atof(cord[0]);
	new_square->cord.y = ft_atof(cord[1]);
	new_square->cord.z = ft_atof(cord[2]);
	new_square->ori = *get_orientation(ori);
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
		write(2, "error", 5);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[5], ',');
	new_cylinder->cord.x = ft_atof(cord[0]);
	new_cylinder->cord.y = ft_atof(cord[1]);
	new_cylinder->cord.z = ft_atof(cord[2]);
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
		write(2, "error", 5);
	cord1 = ft_split(data[1], ',');
	cord2 = ft_split(data[2], ',');
	cord3 = ft_split(data[3], ',');
	rgb = ft_split(data[4], ',');
	new_triangle->cord1.x = ft_atof(cord1[0]);
	new_triangle->cord1.y = ft_atof(cord1[1]);
	new_triangle->cord1.z = ft_atof(cord1[2]);
	new_triangle->cord2.x = ft_atof(cord2[0]);
	new_triangle->cord2.y = ft_atof(cord2[1]);
	new_triangle->cord2.z = ft_atof(cord2[2]);
	new_triangle->cord3.x = ft_atof(cord3[0]);
	new_triangle->cord3.y = ft_atof(cord3[1]);
	new_triangle->cord3.z = ft_atof(cord3[2]);
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
		write(2, "error", 5);
	cord = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	new_plane->cord.x = ft_atof(cord[0]);
	new_plane->cord.y = ft_atof(cord[1]);
	new_plane->cord.z = ft_atof(cord[2]);
	new_plane->ori = *get_orientation(ori);
	new_plane->color = *get_color(rgb);
	ft_lstadd_front(&scene->plane, ft_lstnew(new_plane));
}
