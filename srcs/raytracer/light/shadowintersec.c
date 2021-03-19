/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowintersec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:19:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/11 13:45:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	sphere_intersec(t_scene scene, t_ray *ray)
{
	double			t[2];
	double			t_;
	t_list			*sphere_list;
	t_sphere		*sphere;

	sphere_list = scene.sphere;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		t_ = sphere_intersec_equation(ray, sphere, t);
		if (t_ > 0.0001 && t_ < 1.0 && t_ < ray->ray_t)
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

int	triangle_intersec(t_scene scene, t_ray *ray)
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
		if (t_ > 0.0001 && t_ < 1 && t_ < ray->ray_t)
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

int	plane_intersec(t_scene scene, t_ray *ray)
{
	double			t_;
	t_list			*plane_list;
	t_plane			*plane;

	plane_list = scene.plane;
	while (plane_list->next)
	{
		plane = plane_list->content;
		t_ = plane_intersec_equation(ray, plane);
		if (t_ > 0.0001 && t_ < 1 && t_ < ray->ray_t)
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

int	square_intersec(t_scene scene, t_ray *ray)
{
	double			t_;
	t_list			*square_list;
	t_square		*square;

	square_list = scene.square;
	//printf("ray_pos\n x: %f\n y: %f\n z: %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	//printf("ray_origin\n x: %f\n y: %f\n z: %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
	while (square_list->next)
	{
		square = square_list->content;
		t_ = square_intersec_equation(ray, square);
		//if (t_ != INFINITY)
		//printf("t %f\n", t_);
		if (t_ > 0.0001 && t_ < 1 && t_ < ray->ray_t)
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