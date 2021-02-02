/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 17:35:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double		compute_light(t_vector ray_equa, t_vector normal, t_scene *scene)
{
	double		intensity;
	double		normal_dot;
	t_vector	light_dir;
	t_list		*lights;
	t_light		*light;
	//printf("raydir: \n x: %f\ny: %f\nz: %f\n", ray_equa.x, ray_equa.y, ray_equa.z);
	intensity = 0.0;
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		intensity += scene->amli.ratio;
		light_dir = vec_diff(light->cord, ray_equa);
		//printf("light dir1 \n x: %f\ny: %f\nz: %f\n", light_dir.x, light_dir.y, light_dir.z);
		light_dir = vec_multipli_coeff(light_dir, 1.0 / vec_length(light_dir));
		//printf("light dir2 \n x: %f\ny: %f\nz: %f\n", light_dir.x, light_dir.y, light_dir.z);
		normal_dot = vec_dot(normal, light_dir);
		if (normal_dot > 0)
			intensity += light->ratio * normal_dot / (vec_length(normal) * vec_length(light_dir));
		lights = lights->next;
	}
	return (intensity);
}