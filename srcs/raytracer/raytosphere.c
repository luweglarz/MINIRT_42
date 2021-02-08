/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:48:11 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/04 17:29:03 by user42           ###   ########.fr       */
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

t_rgb	color_multipli(t_frgb frgb1, t_frgb frgb2)
{
	t_frgb	frgb3;

	frgb3.r = frgb1.r * frgb2.r;
	frgb3.g = frgb1.g * frgb2.g;
	frgb3.b = frgb1.b * frgb2.b;
	//printf("frgb1\n r: %f\n g: %f\n, b; %f\n", frgb1.r, frgb1.g, frgb1.b);
	//printf("frgb2\n r: %f\n g: %f\n, b; %f\n", frgb2.r, frgb2.g, frgb2.b);
	return (color_range2(frgb3));
}

void	sphere_intersec_color(t_sphere *sphere, t_ray *ray, t_scene *scene)
{
	double			t[2];
	t_vector		ray_pos;
	t_vector		normal;

	sphere_intersec_equation(ray, sphere, t);
	if (t[0] > 1.0 && t[0] < INFINITY && t[0] < ray->ray_t)
	{
		ray->ray_t = t[0];
		ray->ray_color = sphere->color;
		ray_pos = ray_equation(ray, ray->ray_t);
		normal = normalize(ray_equation(ray, ray->ray_t), sphere->cord);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene));
	}
	if (t[1] > 1.0 && t[1] < INFINITY && t[1] < ray->ray_t)
	{
		ray->ray_t = t[1];
		ray->ray_color = sphere->color;
		ray_pos = ray_equation(ray, ray->ray_t);
		normal = normalize(ray_equation(ray, ray->ray_t), sphere->cord);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene));
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
