/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:44:51 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/02 17:28:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vector  vec_diff(t_vector v1, t_vector v2)
{
    t_vector    v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    v3.z = v1.z - v2.z;
    return (v3);
}

t_vector  vec_multipli_coeff(t_vector v1, double coeff)
{
    t_vector    v3;
   // printf("vector 1:\n x: %f\n y: %f\n z: %f\n", v1.x, v1.y, v1.z);
    v3.x = v1.x * coeff;
    //printf("printf y%f\n", v3.y = v1.y * coeff);
    v3.y = v1.y * coeff;
   // printf("v3.y%f\n", v3.y);
    v3.z = v1.z * coeff;
    return (v3);
}

t_vector  vec_add(t_vector v1, t_vector v2)
{    
    t_vector    v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return (v3);
}

t_vector   vec_div(t_vector v1, double nb)
{    
    t_vector    v3;
    v3.x = v1.x / nb;
    v3.y = v1.y / nb;
    v3.z = v1.z / nb;
    return (v3);
}

t_vector	normalize(t_ray	*ray, double ray_t, t_sphere *sphere)
{
	t_vector	normal;

	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	normal = vec_diff(ray_equation(ray, ray_t), sphere->cord);
    normal = vec_multipli_coeff(normal, 1.0 / vec_length(normal));
	return (normal);
}