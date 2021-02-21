/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytoplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 22:44:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	plane_intersec_equation(t_ray *ray, t_plane *plane)
{
	double 	 a;
	double 	 t;
	t_vector	normal;
	t_vector	dist;

	t = INFINITY;
	normal = normalize(plane->ori);
	a = vec_dot(normal, ray->dir);
	if (a < 0)
		return (t);
	dist = vec_diff(plane->cord, ray->origin);
	t = vec_dot(dist, normal) / a;
	return (t);
}

void	plane_intersec_color(t_plane *plane, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;

	ray->ray_t_temp = plane_intersec_equation(ray, plane);
	if (ray->ray_t_temp < INFINITY && ray->ray_t_temp > 0 && ray->ray_t_temp < ray->ray_t)
	{
		ray->ray_t = ray->ray_t_temp;
		ray->obj = plane;
		ray->ray_color = plane->color;
		ray_pos = ray_equation(ray, ray->ray_t);
		normal = vec_diff(ray_pos, plane->cord);
		normal = normalize(normal);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytoplane(t_ray *ray, t_scene *scene)
{
	t_list			*plane_list;
	t_plane			*plane;


	plane_list = scene->plane;
	while (plane_list->next)
	{
		plane = plane_list->content;
		plane_intersec_color(plane, ray, scene);
		plane_list = plane_list->next;
	}
}