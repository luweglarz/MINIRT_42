/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:48:11 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/26 22:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t)
{
	t_vector	dist;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	dist = vec_diff(ray->origin, sphere->cord);
	a = vec_dot(ray->dir, ray->dir);
	b = 2 * vec_dot(ray->dir, dist);
	c = vec_dot(dist, dist) - (sphere->radius * sphere->radius);
	discriminant = (b * b) - 4 * (a * c);
	if (discriminant < 0)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (INFINITY);
	}

	t[0] = (-b + sqrt(discriminant)) / (2 * a);
	t[1] = (-b - sqrt(discriminant)) / (2 * a);
	if (t[0] < t[1])
		return (t[0]);
	if (t[0] > t[1])
		return (t[1]);
	return (INFINITY);
}

void	sphere_intersec_color(t_sphere *sphere, t_ray *ray, t_scene *scene)
{
	double			t[2];
	double			t_;
	t_vector		ray_pos;
	t_vector		normal;

	t_ = sphere_intersec_equation(ray, sphere, t);
	if (t_ > 1.0 && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = sphere;
		ray->ray_color = sphere->color;
		ray_pos = ray_equation(ray,	ray->ray_t);
		normal = vec_diff(ray_pos, sphere->cord);
		normal = normalize(normal);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene, ray->obj));
	}
}

void		raytosphere(t_ray *ray, t_scene *scene)
{
	t_list			*sphere_list;
	t_sphere		*sphere;

	sphere_list = scene->sphere;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		sphere_intersec_color(sphere, ray, scene);
		sphere_list = sphere_list->next;
	}

}
