/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:48:11 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/04 16:59:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t)
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
		return ;
	}
	t[0] = (-b + sqrt(discriminant)) / (2 * a);
	t[1] = (-b - sqrt(discriminant)) / (2 * a);
}

void	sphere_intersec_color(t_sphere *sphere, t_ray *ray, t_scene *scene)
{
	double			t[2];

	sphere_intersec_equation(ray, sphere, t);
	if (t[0] > 1.0 && t[0] < INFINITY && t[0] < ray->ray_t)
	{
		ray->ray_t = t[0];
		ray->ray_color = sphere->color;
		ray->ray_color = rgb_multipli(ray->ray_color,
			compute_light(ray_equation(ray, ray->ray_t),
			normalize(ray_equation(ray, ray->ray_t), sphere->cord), scene));
	}
	if (t[1] > 1.0 && t[1] < INFINITY && t[1] < ray->ray_t)
	{
		ray->ray_t = t[1];
		ray->ray_color = sphere->color;
		ray->ray_color = rgb_multipli(ray->ray_color,
			compute_light(ray_equation(ray, ray->ray_t),
			normalize(ray_equation(ray, ray->ray_t), sphere->cord), scene));
	}
}

int		raytosphere(t_ray *ray, t_scene *scene)
{
	t_list			*sphere_list;
	t_sphere		*sphere;

	sphere_list = scene->sphere;
	ray->ray_t = INFINITY;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		sphere_intersec_color(sphere, ray, scene);
		sphere_list = sphere_list->next;
	}
	if (ray->ray_t == INFINITY)
		return (0);
	return (1);
}
