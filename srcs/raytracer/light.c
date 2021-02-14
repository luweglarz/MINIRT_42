/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 20:36:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_intensity(t_vector ray_pos, t_vector normal, t_light light)
{
	double		intensity;
	double		cos;
	t_vector	light_dir;

	intensity = 0.0;
	light_dir = vec_diff(light.cord, ray_pos);
	light_dir = normalize(light_dir);
	cos = vec_dot(normal, light_dir);
	if (cos > 0)
		intensity += light.ratio * cos;
	//specular lighting a faire
	return (intensity);
}

t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene)
{
	double		intensity;
	t_rgb		light_color;
	t_list		*lights;
	t_light		*light;

	intensity = 0.0;
	light_color.r = 0;
	light_color.g = 0;
	light_color.b = 0;
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		intensity = scene->amli.ratio;
		intensity = get_intensity(ray_pos, normal, *light);
		light_color = rgb_add(light_color,
		rgb_multipli(light->color, intensity));
		lights = lights->next;
	}
	light_color = rgb_add(light_color,
	rgb_multipli(scene->amli.color, scene->amli.ratio));
	return (color_range1(light_color));
}
