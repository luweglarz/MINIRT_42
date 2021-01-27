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
    int     offset;
    int     color;

    offset = (y * data->line_length + x * 4);
    dst = data->addr + offset;
    color = (rgb->r << 16 | rgb->g << 8 | rgb->b);
   *(unsigned int*)dst = color;
}

double  vec_dot(t_vector v1, t_vector v2)
{
    return (v1.x * v2.x +  v1.y * v2.y + v1.z * v2.z);
}

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
    v3.x = v1.x * coeff;
    v3.y = v1.y * coeff;
    v3.z = v1.z * coeff;
    return (v3);
}

void   rgb_multipli(t_rgb *color, double coeff)
{
    //t_rgb    rgb;
   // rgb.r = color.r * coeff;
   // rgb.g = color.g * coeff;
   // rgb.b = color.b * coeff;
   color->r *= coeff;
   color->g *= coeff;
   color->b *= coeff;
}

t_vector  vec_add(t_vector v1, t_vector v2)
{    
    t_vector    v3;
    v3.x = v1.x + v2.x;
    v3.x = v1.y + v2.y;
    v3.x = v1.y + v2.y;
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

double      vec_length(t_vector v1)
{
    double  power;
    power = pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2);
    return (sqrt(power));
}