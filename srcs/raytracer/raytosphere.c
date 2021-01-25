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

int		sphereintersec(t_ray *ray, t_sphere *sphere, double *t1, double *t2)
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
		*t1 = INFINITY;
		*t2 = 1.0;
		return (0);
	}
	*t1 = (-b + sqrt(discriminant)) / (2 * a);
	*t2 = (-b - sqrt(discriminant)) / (2 * a);
	return (1);
}

int		raytosphere(t_ray *ray, t_scene *scene, t_rgb *obj_color)
{
	t_list			*sphere_list;
	t_sphere		*sphere;
	double			t1;
	double			t2;
	int				ray_t;

	sphere_list = scene->sphere;
	ray_t = -1;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		sphereintersec(ray, sphere, &t1, &t2);
		if (t1 > 1.0 && t1 < INFINITY)
		{
			ray_t = t1;
		    *obj_color = sphere->color;
		}
		if (t2 > 1.0 && t2 < INFINITY)   //trouver un moyen de de mettre ca dans la fonction au dessus
		{
			ray_t = t2;
		    *obj_color = sphere->color;
		}
		sphere_list = sphere_list->next;
	}
	if (ray_t == -1)
		return (0);
	return (1);
}
