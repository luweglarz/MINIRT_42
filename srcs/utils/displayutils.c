/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:20:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 17:39:08 by user42           ###   ########.fr       */
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

int color_to_int(t_rgb rgb)
{
    return(rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb   rgb_multipli(t_rgb color, double coeff)
{
    t_rgb    rgb;

    rgb.r = color.r * coeff;
    if (rgb.r > 255)
        rgb.r = 255;
    rgb.g = color.g * coeff;
    if (rgb.g > 255)
        rgb.g = 255;
    rgb.b = color.b * coeff;
    if (rgb.b > 255)
        rgb.b = 255;
    return (rgb);
}