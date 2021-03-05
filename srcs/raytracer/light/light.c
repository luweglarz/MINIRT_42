/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/03/02 16:19:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	get_intensity(t_scene scene, t_vector light_dir, t_vector normal, t_light light)
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

int		is_intersection(t_scene scene, t_vector ray_pos, t_vector light_cord, void *obj)
{
	t_ray		ray;
	double		length;

	ray_init(&ray);
	ray.origin = ray_pos;
	ray.dir = light_cord;
//	ray.dir = normalize(ray.dir);
	length = vec_length(ray.dir);
	if (sphere_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (triangle_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (plane_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	if (square_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	return (0);
}

t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene, void *obj)
{
	double		intensity;
	t_rgb		light_color;
	t_list		*lights;
	t_light		*light;
	t_vector	light_dir;

	color_init(&light_color);
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		light_dir = vec_diff(light->cord, ray_pos);
		if (is_intersection(*scene, ray_pos, light_dir, obj))
		{
			color_init(&light_color);
			break;
		}
		light_dir = normalize(light_dir);
		intensity = get_intensity(*scene, light_dir, normal, *light);
		light_color = rgb_add(light_color,
		rgb_multipli(light->color, intensity));
		lights = lights->next;
	}
	light_color = rgb_add(light_color,
	rgb_multipli(scene->amli.color, scene->amli.ratio));
	return (color_range1(light_color));
}
