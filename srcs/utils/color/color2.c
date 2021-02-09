/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:13:38 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 12:20:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_frgb	color_range1(t_rgb rgb)
{
	t_frgb	rgb1;

	rgb1.r = (float)rgb.r / 255;
	rgb1.g = (float)rgb.g / 255;
	rgb1.b = (float)rgb.b / 255;
	return (rgb1);
}

t_rgb	color_range2(t_frgb frgb)
{
	t_rgb	rgb1;

	rgb1.r = frgb.r * 255;
	if (rgb1.r > 255)
		rgb1.r = 255;
	rgb1.g = frgb.g * 255;
	if (rgb1.g > 255)
		rgb1.g = 255;
	rgb1.b = frgb.b * 255;
	if (rgb1.b > 255)
		rgb1.b = 255;
	return (rgb1);
}
