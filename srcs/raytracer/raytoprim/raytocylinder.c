/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytocylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/03/23 16:44:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	cylinder_intersec_equation(t_ray *ray, t_cylinder *cylinder, double *t)
{
	t_vector	dist;
	dist = vec_diff(ray->origin, cylinder->cord);
	double	r = cylinder->diameter / 2;
	double a = vec_dot(ray->dir, ray->dir) - vec_dot(ray->dir, cylinder->ori) * 2;
	double b = (vec_dot(ray->dir, dist) - (vec_dot(ray->dir, cylinder->ori) * vec_dot(dist, cylinder->ori))) * 2;
	double c = vec_dot(dist, dist) - (vec_dot(dist, cylinder->ori) * 2) - r * r;
	double 	discriminant = (b * b) - 4 * (a * c);
		if (discriminant < 0)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (INFINITY);
	}
	t[0] = (-b + sqrt(discriminant)) / (2 * a);
	t[1] = (-b - sqrt(discriminant)) / (2 * a);
	double m[2];
	m[0] = vec_dot(ray->dir, cylinder->ori) * t[0] + vec_dot(dist, cylinder->ori);
	m[1] = vec_dot(ray->dir, cylinder->ori) * t[1] + vec_dot(dist, cylinder->ori);
	if (m[0] >= 0 && m[0] <= cylinder->height)
		return (t[0]);
	else if (m[1] >= 0 && m[1] <= cylinder->height)
	return(t[1]);
	return (INFINITY);
}

void	cylinder_intersec_color(t_cylinder *cylinder, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;
	double			t_;
	double			t[2];
	t_ = cylinder_intersec_equation(ray, cylinder, t);

	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = cylinder;
		ray->ray_color = cylinder->color;
		(void)ray_pos;
		(void)scene;
		(void)normal;
		//ray->ray_color = color_multipli(color_range1(ray->ray_color),
		//compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytocylinder(t_ray *ray, t_scene *scene)
{
	t_list			*cylinder_list;
	t_cylinder			*cylinder;


	cylinder_list = scene->cylinder;
	while (cylinder_list->next)
	{
		cylinder = cylinder_list->content;
		cylinder_intersec_color(cylinder, ray, scene);
		cylinder_list = cylinder_list->next;
	}
}
