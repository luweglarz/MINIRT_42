/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:20:22 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 14:31:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void    my_pixel_put(t_img_data *data, t_px px, t_rgb *rgb)
{
    char    *dst;
    int     offset;
    int     color;

    offset = (px.y * data->line_length + px.x * 4);
    dst = data->addr + offset;
    color = color_to_int(*rgb);
    *(unsigned int*)dst = color;
}
