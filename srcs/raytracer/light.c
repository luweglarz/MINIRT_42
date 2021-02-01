/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 18:14:25 by user42           ###   ########.fr       */
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

	intensity = 0.0;
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		intensity += scene->amli.ratio;
		lights = lights->next;
	}
	return (intensity);
}