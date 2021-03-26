/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytotriangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:46:13 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 18:35:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	motrum_init(t_motrum *motrum)
{
	motrum->cross.x = 0;
	motrum->cross.y = 0;
	motrum->cross.z = 0;
	motrum->det = 0;
	motrum->inv_det = 0;
	motrum->ubary = 0;
	motrum->vbary = 0;
}

double	triangle_intersec_equation(t_ray *ray, t_triangle *triangle,
t_vector *normal)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	u;
	t_vector	v;
	t_motrum	motrum;

	motrum_init(&motrum);
	v1 = vec_diff(triangle->cord2, triangle->cord1);
	v2 = vec_diff(triangle->cord3, triangle->cord1);
	motrum.cross = cross_product(ray->dir, v2);
	motrum.det = vec_dot(motrum.cross, v1);
	if (motrum.det > -0.00000001 && motrum.det < 0.00000001)
		return (INFINITY);
	motrum.inv_det = 1.0 / motrum.det;
	u = vec_diff(ray->origin, triangle->cord1);
	motrum.ubary = vec_dot(u, motrum.cross) * motrum.inv_det;
	if (motrum.ubary < 0.0 || motrum.ubary > 1.0)
		return (INFINITY);
	v = cross_product(u, v1);
	motrum.vbary = vec_dot(ray->dir, v) * motrum.inv_det;
	if (motrum.vbary < 0.0 || motrum.vbary + motrum.ubary > 1.0)
		return (INFINITY);
	*normal = cross_product(v1, v2);
	return (vec_dot(v2, v) * motrum.inv_det);
}

void	triangle_intersec_color(t_triangle *triangle, t_ray *ray, t_scene scene)
{
	t_vector		ray_pos;
	t_vector		normal;
	double			t_;

	t_ = triangle_intersec_equation(ray, triangle, &normal);
	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = triangle;
		ray->ray_color = triangle->color;
		ray_pos = ray_equation(ray, ray->ray_t);
		normal = normalize(normal);
		if (vec_dot(ray->dir, normal) > 0)
			normal = vec_multipli_coeff(normal, -1);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene, ray->obj));
	}
}

void	raytotriangle(t_ray *ray, t_scene scene)
{
	t_list			*triangle_list;
	t_triangle		*triangle;

	triangle_list = scene.triangle;
	while (triangle_list->next)
	{
		triangle = triangle_list->content;
		triangle_intersec_color(triangle, ray, scene);
		triangle_list = triangle_list->next;
	}
}
