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

t_frgb   color_range1(t_rgb rgb)
{
    t_frgb   rgb1;
    //printf("entrer\n r: %d\n g: %d\n, b; %d\n", rgb.r, rgb.g, rgb.b);
    rgb1.r = (float)rgb.r / 255;
    rgb1.g = (float)rgb.g / 255;
    rgb1.b = (float)rgb.b / 255;
    //printf("sortie\n r: %f\n g: %f\n, b; %f\n", rgb1.r, rgb1.g, rgb1.b);
    return (rgb1);
}

t_rgb   color_range2(t_frgb frgb)
{
    t_rgb   rgb1;

    rgb1.r = frgb.r * 255;
    rgb1.g = frgb.g * 255;
    rgb1.b = frgb.b * 255;
    return (rgb1);
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