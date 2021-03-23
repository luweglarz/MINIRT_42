/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:15:55 by user42            #+#    #+#             */
/*   Updated: 2021/03/23 11:46:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double		vec_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		vec_length(t_vector v1)
{
	return (sqrt(vec_dot(v1, v1)));
}

t_vector		vector_matrix(t_vector v, t_matrix m)
{
	t_vector res;

	res.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	res.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	res.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	return (res);
}

t_vector	ray_equation(t_ray *ray, double ray_t)
{
	t_vector	equa_ray;

	equa_ray = vec_add(ray->origin, vec_multipli_coeff(ray->dir, ray_t));
	return (equa_ray);
}


t_vector	normalize(t_vector vec)
{
	t_vector	normal;

	normal = vec_multipli_coeff(vec, 1.0 / vec_length(vec));
	return (normal);
}



