/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/03/27 21:03:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	get_intensity(t_scene scene, t_vector light_dir, t_vector normal,
t_light light)
{
	double		intensity;
	double		cos;

	intensity = 0.0;
	intensity = scene.amli.ratio;
	cos = vec_dot(normal, light_dir);
	if (cos > 0)
		intensity += light.ratio * cos;
	return (intensity);
}

int		is_intersection(t_scene scene, t_vector ray_pos, t_vector light_cord,
void *obj)
{
	t_ray		ray;
	double		length;

	ray_init(&ray);
	ray.origin = ray_pos;
	ray.dir = vec_diff(light_cord, ray.origin);
	length = vec_length(normalize(ray.dir));
	if (sphere_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (triangle_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (plane_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (square_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (cylinder_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	return (0);
}

t_frgb	compute_light_other(t_ray ray, t_vector normal, t_scene scene,
void *obj)
{
	t_rgb		light_color;
	t_vector	light_dir;
	t_list		*lights;
	t_light		*light;

	color_init(&light_color);
	lights = scene.light;
	while (lights->next)
	{
		light = lights->content;
		light_dir = vec_diff(light->cord, ray.ray_n_t);
		if (is_intersection(scene, ray.ray_n_t, light->cord, obj) ||
		(vec_dot(normal, light_dir) < 0))
		{
			lights = lights->next;
			continue;
		}
		light_color = rgb_add(light_color,
		rgb_multipli(light->color,
		get_intensity(scene, normalize(light_dir), normal, *light)));
		lights = lights->next;
	}
	light_color = rgb_add(light_color,
	rgb_multipli(scene.amli.color, scene.amli.ratio));
	return (color_range1(light_color));
}

t_frgb	compute_light(t_ray ray, t_vector normal, t_scene scene,
void *obj)
{
	t_rgb		light_color;
	t_vector	light_dir;
	t_list		*lights;
	t_light		*light;

	color_init(&light_color);
	lights = scene.light;
	while (lights->next)
	{
		light = lights->content;
		light_dir = vec_diff(light->cord, ray.ray_n_t);
		if (is_intersection(scene, ray.ray_n_t, light->cord, obj) ||
		(vec_dot(normal, light_dir) < 0))
		{
			lights = lights->next;
			continue;
		}
		light_color = rgb_add(light_color,
		rgb_multipli(light->color,
		get_intensity(scene, normalize(light_dir), normal, *light)));
		lights = lights->next;
	}
	light_color = rgb_add(light_color,
	rgb_multipli(scene.amli.color, scene.amli.ratio));
	return (color_range1(light_color));
}
