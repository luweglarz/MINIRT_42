/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 11:50:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double		compute_light(t_vector ray_equa, t_vector normal, t_scene *scene)
{
	double		intensity;
	double		cos;
	t_vector	light_dir;
	t_list		*lights;
	t_light		*light;

	intensity = 0.0;
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		intensity += scene->amli.ratio;
		light_dir = normalize(light->cord, ray_equa);
		cos = vec_dot(normal, light_dir);
		if (cos > 0)
			intensity += light->ratio * cos /
			(vec_length(normal) * vec_length(light_dir));
		lights = lights->next;
	}
	return (intensity);
}
