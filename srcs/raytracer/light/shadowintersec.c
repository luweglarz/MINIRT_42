/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowintersec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:19:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 18:30:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	sphere_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t_;
	t_list			*sphere_list;
	t_sphere		*sphere;

	sphere_list = scene.sphere;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		t_ = sphere_intersec_equation(ray, sphere);
		if (t_ > 0.00000001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = sphere;
		}
		sphere_list = sphere_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}

int	triangle_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t_;
	t_list			*triangle_list;
	t_triangle		*triangle;
	t_vector		normal;

	triangle_list = scene.triangle;
	while (triangle_list->next)
	{
		triangle = triangle_list->content;
		t_ = triangle_intersec_equation(ray, triangle, &normal);
		if (t_ > 0.00000001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = triangle;
		}
		triangle_list = triangle_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}

int	plane_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t_;
	t_list			*plane_list;
	t_plane			*plane;

	plane_list = scene.plane;
	while (plane_list->next)
	{
		plane = plane_list->content;
		t_ = plane_intersec_equation(ray, plane);
		if (t_ > 0.00000001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = plane;
		}
		plane_list = plane_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}

int	square_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t_;
	t_list			*square_list;
	t_square		*square;

	square_list = scene.square;
	while (square_list->next)
	{
		square = square_list->content;
		t_ = square_intersec_equation(ray, square);
		if (t_ > 0.00000001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = square;
		}
		square_list = square_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}

int	cylinder_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t_;
	t_list			*cylinder_list;
	t_cylinder		*cylinder;
	t_quadric		q;

	cylinder_list = scene.cylinder;
	while (cylinder_list->next)
	{
		cylinder = cylinder_list->content;
		t_ = cylinder_inter_equation(ray, cylinder, &q);
		if (t_ > 0.00000001 && t_ < length && t_ < ray->ray_t)
		{
			ray->ray_t = t_;
			ray->obj = cylinder;
		}
		cylinder_list = cylinder_list->next;
	}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}
