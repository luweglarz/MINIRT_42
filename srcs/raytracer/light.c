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

double		compute_light(t_vector ray_pos, t_vector normal, t_scene *scene)
{
	double		intensity;
	t_list		*lights;
	t_light		*light;

	intensity = 0.0;
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		intensity = get_intensity(*scene, ray_pos, normal, *light);
		lights = lights->next;
	}
	return (intensity);
}
