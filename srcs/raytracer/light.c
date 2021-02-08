/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/05 16:45:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_intensity(t_scene scene, t_vector ray_pos, t_vector normal, t_light light)
{
	double		intensity;
	double		cos;
	t_vector	light_dir;

	intensity = 0.0;
	intensity += scene.amli.ratio;
	light_dir = normalize(light.cord, ray_pos);
	cos = vec_dot(normal, light_dir);
	if (cos > 0)
		intensity += light.ratio * cos;
	return (intensity);
}

t_frgb		compute_light(t_vector ray_pos, t_vector normal, t_scene *scene)
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
		intensity += get_intensity(*scene, ray_pos, normal, *light);
		light_color = rgb_add(light_color, rgb_multipli(light->color,intensity)); // la premiere lumiere prend tout 
		lights = lights->next;
	}
	light_color = rgb_add(light_color, rgb_multipli(scene->amli.color, scene->amli.ratio));  // il ne faut pas add mais multiplier 
	return (color_range1(light_color));
}
