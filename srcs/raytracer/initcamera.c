/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcamera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:32:24 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 19:02:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef	struct s_matrix
{
	double	m[4][4];
}				t_matrix;


t_vector		vector_matrix(t_vector v, t_matrix m)
{
	t_vector res;

	res.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	res.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	res.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	return (res);
}

t_matrix	look_at(t_vector origin, t_vector direction)
{
	t_matrix		m;
	t_vector		arbitrary;
	t_vector		right;
	t_vector		up;

	arbitrary.x = 0;
	arbitrary.y = 1.0;
	arbitrary.z = 0;
	right = cross_product(arbitrary, direction);
	up = cross_product(direction, right);
	m.m[0][0] = right.x;
	m.m[0][1] = right.y;
	m.m[0][2] = right.z;
	m.m[1][0] = up.x;
	m.m[1][1] = up.y;
	m.m[1][2] = up.z;
	m.m[2][0] = direction.x;
	m.m[2][1] = direction.y;
	m.m[2][2] = direction.z;
	m.m[3][0] = origin.x;
	m.m[3][1] = origin.y;
	m.m[3][2] = origin.z;
	return (m);
}

t_vector	
set_ray_dir(t_ray *ray, t_scene scene, t_camera camera, t_px px)
{
	double	 	aspect_ratio;
	double	 	fov;
	
	fov = tan((double)camera.fov / 2 * PI / 180);
	aspect_ratio = (double)scene.reso.w / (double)scene.reso.h;
	ray->dir.x = (2 * (px.x + 0.5) / (double)scene.reso.w - 1) * aspect_ratio * fov ;
	ray->dir.y = (1 - (2 * (px.y + 0.5) / scene.reso.h)) * fov;
	return (ray->dir);
}

void	init_camera(t_ray *ray, t_camera *camera, t_px px, t_scene *scene)
{
	t_matrix	matrix;

	matrix = look_at(camera->cord, camera->ori);
	ray->origin = vector_matrix(ray->origin, matrix);
	ray->dir = set_ray_dir(ray, *scene, *camera, px);
	ray->dir = vector_matrix(ray->dir, matrix);
	ray->dir = vec_diff(ray->dir, ray->origin);
	ray->dir = normalize(ray->dir);
}