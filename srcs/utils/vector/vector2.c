/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:15:55 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 17:28:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double  vec_dot(t_vector v1, t_vector v2)
{
    return (v1.x * v2.x +  v1.y * v2.y + v1.z * v2.z);
}

double      vec_length(t_vector v1)
{
    return (sqrt(vec_dot(v1, v1)));
}

t_vector	ray_equation(t_ray *ray, double ray_t)
{
	t_vector	equa_ray;

	//printf("ray:\n x: %f\n y: %f\n z: %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	//printf("ray_t : %f\n", ray_t);
	equa_ray = vec_add(ray->origin, vec_multipli_coeff(ray->dir, ray_t));
	//printf("equa_ray:\n x: %f\n y: %f\n z: %f\n", equa_ray.x, equa_ray.y, equa_ray.z);
	return (equa_ray);
}