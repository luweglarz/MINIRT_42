/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:44:51 by lweglarz          #+#    #+#             */
/*   Updated: 2021/01/14 14:45:02 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void    my_pixel_put(t_img_data *data, int x, int y, t_rgb *rgb)
{
    char    *dst;
    int     offset = (y * data->line_length + x * 4);
    int     color;

    offset = (y * data->line_length + x * 4);
    dst = data->addr + offset;
    color = (rgb->r * 1000 + rgb->g) * 1000 + rgb->b;
    *(unsigned int*)dst = color;
}

double  vec_dot(t_vector *v1, t_vector *v2)
{
    return  v1->x * v2->x +  v1->y * v2->y + v1->z * v2->z;
}

t_vector  vec_diff(t_vector *v1, t_vector *v2)
{
    t_vector    v3;
    v3.x = v1->x - v2->x;
    v3.y = v1->y - v2->y;
    v3.z = v1->z - v2->z;
}