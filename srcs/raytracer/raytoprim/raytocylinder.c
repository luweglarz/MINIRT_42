/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytocylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/03/23 16:44:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	cylinder_res(t_quadric *q, double m_, double t)
{
	q->m_ = m_;
	return (t);
}

double	
cylinder_intersec_equation(t_ray *ray, t_cylinder *cylinder, t_quadric *q)
{
	t_vector	dist;
	double		t[2];
	double		m[2];
	double		r;

//printf("notmal \n x: %f\n y: %f\n z: %f\n", cylinder->cord.x, cylinder->cord.y, cylinder->cord.z);
	dist = vec_diff(ray->origin, cylinder->cord);
	r = cylinder->diameter / 2;
	q->a = vec_dot(ray->dir, ray->dir) - vec_dot(ray->dir, cylinder->ori) * vec_dot(ray->dir, cylinder->ori);
	q->b = 2 * (vec_dot(ray->dir, dist) - (vec_dot(ray->dir, cylinder->ori) *
	vec_dot(dist, cylinder->ori)));
	q->c = vec_dot(dist, dist) - (vec_dot(dist, cylinder->ori) * vec_dot(dist, cylinder->ori)) - r * r;
	q->discriminant = (q->b * q->b) - 4 * (q->a * q->c);
	if (q->discriminant < 0)
		return (INFINITY);
	t[0] = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
	t[1] = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
	m[0] = vec_dot(ray->dir, cylinder->ori) *
	t[0] + vec_dot(dist, cylinder->ori);
	m[1] = vec_dot(ray->dir, cylinder->ori) *
	t[1] + vec_dot(dist, cylinder->ori);
	if (m[0] >= 0 && m[0] <= cylinder->height)
		return (cylinder_res(q, m[0], t[0]));
	if (m[1] >= 0 && m[1] <= cylinder->height)
		return (cylinder_res(q, m[1], t[1]));
	return (INFINITY);
}

void	cylinder_intersec_color(t_cylinder *cylinder, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;
	double			t_;
	t_quadric		q;

	t_ = cylinder_intersec_equation(ray, cylinder, &q);
	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = cylinder;
		ray->ray_color = cylinder->color;
		ray_pos = ray_equation(ray,	ray->ray_t);
		normal = vec_diff(ray_pos, cylinder->cord);
		normal = vec_diff(normal, vec_multipli_coeff(cylinder->ori, q.m_));
		normal= normalize(normal);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytocylinder(t_ray *ray, t_scene *scene)
{
	t_list			*cylinder_list;
	t_cylinder		*cylinder;


	cylinder_list = scene->cylinder;
	while (cylinder_list->next)
	{
		cylinder = cylinder_list->content;
		cylinder_intersec_color(cylinder, ray, scene);
		cylinder_list = cylinder_list->next;
	}
}
