/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytoplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 18:04:26 by user42           ###   ########.fr       */
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
//	printf("normal du plan \n x: %f\n y: %f\n z: %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	a = vec_dot(normal, ray->dir);
	//printf("a %f\n", a);
	if (a < 0)
		return (t);
	dist = vec_diff(plane->cord, ray->origin);
	t = vec_dot(dist, normal) / a;
	return (t);
}

void	plane_intersec_color(t_plane *plane, t_ray *ray, t_scene *scene)
{
	(void)scene;
	ray->ray_t = plane_intersec_equation(ray, plane);
	printf("ray_t %f\n", ray->ray_t);
	if (ray->ray_t < INFINITY && ray->ray_t > 0)
	{
		ray->ray_color = plane->color;
	
	}
}

int		raytoplane(t_ray *ray, t_scene *scene)
{
	t_list			*plane_list;
	t_plane			*plane;

	plane_list = scene->plane;
	ray->ray_t = INFINITY;
	while (plane_list->next)
	{
		plane = plane_list->content;
		plane_intersec_color(plane, ray, scene);
		plane_list = plane_list->next;
	}
	if (ray->ray_t == INFINITY)
		return (0);
	return (1);


}