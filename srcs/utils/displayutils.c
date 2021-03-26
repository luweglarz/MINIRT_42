/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:20:22 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 18:53:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ray_init(t_ray *ray)
{
	ray->origin.x = 0.0;
	ray->origin.y = 0.0;
	ray->origin.z = 0.0;
	ray->dir.x = 0.0;
	ray->dir.y = 0.0;
	ray->dir.z = 1.0;
	ray->ray_t = INFINITY;
	color_init(&ray->ray_color);
	ray->obj = NULL;
}

void	my_pixel_put(t_img_data *data, t_px px, t_rgb *rgb)
{
	char	*dst;
	int		offset;
	int		color;

	offset = (px.y * data->line_length + px.x * 4);
	dst = data->addr + offset;
	color = color_to_int(*rgb);
	*(unsigned int*)dst = color;
}
