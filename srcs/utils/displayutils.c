/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:20:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 19:47:41 by user42           ###   ########.fr       */
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
    *(unsigned int*)dst = *rgb;
}

int color_to_int(t_rgb rgb)
{
    return(rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb   rgb_multipli(t_rgb color, double coeff)
{
    t_rgb    rgb;

    rgb.r = color.r * coeff;
    rgb.g = color.g * coeff;
    rgb.b = color.b * coeff;
    return (rgb);
}