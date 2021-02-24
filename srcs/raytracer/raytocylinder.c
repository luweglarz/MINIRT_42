/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytocylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/02/24 22:10:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	cylinder_intersec_equation(t_ray *ray, t_cylinder *cylinder)
{
	(void)ray;
	(void)cylinder;
	return 1;
}

void	cylinder_intersec_color(t_cylinder *cylinder, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;

	ray->ray_t_temp = cylinder_intersec_equation(ray, cylinder);
	if (ray->ray_t_temp < INFINITY && ray->ray_t_temp > 0 && ray->ray_t_temp < ray->ray_t)
	{
		ray->ray_t = ray->ray_t_temp;
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
