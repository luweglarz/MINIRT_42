/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytotriangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:46:13 by user42            #+#    #+#             */
/*   Updated: 2021/02/24 22:07:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	triangle_intersec_equation(t_ray *ray, t_triangle *triangle)
{
	(void)ray;
	(void)triangle;
	return 1;
}

void	triangle_intersec_color(t_triangle *triangle, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;

	ray->ray_t_temp = triangle_intersec_equation(ray, triangle);
	if (ray->ray_t_temp < INFINITY && ray->ray_t_temp > 0 && ray->ray_t_temp < ray->ray_t)
	{
		ray->ray_t = ray->ray_t_temp;
		ray->obj = triangle;
		ray->ray_color = triangle->color;
		(void)ray_pos;
		(void)scene;
		(void)normal;
	//	ray->ray_color = color_multipli(color_range1(ray->ray_color),
	//	compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytotriangle(t_ray *ray, t_scene *scene)
{
	t_list			*triangle_list;
	t_triangle		*triangle;


	triangle_list = scene->triangle;
	while (triangle_list->next)
	{
		triangle = triangle_list->content;
		triangle_intersec_color(triangle, ray, scene);
		triangle_list = triangle_list->next;
	}
}