/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:23:47 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/26 15:08:08 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	get_sphere(t_scene *scene, char **data)
{
	t_sphere	*new_sphere;
	char		**cordo;
	char		**rgb;

	if (!(new_sphere = malloc(sizeof(t_sphere))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	new_sphere->cordo.x = ft_atof(cordo[0]);
	new_sphere->cordo.y = ft_atof(cordo[1]);
	new_sphere->cordo.z = ft_atof(cordo[2]);
	new_sphere->color.r = ft_atoi(rgb[0]);
	new_sphere->color.g = ft_atoi(rgb[1]);
	new_sphere->color.b = ft_atoi(rgb[2]);
	new_sphere->diameter = ft_atof(data[2]);
	ft_lstadd_front(&scene->sphere, ft_lstnew(new_sphere));
}

void	get_square(t_scene *scene, char **data)
{
	t_square	*new_square;
	char		**cordo;
	char		**ori;
	char		**rgb;

	if (!(new_square = malloc(sizeof(t_square))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[4], ',');
	new_square->cordo.x = ft_atof(cordo[0]);
	new_square->cordo.y = ft_atof(cordo[1]);
	new_square->cordo.z = ft_atof(cordo[2]);
	new_square->ori.x = ft_atof(ori[0]);
	new_square->ori.y = ft_atof(ori[1]);
	new_square->ori.z = ft_atof(ori[2]);
	new_square->color.r = ft_atoi(rgb[0]);
	new_square->color.g = ft_atoi(rgb[1]);
	new_square->color.b = ft_atoi(rgb[2]);
	new_square->height = ft_atoi(data[3]);
	ft_lstadd_front(&scene->square, ft_lstnew(new_square));
}

void	get_cylinder(t_scene *scene, char **data)
{
	t_cylinder	*new_cylinder;
	char		**cordo;
	char		**ori;
	char		**rgb;

	if (!(new_cylinder = malloc(sizeof(t_cylinder))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[5], ',');
	new_cylinder->cordo.x = ft_atof(cordo[0]);
	new_cylinder->cordo.y = ft_atof(cordo[1]);
	new_cylinder->cordo.z = ft_atof(cordo[2]);
	new_cylinder->ori.x = ft_atof(ori[0]);
	new_cylinder->ori.y = ft_atof(ori[1]);
	new_cylinder->ori.z = ft_atof(ori[2]);
	new_cylinder->color.r = ft_atoi(rgb[0]);
	new_cylinder->color.g = ft_atoi(rgb[1]);
	new_cylinder->color.b = ft_atoi(rgb[2]);
	new_cylinder->diameter = ft_atoi(data[3]);
	new_cylinder->height = ft_atoi(data[4]);
	ft_lstadd_front(&scene->cylinder, ft_lstnew(new_cylinder));
}

void	get_triangle(t_scene *scene, char **data)
{
	t_triangle	*new_triangle;
	char		**cordo1;
	char		**cordo2;
	char		**cordo3;
	char		**rgb;

	if (!(new_triangle = malloc(sizeof(t_triangle))))
		write(2, "error", 5);
	cordo1 = ft_split(data[1], ',');
	cordo2 = ft_split(data[2], ',');
	cordo3 = ft_split(data[3], ',');
	rgb = ft_split(data[4], ',');
	new_triangle->cordo1.x = ft_atof(cordo1[0]);
	new_triangle->cordo1.y = ft_atof(cordo1[1]);
	new_triangle->cordo1.z = ft_atof(cordo1[2]);
	new_triangle->cordo2.x = ft_atof(cordo2[0]);
	new_triangle->cordo2.y = ft_atof(cordo2[1]);
	new_triangle->cordo2.z = ft_atof(cordo2[2]);
	new_triangle->cordo3.x = ft_atof(cordo3[0]);
	new_triangle->cordo3.y = ft_atof(cordo3[1]);
	new_triangle->cordo3.z = ft_atof(cordo3[2]);
	new_triangle->color.r = ft_atof(rgb[0]);
	new_triangle->color.g = ft_atof(rgb[1]);
	new_triangle->color.b = ft_atof(rgb[2]);
	ft_lstadd_front(&scene->triangle, ft_lstnew(new_triangle));
}

void	get_plane(t_scene *scene, char **data)
{
	t_plane		*new_plane;
	char		**cordo;
	char		*ori;
	char		**rgb;

	if (!(new_plane = malloc(sizeof(t_plane))))
		write(2, "error", 5);
	cordo = ft_split(data[1], ',');
	ori = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	new_plane->cordo.x = ft_atof(cordo[0]);
	new_plane->cordo.y = ft_atof(cordo[1]);
	new_plane->cordo.z = ft_atof(cordo[2]);
	new_plane->ori.x = ft_atof(ori[0]);
	new_plane->ori.y = ft_atof(ori[1]);
	new_plane->ori.z = ft_atof(ori[2]);
	new_plane->color.r = ft_atoi(rgb[0]);
	new_plane->color.g = ft_atoi(rgb[1]);
	new_plane->color.b = ft_atoi(rgb[2]);
	ft_lstadd_front(&scene->plane, ft_lstnew(new_plane));
}
