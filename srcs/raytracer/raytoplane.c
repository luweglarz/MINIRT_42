/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytoplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 15:00:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	plane_intersec_equation(t_ray *ray, t_plane *plane)
{
	double a;

	a = vec_dot(ray->dir, plane->cord);
	
}

void	plane_intersec_color(t_plane *plane, t_ray *ray, t_scene *scene)
{
	double	t;
	
	t = plane_intersec_equation(ray, plane);

}

int		raytoplane(t_ray *ray, t_scene *scene)
{
	t_list			*plane_list;
	t_plane			*plane;

	plane_list = scene->sphere;
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