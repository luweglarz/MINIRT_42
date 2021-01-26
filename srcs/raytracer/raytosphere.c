/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:48:11 by lweglarz          #+#    #+#             */
/*   Updated: 2021/01/19 15:48:14 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void		sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t)
{
	t_vector	dist;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	dist = vec_diff(&ray->origin, &sphere->cord);
	a = vec_dot(&ray->dir, &ray->dir);
	b = 2 * vec_dot(&ray->dir, &dist);
	c = vec_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	discriminant = (b * b) - 4 * (a * c);
	if (discriminant < 0)
	{
		t[0] = INFINITY;
		t[1] = 1.0;
		return ;
	}
	t[0] = (-b + sqrt(discriminant)) / (2 * a);
	t[1] = (-b - sqrt(discriminant)) / (2 * a);
}

void	sphere_intersec_color(double *t, double *ray_t, t_sphere *sphere, t_rgb *obj_color)
{
			if (t[0] > 1.0 && t[0] < INFINITY && t[0] < *ray_t)
		{
			*ray_t = t[0];
		    *obj_color = sphere->color;
		}
		if (t[1] > 1.0 && t[1] < INFINITY && t[1] < *ray_t)   //trouver un moyen de de mettre ca dans la fonction au dessus
		{
			*ray_t = t[1];
		    *obj_color = sphere->color;
		}
}

int		raytosphere(t_ray *ray, t_scene *scene, t_rgb *obj_color)
{
	t_list			*sphere_list;
	t_sphere		*sphere;
	double			t[2];
	double			ray_t;

	sphere_list = scene->sphere;
	ray_t = INFINITY;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		sphere_intersec_equation(ray, sphere, t);
		sphere_intersec_color(t, &ray_t,sphere, obj_color);
		sphere_list = sphere_list->next;
	}
	if (ray_t == INFINITY)
		return (0);
	return (1);
}
